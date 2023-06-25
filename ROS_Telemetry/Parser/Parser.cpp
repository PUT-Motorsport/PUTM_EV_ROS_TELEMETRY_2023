#include "Parser.hpp"
#include "../Prometheus/Prometheus.hpp"
#include <chrono>
#include <thread>
#include <iostream>

Data::Apps *apps = new Data::Apps();
Data::AQ_Card *aq = new Data::AQ_Card();
Data::Bms_Lv *lv = new Data::Bms_Lv();
Data::Bms_Hv *hv = new Data::Bms_Hv();
Data::Traction_Control *tc = new Data::Traction_Control();
Data::Time *times = new Data::Time();
Data::Fuse *fuse = new Data::Fuse();
Data::WheelTemperatureSensor *wheeltmpSensor = new Data::WheelTemperatureSensor();

namespace Parser{

void Run()
{
    CAN_Parser parsing_handler;
    parsing_handler.Start();
    if(parsing_handler.state == CAN_Parser::ERROR) {return;}
    while(true)
    {
        parsing_handler.Push();
<<<<<<< HEAD
=======
        //std::cout << parsing_handler.frame_buffer.size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
>>>>>>> eb2d080f82b3a1b016f55872a3a4c6bf8777e632
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
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
        
<<<<<<< HEAD
    while(frame_buffer.size() == 0) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
=======
    while(frame_buffer.size() == 0) {}
>>>>>>> eb2d080f82b3a1b016f55872a3a4c6bf8777e632
    
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
            PUTM_CAN::AQ_gyroscope aqgytmp;
            memcpy(&aqgytmp, &frtmp.data, sizeof(frtmp.data));
            aq->Update_metrics(aqgytmp);
        }
        break;
        
        case PUTM_CAN::AQ_MAIN_CAN_ID:
        {
            PUTM_CAN::AQ_main aqtmp;
            memcpy(&aqtmp, &frtmp.data, sizeof(frtmp.data));
            aq->Update_metrics(aqtmp);
        }
        break;

        case PUTM_CAN::AQ_TS_BUTTON_CAN_ID:
        {
            PUTM_CAN::AQ_main aqtmp;
            memcpy(&aqtmp, &frtmp.data, sizeof(frtmp.data));
            aq->Update_metrics(aqtmp);
        }
        break;

        case PUTM_CAN::BMS_LV_MAIN_CAN_ID:
        {
            PUTM_CAN::BMS_LV_main bmslv;
            memcpy(&bmslv, &frtmp.data, sizeof(frtmp.data));
            lv->Update_metrics(bmslv);
        }
        break;

        case PUTM_CAN::BMS_LV_TEMPERATURE_CAN_ID:
        {
            PUTM_CAN::BMS_LV_temperature bmslvtemps;
            memcpy(&bmslvtemps, &frtmp.data, sizeof(frtmp.data));
            lv->Update_metrics(bmslvtemps);
        }
        break;

        case PUTM_CAN::BMS_HV_MAIN_CAN_ID:
        {
            PUTM_CAN::BMS_HV_main bmshvmain;
            memcpy(&bmshvmain, &frtmp.data, sizeof(frtmp.data));
            hv->Update_metrics(bmshvmain); 
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
            PUTM_CAN::Lap_timer_Acc_time laptimeracc;
            memcpy(&laptimeracc, &frtmp.data, sizeof(frtmp.data));
            times->Update_metrics(laptimeracc);
            ROS_INFO("Acceleration");
        }
        break;

        case PUTM_CAN::LAP_TIMER_LAP_TIME_CAN_ID:
        {
            PUTM_CAN::Lap_timer_Lap_time laptimerlap;
            memcpy(&laptimerlap, &frtmp.data, sizeof(frtmp.data));
            times->Update_metrics(laptimerlap);
        }
        break;

        case PUTM_CAN::LAP_TIMER_MAIN_CAN_ID:
        {
            PUTM_CAN::Lap_timer_Main laptimermain;
            memcpy(&laptimermain, &frtmp.data, sizeof(frtmp.data));
            times->Update_metrics(laptimermain);
        }
        break;

        case PUTM_CAN::LAP_TIMER_SECTOR_CAN_ID:
        {
            PUTM_CAN::Lap_timer_Lap_time laptimersec;
            memcpy(&laptimersec, &frtmp.data, sizeof(frtmp.data));
            times->Update_metrics(laptimersec);
        }
        break;

        case PUTM_CAN::LAP_TIMER_SKIDPAD_TIME_CAN_ID:
        {
            PUTM_CAN::Lap_timer_Lap_time laptimerskid;
            memcpy(&laptimerskid, &frtmp.data, sizeof(frtmp.data));
            times->Update_metrics(laptimerskid);
        }
        break;

        case PUTM_CAN::SF_MAIN_CAN_ID:
        {
            PUTM_CAN::SF_main sfmain;
            memcpy(&sfmain, &frtmp.data, sizeof(frtmp.data));
            fuse->Update_metrics(sfmain);
        }
        break;

        case PUTM_CAN::SF_SAFETY_CAN_ID:
        {
            PUTM_CAN::SF_safety sfsafety;
            memcpy(&sfsafety, &frtmp.data, sizeof(frtmp.data));
            fuse->Update_metrics(sfsafety);
        }
        break;

        case PUTM_CAN::TC_IMU_ACC_CAN_ID:
        {
            PUTM_CAN::TC_imu_acc tc_imu_acc;
            memcpy(&tc_imu_acc, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_imu_acc);
        }
        break;

        case PUTM_CAN::TC_IMU_GYRO_CAN_ID:
        {
            PUTM_CAN::TC_imu_gyro tc_imu_gyro;
            memcpy(&tc_imu_gyro, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_imu_gyro);
        }
        break;


        case PUTM_CAN::TC_MAIN_CAN_ID:
        {
            PUTM_CAN::TC_main tc_main;
            memcpy(&tc_main, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_main);
            if(tc_main.tractive_system_on == true)
            {
                int a = 10;            


            }
        }
        break;


        case PUTM_CAN::TC_REAR_SUSPENSION_CAN_ID:
        {
            PUTM_CAN::TC_rear_suspension tc_rear;
            memcpy(&tc_rear, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_rear);
        }
        break;


        case PUTM_CAN::TC_TEMPERATURES_CAN_ID:
        {
            PUTM_CAN::TC_temperatures tc_temperatures;
            memcpy(&tc_temperatures, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_temperatures);
        }
        break;


        case PUTM_CAN::TC_WHEEL_VELOCITIES_CAN_ID:
        {
            PUTM_CAN::TC_wheel_velocities tc_wheels;
            memcpy(&tc_wheels, &frtmp.data, sizeof(frtmp.data));
            tc->Update_metrics(tc_wheels);
        }
        break;


        case PUTM_CAN::WHEELTEMP_MAIN_CAN_ID:
        {
            PUTM_CAN::WheelTemp_main wheel_tmp_main;
            memcpy(&wheel_tmp_main, &frtmp.data, sizeof(frtmp.data));
            wheeltmpSensor->Update_metrics(wheel_tmp_main);
        }
        break;


        case PUTM_CAN::YAWPROBE_AIR_FLOW_CAN_ID:
        {
            PUTM_CAN::YawProbe_air_flow yawprobe;
            memcpy(&yawprobe, &frtmp.data, sizeof(frtmp.data));
            // tc->Update_metrics(tc_wheels);
        }
        break;
        case PUTM_CAN::STEERING_WHEEL_EVENT_CAN_ID:
        {
            PUTM_CAN::Steering_Wheel_event event;
            int a = 10;
        }
    }
    }
}
}