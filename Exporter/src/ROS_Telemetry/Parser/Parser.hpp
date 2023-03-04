#pragma once

#include <thread>
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
    std::vector<can_frame> frame_buffer;
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
    void Receive();
    void Parser();
};
}