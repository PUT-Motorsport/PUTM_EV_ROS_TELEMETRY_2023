#include "Prometheus.hpp"

using namespace Data;


void Apps::Update_metrics(PUTM_CAN::Apps_main apps_frame)
{
    Counter.Set(apps_frame.counter);
    Difference.Set(apps_frame.position_diff);
    Pedal_Position.Set(apps_frame.pedal_position);
    std::cout << int(apps_frame.counter) << std::endl;
    Update_State(this, uint8_t(apps_frame.device_state));
}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_acceleration aq_acc_frame)
{



}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_gyroscope aq_gyro_frame)
{



}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_main aq_main_frame)
{

    

}

void Bms_Lv::Update_metrics(PUTM_CAN::BMS_LV_main bmslv_frame)
{

    

}

void Bms_Lv::Update_metrics(PUTM_CAN::BMS_LV_temperature bmslv_tmp_frame)
{

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Acc_time laptimer_acc_frame)
{

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Lap_time laptimer_lap_frame)
{

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Sector laptimer_sec_frame)
{

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Skidpad_time laptimer_skid_frame)
{

    

}


void Fuse::Update_metrics(PUTM_CAN::SF_main sfmain_frame)
{

    

}

void Traction_Control::Update_metrics(PUTM_CAN::TC_imu_acc tc_imu_acc_frame)
{

    

}

void Traction_Control::Update_metrics(PUTM_CAN::TC_imu_gyro tc_imu_gyro_frame)
{

    

}

void Traction_Control::Update_metrics(PUTM_CAN::TC_main tc_main_frame)
{

    

}

// void Traction_Control::Update_metrics(PUTM_CAN::TC_main tc_main_frame)
// {

    

// }

void Traction_Control::Update_metrics(PUTM_CAN::TC_temperatures tc_temperatures_frame)
{

    

}

void Traction_Control::Update_metrics(PUTM_CAN::TC_wheel_velocities tc_wheels_frames)
{

    

}










