#pragma once

#include<algorithm>
#include <array>
#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <thread>
#include <iostream>
#include <vector>
#include <iterator>

#include "prometheus/client_metric.h"
#include "prometheus/counter.h"
#include "prometheus/exposer.h"
#include "prometheus/family.h"
#include "prometheus/registry.h"
#include "../Loki/Loki.hpp"

#include "../PUTM_DV_CAN_LIBRARY/Inc/putm_can_interface.hpp"

using namespace prometheus;

extern std::shared_ptr<prometheus::Registry> registry_prometheus;
extern Tlogs logger;

namespace Data
{

class Apps{
    private:

    Family<Gauge> &APPS1 = {BuildGauge()
                        .Name("APPS")
                        .Help("--")
                        .Register(*registry_prometheus)};

    //Order here matters. Gauges should be defined in opposite order, than in msg file.
    Gauge &Counter        = {APPS1.Add({{"Apps",       "Counter"}})};
    Gauge &Difference     = {APPS1.Add({{"Apps",    "Difference"}})};
    Gauge &Pedal_Position = {APPS1.Add({{"Apps","Pedal Position"}})};

    public:

    std::string device_name = "Apps";
    AgentJson &device_logger = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};
    int current_state = -1;

    std::vector<std::string> ok_states {
            "Normal Operation",
            "Power Up"};

    std::vector<std::string> warning_states {};

    std::vector<std::string> error_states {
            "Sensor Implausiblity",
            "Left sensor out of range - lower bound",
            "Left sensor out of range - upper bound",
            "Right sensor out of range - lower bound",
            "Right sensor out of range - upper bound"};

    void Update_metrics(PUTM_CAN::Apps_main);
};

class Bms_Lv{
    
    private:

    Family<Gauge> &fam = {BuildGauge()
                        .Name("BMS_LV")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage     = {fam.Add({{"BMS_LV","Voltage"}})};
    Gauge& SoC         = {fam.Add({{"BMS_LV","SoC"}})};
    Gauge& Temperature = {fam.Add({{"BMS_LV","Temperature"}})};
    Gauge& Current     = {fam.Add({{"BMS_LV","Current"}})};
    Gauge& cell_1_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_2_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_3_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_4_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_5_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_6_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_7_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    Gauge& cell_8_temp = {fam.Add({{"BMS_LV","Cells_Temperature"}})};
    
    public:

    std::string device_name = "BMSLV";

    AgentJson &device_logger     = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    std::vector<std::string> ok_states {
            "Normal Operation",
            "Charging"};

    std::vector<std::string> warning_states {
            "Unbalanced",
            "Temperature Warning"};

    std::vector<std::string> error_states {
            "Voltage too low",
            "Voltage too high",
            "High Temperature",
            "High Current",
            "Sleeping"};

    int current_state = -1;

    void Update_metrics(PUTM_CAN::BMS_LV_main);
    void Update_metrics(PUTM_CAN::BMS_LV_temperature);
};

class Bms_Hv{
    private:
    
