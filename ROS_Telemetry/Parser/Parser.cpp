#include "Parser.hpp"
#include "../Prometheus/Prometheus.hpp"

Data::Apps *apps = new Data::Apps();
Data::AQ_Card *aq = new Data::AQ_Card();
Data::Bms_Lv *lv = new Data::Bms_Lv();
Data::Bms_Hv *hv = new Data::Bms_Hv();
Data::Traction_Control *tc = new Data::Traction_Control();
Data::Time *times = new Data::Time();
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
            PUTM_CAN::AQ_acceleration aqacctmp;
            memcpy(&aqacctmp, &frtmp.data, sizeof(frtmp.data));
            aq->Update_metrics(aqacctmp);
        }
        break;

        case PUTM_CAN::AQ_GYROSCOPE_CAN_ID:
        {

        }
        break;
        
        case PUTM_CAN::AQ_MAIN_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::AQ_TS_BUTTON_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::BMS_LV_MAIN_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::BMS_LV_TEMPERATURE_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::DASH_MAIN_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::DV_ASS_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::LAP_TIMER_ACC_TIME_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::LAP_TIMER_LAP_TIME_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::LAP_TIMER_MAIN_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::LAP_TIMER_SECTOR_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::LAP_TIMER_SKIDPAD_TIME_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::SF_MAIN_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::SF_SAFETY_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::TC_IMU_ACC_CAN_ID:
        {

        }
        break;

        case PUTM_CAN::TC_IMU_GYRO_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::TC_MAIN_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::TC_REAR_SUSPENSION_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::TC_TEMPERATURES_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::TC_WHEEL_VELOCITIES_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::WHEELTEMP_MAIN_CAN_ID:
        {

        }
        break;


        case PUTM_CAN::YAWPROBE_AIR_FLOW_CAN_ID:
        {

        }
        break;
    }
    }
}
}