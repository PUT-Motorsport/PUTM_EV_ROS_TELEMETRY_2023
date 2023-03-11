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

#include "../PUTM_DV_ROS2CAN_2023/Inc/putm_can_interface.hpp"

using namespace prometheus;

extern std::shared_ptr<prometheus::Registry> registry_prometheus;
extern Tlogs logger;

namespace Data
{

class Apps{
    private:

    Family<Gauge> &fam = {BuildGauge()
                        .Name("APPS")
                        .Help("--")
                        .Register(*registry_prometheus)};

    //Order here matters. Gauges should be defined in opposite order, than in msg file.
    Gauge &Counter        = {fam.Add({{"Apps",       "Counter"}})};
    Gauge &Difference     = {fam.Add({{"Apps",    "Difference"}})};
    Gauge &Pedal_Position = {fam.Add({{"Apps","Pedal Position"}})};

    public:

    std::string device_name = "Apps";
    AgentJson &device_logger = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};
    int current_state;

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

    void Update_metrics(PUTM_CAN::Apps_main apps_frame);
};

class Bms_Lv{
    public:

    std::string device_name = "BMSLV";

    Family<Gauge> &fam = {BuildGauge()
                        .Name("BMS_LV")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage     = {fam.Add({{"BMS_LV",    "Voltage"}})};
    Gauge& SoC         = {fam.Add({{"BMS_LV",        "SoC"}})};
    Gauge& Temperature = {fam.Add({{"BMS_LV","Temperature"}})};
    Gauge& Current     = {fam.Add({{"BMS_LV",    "Current"}})};

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

    int current_state;
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

    std::vector<std::string> bmshv_string_states {
                "AIRs Opened",
                "AIRs Closed", 
                "Precharge On",
                "Charger Connected",
                "Battery unbalanced",
                "Battery critically unbalanced",
                "Voltage too low ",
                "Voltage too high ",
                "Temperature too high",
                "Current to high"};
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

    std::vector<std::string> aq_string_states 
        {
            "POWER_UP",
            "NORMAL_OPERATION",
            "SENSOR_IMPLOSIBILITY"
        };
};

class Traction_Control{
    private:
    Family<Gauge>& TC = {BuildGauge()
                        .Name("Tracion_Control")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& vehicle_speed            = {TC.Add({{"Tracion_Control",     "Vehicle speed"}})};
    Gauge& motor_current            = {TC.Add({{"Tracion_Control",             "Motor"}})};
    Gauge& motor_speed              = {TC.Add({{"Tracion_Control",             "Motor"}})};
    Gauge& tc_intensity             = {TC.Add({{"Tracion_Control",      "TC intensity"}})};
    Gauge& suspension_rear_left     = {TC.Add({{"Tracion_Control",        "Suspension"}})};
    Gauge& suspension_rear_right    = {TC.Add({{"Tracion_Control",        "Suspension"}})};
    Gauge& wheel_front_left         = {TC.Add({{"Tracion_Control",        "Wheel speed front left"}})};
    Gauge& wheel_front_right        = {TC.Add({{"Tracion_Control",       "Wheel speed front right"}})};
    Gauge& wheel_rear_left          = {TC.Add({{"Tracion_Control",         "Wheel speed rear left"}})};
    Gauge& wheel_rear_right         = {TC.Add({{"Tracion_Control",        "Wheel speed rear right"}})};
    Gauge& acc_x                    = {TC.Add({{"Tracion_Control","Acceleretion front"}})};
    Gauge& acc_y                    = {TC.Add({{"Tracion_Control","Acceleretion front"}})};
    Gauge& acc_z                    = {TC.Add({{"Tracion_Control","Acceleretion front"}})};
    Gauge& gyro_x                   = {TC.Add({{"Tracion_Control",          "IMU read"}})};
    Gauge& gyro_y                   = {TC.Add({{"Tracion_Control",          "IMU read"}})};
    Gauge& gyro_z                   = {TC.Add({{"Tracion_Control",          "IMU read"}})};

    public:

    std::vector<std::string> tc_string_states {
                "Normal Operation",
                "Power Up",
                "APPS Timeout",
                "APPS Invalid Value",
                "APPS Skip Frame",
                "Inverter Timeout",
                "Inverter IPEAK"
                };
};
 
class Temperatures{
    private:
    Family<Gauge>& temps = {BuildGauge()
                        .Name("Temperatures")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& temp_engine         = {temps.Add({{"Temperatures","   Motor"}})};
    Gauge& temp_inverter       = {temps.Add({{"Temperatures","Inverter"}})};
    Gauge& water_p_in          = {temps.Add({{"Temperatures","   Water"}})};
    Gauge& water_p_out         = {temps.Add({{"Temperatures","   Water"}})};
    Gauge& temp_water_in       = {temps.Add({{"Temperatures","   Water"}})};
    Gauge& temp_water_out      = {temps.Add({{"Temperatures","   Water"}})};

    std::vector<Gauge*> Tempsv {
        &temp_engine, 
        &temp_inverter,
        &water_p_in, 
        &water_p_out,  
        &temp_water_in,
        &temp_water_out,
    };
    public:
};
class Shutdown_Circut_front{
    public:

    std::string device_name = "Shutdown_Circut_front";

    AgentJson &device_logger     = {logger.registry.Add({{"Source", "PUTM_Telemetry"}, {"Device",device_name}})};

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
};

class Shutdown_Circut_rear{
    public:

    std::string device_name = "Shutdown_Circut_rear";

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

    public:

    Gauge& Acc_time =     {Times.Add({})};
    Gauge& Skidpad_time = {Times.Add({})};
    Gauge& Lap_Time =     {Times.Add({})};
    Gauge& S1 =           {Times.Add({})};
    Gauge& S2 =           {Times.Add({})};
    Gauge& S3 =           {Times.Add({})};

    Time() = default;
    ~Time(){}
    void Set_Acc_Ignore_Boundaries(float upper, float lower) {
        Acc_lower = lower;
        Acc_upper = upper;}
    void Set_Lap_Ignore_Boundaries(float upper, float lower){
        Lap_lower = lower;
        Lap_upper = upper;}
    void Set_Skidpad_Ignore_Boundaries(float upper, float lower){
        SkidPad_lower = lower;
        SkidPad_upper = upper;}
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
 