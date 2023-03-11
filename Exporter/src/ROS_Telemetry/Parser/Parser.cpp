#include "Parser.hpp"
#include "../Prometheus/Prometheus.hpp"

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
    parsing_handler.Start();
    if(parsing_handler.state == CAN_Parser::ERROR) {return;}
    while(true)
    {
        parsing_handler.Push();
    }
}

void CAN_Parser::Start()
{
    rec = new std::thread(&CAN_Parser::Parser, this);
}

void CAN_Parser::Parser()
{
    while(true)
    {
    while(frame_buffer.size() == 0);
    
    can_frame frtmp = Pop();
    switch(frtmp.can_id)
    {
        case PUTM_CAN::APPS_MAIN_CAN_ID:
        {
            PUTM_CAN::Apps_main appstmp;
            memcpy(&appstmp, &frtmp.data, sizeof(frtmp.data));
            apps->Update_metrics(appstmp);
        }
        break;

        case PUTM_CAN::AQ_ACCELERATION_CAN_ID:
        {

        }
        break;
    }
    }
}
}