    Family<Gauge>& BMS_HV_FAM = {BuildGauge()
                        .Name("BMS_HV")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage          = {BMS_HV_FAM.Add({{"BMS_HV",        "Voltage"}})};
    Gauge& Current          = {BMS_HV_FAM.Add({{"BMS_HV",        "Current"}})};
    Gauge& SoC              = {BMS_HV_FAM.Add({{"BMS_HV",            "SoC"}})};
    Gauge& Temperature_max  = {BMS_HV_FAM.Add({{"BMS_HV","Temperature max"}})};
    Gauge& Temperature_avg  = {BMS_HV_FAM.Add({{"BMS_HV","Temperature avg"}})};

    public:

    std::string device_name = "BMSHV";
    AgentJson &device_logger     = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    std::vector<std::string> ok_states {
        "AIRs Opened",
        "AIRs Closed", 
        "Precharge On",
        "Charger Connected",
        };

    std::vector<std::string> warning_states {
        "Charger Connected",
        "Battery unbalanced",
        "Battery critically unbalanced",
        };

    std::vector<std::string> error_states {
        "Voltage too low ",
        "Voltage too high ",
        "Temperature too high",
        "Current to high"
        };
    int current_state = -1;

    void Update_metrics(PUTM_CAN::BMS_HV_main);
};

class Fuse{
    private:
    Family<Gauge>& FUSE = {BuildGauge()
                        .Name("FUSE")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage     = {FUSE.Add({{"FUSE","Voltage"}})};
    Gauge& Current     = {FUSE.Add({{"FUSE","Current"}})};

    public:

    std::string device_name = "Smart_Fuses";

    AgentJson &device_logger = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    uint8_t safety_last = 0;
    uint8_t safety_new = 0;

    std::vector<std::string> safety_strings {
        "TSMS",
        "DV",
        "INVERTER",
        "HVD",
        "FIREWALL"
        };
    int current_state;

    void Update_metrics(PUTM_CAN::SF_safety);
    void Update_metrics(PUTM_CAN::SF_main);
};

class AQ_Card{
    private:
    Family<Gauge>& AQ_FAM = {BuildGauge()
                        .Name("AQ_Card")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Susp_front_right        = {AQ_FAM.Add({{"AQ_Card",    "Suspension_Right"}})};
    Gauge& Susp_front_left         = {AQ_FAM.Add({{"AQ_Card",     "Suspension_Left"}})};
    Gauge& brake_pressure_front    = {AQ_FAM.Add({{"AQ_Card","Brake Pressure_Front"}})};
    Gauge& brake_pressure_rear     = {AQ_FAM.Add({{"AQ_Card", "Brake Pressure_Rear"}})};
    Gauge& speed_x                 = {AQ_FAM.Add({{"AQ_Card",         "IMU front X"}})};
    Gauge& speed_y                 = {AQ_FAM.Add({{"AQ_Card",         "IMU front Y"}})};
    Gauge& speed_z                 = {AQ_FAM.Add({{"AQ_Card",         "IMU front Z"}})};
    Gauge& acc_x                   = {AQ_FAM.Add({{"AQ_Card","Acceleration front X"}})};
    Gauge& acc_y                   = {AQ_FAM.Add({{"AQ_Card","Acceleration front Y"}})};
    Gauge& acc_z                   = {AQ_FAM.Add({{"AQ_Card","Acceleration front Z"}})};

    public:
 
    AgentJson &device_logger     = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    std::string device_name = "AQ_Card";

    std::vector<std::string> ok_states {
        "POWER_UP",
        "NORMAL_OPERATION",};

    std::vector<std::string> warning_states {
        " SENSOR_IMPLOSIBILITY"};

    std::vector<std::string> error_states {};

    uint8_t safety_last = 0;
    uint8_t safety_new = 0;
    std::vector<std::string> safety_strings {
        "OVERTRAVEL",
        "LEFT_KILL",
        "RIGHT_KILL",
        "BSPD",
        "DRIVER_KILL",
        "INERTIA",
        "EBS"
        };
    
    int current_state = -1;

    void Update_metrics(PUTM_CAN::AQ_acceleration);
    void Update_metrics(PUTM_CAN::AQ_gyroscope);
    void Update_metrics(PUTM_CAN::AQ_main);
};

class Traction_Control{
    private:

    Family<Gauge>& TC = {BuildGauge()
                        .Name("Tracion_Control")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& vehicle_speed            = {TC.Add({{"Tracion_Control",                                    "Vehicle speed"}})};
    Gauge& motor_current            = {TC.Add({{"Tracion_Control",                                            "Motor"}})};
    Gauge& motor_speed              = {TC.Add({{"Tracion_Control",                                            "Motor"}})};
    Gauge& tc_intensity             = {TC.Add({{"Tracion_Control",                                     "TC intensity"}})};
    Gauge& suspension_rear_left     = {TC.Add({{"Tracion_Control",                                       "Suspension"}})};
    Gauge& suspension_rear_right    = {TC.Add({{"Tracion_Control",                                       "Suspension"}})};
    Gauge& wheel_front_left         = {TC.Add({{"Tracion_Control",                           "Wheel speed front left"}})};
    Gauge& wheel_front_right        = {TC.Add({{"Tracion_Control",                          "Wheel speed front right"}})};
    Gauge& wheel_rear_left          = {TC.Add({{"Tracion_Control",                            "Wheel speed rear left"}})};
    Gauge& wheel_rear_right         = {TC.Add({{"Tracion_Control",                           "Wheel speed rear right"}})};
    Gauge& acc_x                    = {TC.Add({{"Tracion_Control",                               "Acceleretion front"}})};
    Gauge& acc_y                    = {TC.Add({{"Tracion_Control",                               "Acceleretion front"}})};
    Gauge& acc_z                    = {TC.Add({{"Tracion_Control",                               "Acceleretion front"}})};
    Gauge& gyro_x                   = {TC.Add({{"Tracion_Control",                                         "IMU read"}})};
    Gauge& gyro_y                   = {TC.Add({{"Tracion_Control",                                         "IMU read"}})};
    Gauge& gyro_z                   = {TC.Add({{"Tracion_Control",                                         "IMU read"}})};
    Gauge& temp_engine              = {TC.Add({{"Tracion_Control",   "Temperature engine"},{"Temperatures","   Motor"}})};
    Gauge& temp_inverter            = {TC.Add({{"Tracion_Control", "Temperature inverter"},{"Temperatures","Inverter"}})};
    Gauge& water_p_in               = {TC.Add({{"Tracion_Control",    "Water pressure in"},{"Temperatures","   Water"}})};
    Gauge& water_p_out              = {TC.Add({{"Tracion_Control",   "Water pressure out"},{"Temperatures","   Water"}})};
    Gauge& temp_water_in            = {TC.Add({{"Tracion_Control", "Water temperature in"},{"Temperatures","   Water"}})};
    Gauge& temp_water_out           = {TC.Add({{"Tracion_Control","Water temperature out"},{"Temperatures","   Water"}})};

    public:

    AgentJson &device_logger     = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    std::string device_name = "Traction_Control";


    std::vector<std::string> ok_states {
            "Normal Operation",
            "Power Up",};

    std::vector<std::string> warning_states {};

    std::vector<std::string> error_states {
            "APPS Timeout",
            "APPS Invalid Value",
            "APPS Skip Frame",
            "Inverter Timeout",
            "Inverter IPEAK"};

    int current_state = -1;
    
    void Update_metrics(PUTM_CAN::TC_imu_acc);
    void Update_metrics(PUTM_CAN::TC_imu_gyro);
    void Update_metrics(PUTM_CAN::TC_main);
    void Update_metrics(PUTM_CAN::TC_wheel_velocities);   
    void Update_metrics(PUTM_CAN::TC_rear_suspension);   
    void Update_metrics(PUTM_CAN::TC_temperatures);
};

class Time{
    private:

