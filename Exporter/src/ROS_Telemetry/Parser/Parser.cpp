#include "Parser.hpp"
#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/SC.tpp"
#include "../Loki/Loki.hpp"

Data::Apps *apps = new Data::Apps();
Data::AQ_Card *aq = new Data::AQ_Card();
Data::Bms_Lv *lv = new Data::Bms_Lv();
Data::Bms_Hv *hv = new Data::Bms_Hv();
Data::Traction_Control *tc = new Data::Traction_Control();
Data::Temperatures *temps = new Data::Temperatures();
Data::Time *times = new Data::Time();
Data::Shutdown_Circut_front *fsh = new Data::Shutdown_Circut_front();
Data::Shutdown_Circut_rear *rsh = new Data::Shutdown_Circut_rear();

namespace Parser{

void Run()
{
    CAN_Parser parsing_handler;
    if(parsing_handler.state == CAN_Parser::ERROR) {return;}
    while(true)
    {
        parsing_handler.Receive();
    }
}

void CAN_Parser::Receive()
{
    can_frame fr1;
    can.structure_receive_random(fr1);
    frame_buffer.push_back(fr1);
}

void CAN_Parser::Parser()
{
    std::lock_guard<std::mutex> guard(buffer_mutex);
    while(frame_buffer.size() == 0);

    auto frtmp = frame_buffer.back();
    frame_buffer.pop_back();
    buffer_mutex.unlock();

    switch(frtmp.can_id)
    {
        case PUTM_CAN::APPS_MAIN_CAN_ID:
        {
            
        }
        break;

        case PUTM_CAN::AQ_ACCELERATION_CAN_ID:
        {

        }
        break;
    }
}
}