#include "Prometheus.hpp"
#include "Communication.hpp"
#include "../Parser/Parser.hpp"
#include <iostream>
#include <string> 

using namespace Data;

extern Communication::RosComs rosDataHandler;

void Apps::Update_metrics(PUTM_CAN::Apps_main apps_frame)
{
    //Prometheus
    Counter.Set(apps_frame.counter);
    Difference.Set(apps_frame.position_diff);
    Pedal_Position.Set(apps_frame.pedal_position);
    std::cout << int(apps_frame.counter) << std::endl;
    Update_State(this, uint8_t(apps_frame.device_state));
    //ROS
    rosDataHandler.appsROS.pedalPosition = apps_frame.pedal_position;
    rosDataHandler.appsROS.difference = apps_frame.position_diff;
    rosDataHandler.appsPublisher.publish(rosDataHandler.appsROS);
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
    //Check_SC(this, uint8_t(aq_main_frame.safety_front));
}

void Bms_Lv::Update_metrics(PUTM_CAN::BMS_LV_main bmslv_frame)
{
    Voltage    .Set(static_cast<float>(bmslv_frame.voltage_sum)/100);
    SoC        .Set(bmslv_frame.soc);
    Temperature.Set(bmslv_frame.temp_avg);
    Current    .Set(bmslv_frame.current);
    Update_State(this, uint8_t(bmslv_frame.device_state));
}

void Bms_Lv::Update_metrics(PUTM_CAN::BMS_LV_temperature bmslv_tmp_frame)
{
    cell_1_temp.Set(bmslv_tmp_frame.temp_1);
    cell_2_temp.Set(bmslv_tmp_frame.temp_2);
    cell_3_temp.Set(bmslv_tmp_frame.temp_3);
    cell_4_temp.Set(bmslv_tmp_frame.temp_4);
    cell_5_temp.Set(bmslv_tmp_frame.temp_5);
    cell_6_temp.Set(bmslv_tmp_frame.temp_6);
    cell_7_temp.Set(bmslv_tmp_frame.temp_7);
    cell_8_temp.Set(bmslv_tmp_frame.temp_8);
}

void Bms_Hv::Update_metrics(PUTM_CAN::BMS_HV_main bmshv_main_frame)
{
    Voltage        .Set(bmshv_main_frame.voltage_sum);
    Current        .Set(bmshv_main_frame.current);
    SoC            .Set(bmshv_main_frame.soc);
    Temperature_max.Set(bmshv_main_frame.temp_max);
    Temperature_avg.Set(bmshv_main_frame.temp_avg);
    Update_State(this, uint8_t(bmshv_main_frame.device_state));
}


void Time::Update_metrics(PUTM_CAN::Lap_timer_Acc_time laptimer_acc_frame)
{
    Acc_time.Set(laptimer_acc_frame.Acc_Time);

    uint8_t seconds  = (laptimer_acc_frame.Acc_Time/1000);
    uint32_t miliseconds = laptimer_acc_frame.Acc_Time - seconds*1000;
    std::string message = "Lap time: " + std::to_string(seconds) + ":" + std::to_string(miliseconds);
    logger.Push_Debug(&this->device_logger, device_name, message);
    Update_State(this, uint8_t(laptimer_acc_frame.device_state));
}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Lap_time laptimer_lap_frame)
{
    Lap_Time.Set(laptimer_lap_frame.Lap_time);

    uint8_t minutes = laptimer_lap_frame.Lap_time/60000;
    uint8_t seconds  = (laptimer_lap_frame.Lap_time/1000) - minutes*60;
    uint32_t miliseconds = laptimer_lap_frame.Lap_time - seconds*1000;

    std::string message = "Lap time: " + std::to_string(minutes) + ":" + std::to_string(seconds) + ":" + std::to_string(miliseconds);
    logger.Push_Debug(&this->device_logger, device_name, message);
    Update_State(this, uint8_t(laptimer_lap_frame.device_state));
}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Sector laptimer_sec_frame)
{

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Skidpad_time laptimer_skid_frame)
{
    

    

}

void Time::Update_metrics(PUTM_CAN::Lap_timer_Main laptimer_main_frame)
{
    Update_State(this, uint8_t(laptimer_main_frame.device_state));
}


void Fuse::Update_metrics(PUTM_CAN::SF_main sfmain_frame)
{

    

}

void Fuse::Update_metrics(PUTM_CAN::SF_safety sf_safety)
{
    //Check_SC(this, uint8_t(sf_safety));
}


void Traction_Control::Update_metrics(PUTM_CAN::TC_imu_acc tc_imu_acc_frame)
{
    acc_x.Set(tc_imu_acc_frame.acc_x);
    acc_y.Set(tc_imu_acc_frame.acc_y);
    acc_z.Set(tc_imu_acc_frame.acc_z);
}

void Traction_Control::Update_metrics(PUTM_CAN::TC_imu_gyro tc_imu_gyro_frame)
{
    gyro_x.Set(tc_imu_gyro_frame.gyro_x);
    gyro_y.Set(tc_imu_gyro_frame.gyro_y);
    gyro_z.Set(tc_imu_gyro_frame.gyro_z);
}

void Traction_Control::Update_metrics(PUTM_CAN::TC_rear_suspension tc_rear_suspension)
{
    suspension_rear_left .Set(tc_rear_suspension.adc_susp_left);  
    suspension_rear_right.Set(tc_rear_suspension.adc_susp_right);  
}

void Traction_Control::Update_metrics(PUTM_CAN::TC_main tc_main_frame)
{
    vehicle_speed.Set(tc_main_frame.vehicle_speed);
    motor_current.Set(tc_main_frame.motor_current);
    motor_speed  .Set(tc_main_frame.engine_speed);
    tc_intensity .Set(tc_main_frame.traction_control_intensivity);
}

void Traction_Control::Update_metrics(PUTM_CAN::TC_temperatures tc_temperatures_frame)
{
    temp_engine   .Set(tc_temperatures_frame.engine);   
    temp_inverter .Set(tc_temperatures_frame.inverter);   
    water_p_in    .Set(tc_temperatures_frame.water_pressure_in);   
    water_p_out   .Set(tc_temperatures_frame.water_pressure_out);   
    temp_water_in .Set(tc_temperatures_frame.water_temp_in);   
    temp_water_out.Set(tc_temperatures_frame.water_temp_out);  
}

void Traction_Control::Update_metrics(PUTM_CAN::TC_wheel_velocities tc_wheels_frames)
{
    wheel_front_left .Set(tc_wheels_frames.left_front);
    wheel_front_right.Set(tc_wheels_frames.right_front);
    wheel_rear_left  .Set(tc_wheels_frames.left_rear);
    wheel_rear_right .Set(tc_wheels_frames.right_rear);
}










