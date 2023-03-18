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
    acc_x.Set(aq_acc_frame.acc_x);
    acc_y.Set(aq_acc_frame.acc_y);
    acc_z.Set(aq_acc_frame.acc_z);
}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_gyroscope aq_gyro_frame)
{
   speed_x.Set(aq_gyro_frame.speed_x);
   speed_y.Set(aq_gyro_frame.speed_y);
   speed_z.Set(aq_gyro_frame.speed_z);
}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_main aq_main_frame)
{
    Susp_front_right    .Set(aq_main_frame.suspension_right);
    Susp_front_left     .Set(aq_main_frame.suspension_left);
    brake_pressure_front.Set(aq_main_frame.brake_pressure_front);
    brake_pressure_rear .Set(aq_main_frame.brake_pressure_back);
    Update_State(this, uint8_t(aq_main_frame.device_state));
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










