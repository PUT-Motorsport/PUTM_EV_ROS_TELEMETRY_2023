#pragma once

#include <thread>
#include <queue>
#include <ros/ros.h>
#include "../PUTM_DV_CAN_LIBRARY/Inc/putm_can_interface.hpp"

namespace Parser{

void Run();

class CAN_Parser{

    private:
    //wątek wykonujący funkcje parser.
    std::thread *rec;
    //Can handler
    PUTM_CAN::CAN can;
    //buffer for frames
    std::queue<can_frame> frame_buffer;
    //mutex
    std::mutex frame_buffer_mutex;
    public:

    enum STATE{
        OK,
        ERROR
    }state;
    
    CAN_Parser(){
        if(can.connect() != PUTM_CAN::CanState::CAN_OK)
        {
            ROS_ERROR("Error while connecting to CAN socket");
            state = ERROR;
        }
        else
        {
            ROS_INFO("Connected to CAN socket");
            state = OK;
        }
    }
    //parser ze switch case. pobiera ramkę z bufora i updateuje metryki.
    void Start();

    void inline Push()
    {
        can_frame fr1;
        can.structure_receive_random(fr1, PUTM_CAN::NO_TIMEOUT);
        std::lock_guard<std::mutex> guard(frame_buffer_mutex);
        frame_buffer.push(fr1);
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