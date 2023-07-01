#pragma once
#include <thread>
#include <queue>
#include <ros/ros.h>
#include "../PUTM_DV_CAN_LIBRARY_MULTIPLE_SOCKETS/include/can_rx.hpp"
#include "../PUTM_DV_CAN_LIBRARY_MULTIPLE_SOCKETS/include/can_tx.hpp"



namespace Parser{

void Run();

class CAN_Parser{

    private:
    //wątek wykonujący funkcje parser.
    std::thread *rec;
    //Can handler
    PUTM_CAN::CanRx<can_frame> received_frame;
    //buffer for frames
    //std::queue<can_frame> frame_buffer;
    //mutex
    std::mutex frame_buffer_mutex;

    public:
    std::queue<can_frame> frame_buffer;
    enum STATE{
        OK,
        ERROR
    }state;
    
    CAN_Parser()
    try : received_frame("can0", PUTM_CAN::NO_TIMEOUT)
    {
        ROS_INFO("[TELEMETRY] Connected to CAN socket");
    }
    catch(std::runtime_error &err){
        ROS_ERROR("[TELEMETRY] Error while connecting to CAN socket");
        std::cout << err.what() << '\n';
    }

    void Start();

    void inline Push()
    {
        try
        {
            can_frame random_device_data = received_frame.receive();
            std::lock_guard<std::mutex> guard(frame_buffer_mutex);
            frame_buffer.push(random_device_data);
        }
        catch(std::runtime_error &err){
            ROS_ERROR("[TELEMETRY] Error while receiving CAN Frame");
             std::cout << err.what() << '\n';
        }
    }
    can_frame inline Pop()
    {
        std::lock_guard<std::mutex> guard(frame_buffer_mutex);
        auto frtmp = frame_buffer.front();
        frame_buffer.pop();
        return frtmp;
    }
    
    void Parser();
};
}