    float Acc_lower {0};
    float Acc_upper {15};

    float SkidPad_lower {0};
    float SkidPad_upper {45};

    float Lap_lower {0};
    float Lap_upper {90};

    Family<Gauge>& Times = {BuildGauge()
            .Name("Time")
            .Help("--")
            .Register(*registry_prometheus)};

    Gauge& Acc_time =     {Times.Add({{"Lap_Timer", "Acceleration time"}})};
    Gauge& Skidpad_time = {Times.Add({{"Lap_Timer", "Skidpad time"}})};
    Gauge& Lap_Time =     {Times.Add({{"Lap_Timer", "Lap time"}})};
    Gauge& S1 =           {Times.Add({{"Lap_Timer", "Sector 1 time"}})};
    Gauge& S2 =           {Times.Add({{"Lap_Timer", "Sector 2 time"}})};
    Gauge& S3 =           {Times.Add({{"Lap_Timer", "Sector 3 time"}})};

    Family<Counter>& lap_counter = {BuildCounter()
        .Name("lap_time_counter")
        .Help("--")
        .Register(*registry_prometheus)};

    Counter &lap_Counter = {lap_counter.Add({{"Lap_Timer", "Lap number"}})};

    public:

    std::string device_name = "Lap_Timer";
    AgentJson &device_logger = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

    int current_state = -1;

    std::vector<std::string> ok_states {
        "Normal Operation",
        "Detected_Startfinish",
	    "Detected_Sector2Skid",
	    "Detected_Sector3Acc"};

    std::vector<std::string> warning_states {
        "Startfinish_battery_low",
	    "Sector_2_battery_low",	// Warning
	    "Sector_3_battery_low",	// Warning
	    "Missed_detection",	// Warning
        "Timeout"
    };
    std::vector<std::string> error_states {
        "Error"};

    void Set_Acc_Ignore_Boundaries(float upper, float lower) {
        Acc_lower = lower;
        Acc_upper = upper;}
    void Set_Lap_Ignore_Boundaries(float upper, float lower){
        Lap_lower = lower;
        Lap_upper = upper;}
    void Set_Skidpad_Ignore_Boundaries(float upper, float lower){
        SkidPad_lower = lower;
        SkidPad_upper = upper;}


    void Update_metrics(PUTM_CAN::Lap_timer_Acc_time);
    void Update_metrics(PUTM_CAN::Lap_timer_Lap_time);
    void Update_metrics(PUTM_CAN::Lap_timer_Main);
    void Update_metrics(PUTM_CAN::Lap_timer_Skidpad_time);
    void Update_metrics(PUTM_CAN::Lap_timer_Sector);
};


class WheelTemperatureSensor{
    private:
    Family<Gauge>& WheelTemperatureSensorData = {BuildGauge()
            .Name("WheelTemps")
            .Help("--")
            .Register(*registry_prometheus)};

    Gauge& wheelTemp0 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 1"}})};
    Gauge& wheelTemp1 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 2"}})};
    Gauge& wheelTemp2 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 3"}})};
    Gauge& wheelTemp3 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 4"}})};
    Gauge& wheelTemp4 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 5"}})};
    Gauge& wheelTemp5 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 6"}})};
    Gauge& wheelTemp6 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 7"}})};
    Gauge& wheelTemp7 =     {WheelTemperatureSensorData.Add({{"Wheel_Temperature_Sensor", "Pixel 8"}})};


    public:

    std::string device_name = "Wheel Temperature Sensor";
    AgentJson &device_logger = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};
    int current_state = -1;

    std::vector<std::string> ok_states {
        };

    std::vector<std::string> warning_states {
    };
    std::vector<std::string> error_states {
        "Error"};

    void Update_metrics(PUTM_CAN::WheelTemp_main);
};

}
 

template<typename T>
void Check_SC(T *SC, uint8_t new_s)
{
    SC->safety_new = new_s;
    unsigned int mask = 1;
    if(SC->safety_last != SC->safety_new)
    {
        for(int i=0;i<SC->safety_strings.size();i++)
        {
            if(!(SC->safety_new & mask))
            {
                logger.Push_Error(&SC->device_logger, SC->device_name, SC->safety_strings[i], "Open");
            }
            else
            {
                logger.Push_Info(&SC->device_logger, SC->device_name, SC->safety_strings[i], "Closed");
            }
            mask <<= 1;
        }
    }
    SC->safety_last = SC->safety_new; 
}
 