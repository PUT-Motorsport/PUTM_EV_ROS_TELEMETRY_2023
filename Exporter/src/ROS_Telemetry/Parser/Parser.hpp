#pragma once

#include <thread>
#include <queue>
#include <ros/ros.h>
#include "putm_can_interface.hpp"

namespace Parser{

void Run();

class CAN_Parser{

    private:
    //wątek wykonujący funkcje parser.
    std::thread *rec;
    //mutex
    std::mutex buffer_mutex;
    //Can handler
    PUTM_CAN::CAN can;
    //buffer for frames
    std::queue<can_frame> frame_buffer;
    public:

    enum STATE{
        OK,
        ERROR
    }state;

    CAN_Parser(){
        if(can.connect() != 0)
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
        can.structure_receive_random(fr1);
        std::lock_guard<std::mutex> guard(buffer_mutex);
        frame_buffer.push(fr1);
    }
    can_frame inline Pop()
    {
        auto frtmp = frame_buffer.front();
        frame_buffer.pop();
        buffer_mutex.unlock();
        return frtmp;
    }
    
    void Parser();
};
}