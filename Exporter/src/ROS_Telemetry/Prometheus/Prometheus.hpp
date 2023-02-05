#pragma once
#include "prometheus/client_metric.h"
#include "prometheus/counter.h"
#include "prometheus/exposer.h"
#include "prometheus/family.h"
#include "prometheus/registry.h"

using namespace prometheus;
extern std::shared_ptr<prometheus::Registry> registry_prometheus;

namespace Data
{

class Counters{
    private:

      Family<Counter>& MESSAGES_COUNTER = {BuildCounter()
                        .Name("total_packets_received")
                        .Help("--")
                        .Register(*registry_prometheus)};
    public:

        Counter& msgA_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_A_total_packets_received"}}));
        Counter& msgB_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_B_total_packets_received"}}));
        Counter& msgC_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_C_total_packets_received"}}));
        Counter& msgD_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_D_total_packets_received"}}));
        Counter& msgE_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_E_total_packets_received"}}));
        Counter& msgF_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_F_total_packets_received"}}));
        Counter& msgG_cntr = (MESSAGES_COUNTER.Add({{"Telemetry_Statistics","message_G_total_packets_received"}}));

    template<typename T>
    void Increment_Counter(T *counter)
    {
        counter->Increment();
    }
};

class Apps{
    private:
     Family<Gauge> &APPS = {BuildGauge()
                        .Name("Apps")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge &Pedal_Position = {APPS.Add({{"Apps","Pedal Position"}})};
    Gauge &Difference     = {APPS.Add({{"Apps",    "Difference"}})};

    enum states
    {
        NORMAL_OPERATION,
        POWER_UP,
        SENSOR_IMPLAUSIBLITY,
        LEFT_SENSOR_OUT_OF_RANGE_LOWER_BOUND,
        LEFT_SENSOR_OUT_OF_RANGE_UPPER_BOUND,
        RIGHT_SENSOR_OUT_OF_RANGE_LOWER_BOUND,
        RIGHT_SENSOR_OUT_OF_RANGE_UPPER_BOUND
    };

    std::vector<std::string> apps_string_states {
            "Normal Operation",
            "Power Up",
            "Sensor Implausiblity",
            "Left sensor out of range - lower bound",
            "Left sensor out of range - upper bound",
            "Right sensor out of range - lower bound",
            "Right sensor out of range - upper bound"};

    public:

    void Update_Metrics();
};

class Bms_Lv{
    private:
    Family<Gauge>& BMS_LV = {BuildGauge()
                        .Name("BMS_LV")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage     = {BMS_LV.Add({{"BMS_LV",    "Voltage"}})};
    Gauge& SoC         = {BMS_LV.Add({{"BMS_LV",        "SoC"}})};
    Gauge& Temperature = {BMS_LV.Add({{"BMS_LV","Temperature"}})};
    Gauge& Current     = {BMS_LV.Add({{"BMS_LV",    "Current"}})};

     enum states
    {
        NORMAL,
        CHARGING,
        UNBALANCED,
        TEMP_WARNING,
        VOLTAGE_LOW,
        VOLTAGE_HIGH,
        TEMP_HIGH,
        CURRENT_HIGH,   
        SLEEP
    };

    std::vector<std::string> bmslv_string_states {
            "Normal Operation",
            "Charging", 
            "Unbalanced",
            "Temperature Warning",
            "Voltage too low",
            "Voltage too high",
            "High Temperature",
            "High Current",
            "Sleeping"};

    public:

    void Update_Metrics();
};

class Bms_Hv{
    private:
    Family<Gauge>& BMS_HV = {BuildGauge()
                        .Name("BMS_HV")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Voltage          = {BMS_HV.Add({{"BMS_HV",        "Voltage"}})};
    Gauge& Current          = {BMS_HV.Add({{"BMS_HV",        "Current"}})};
    Gauge& SoC              = {BMS_HV.Add({{"BMS_HV",            "SoC"}})};
    Gauge& Temperature_max  = {BMS_HV.Add({{"BMS_HV","Temperature max"}})};
    Gauge& Temperature_avg  = {BMS_HV.Add({{"BMS_HV","Temperature avg"}})};

    public:

    enum states
        {
            AIR_OPENED,
            AIR_CLOSED,
            PRECHARGE,
            CHARGER_CONNECTED,
            UNBALANCED,
            UNBALANCED_CRITICAL,
            VOLTAGE_LOW,
            VOLTAGE_HIGH,
            TEMP_HIGH,
            CURRENT_HIGH, 
        };

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


    void Update_Metrics();
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
    void Update_Metrics();
};

class AQ_Card{
    private:
    Family<Gauge>& AQ = {BuildGauge()
                        .Name("AQ_Card")
                        .Help("--")
                        .Register(*registry_prometheus)};

    Gauge& Susp_front_right        = {AQ.Add({{"AQ_Card",    "Suspension_Right"}})};
    Gauge& Susp_front_left         = {AQ.Add({{"AQ_Card",     "Suspension_Left"}})};
    Gauge& brake_pressure_front    = {AQ.Add({{"AQ_Card","Brake Pressure_Front"}})};
    Gauge& brake_pressure_rear     = {AQ.Add({{"AQ_Card", "Brake Pressure_Rear"}})};
    Gauge& speed_x                 = {AQ.Add({{"AQ_Card",         "IMU front X"}})};
    Gauge& speed_y                 = {AQ.Add({{"AQ_Card",         "IMU front Y"}})};
    Gauge& speed_z                 = {AQ.Add({{"AQ_Card",         "IMU front Z"}})};
    Gauge& acc_x                   = {AQ.Add({{"AQ_Card","Acceleration front X"}})};
    Gauge& acc_y                   = {AQ.Add({{"AQ_Card","Acceleration front Y"}})};
    Gauge& acc_z                   = {AQ.Add({{"AQ_Card","Acceleration front Z"}})};
    public:

    enum states
        {
            POWER_UP,
            NORMAL_OPERATION,
            SENSOR_IMPLOSIBILITY
        };

    std::vector<std::string> aq_string_states 
        {
            "POWER_UP",
            "NORMAL_OPERATION",
            "SENSOR_IMPLOSIBILITY"
        };


    void Update_Metrics();
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
    enum states
        {
            NORMAL_OPERATION,
            POWER_UP,
            APPS_TIMEOUT,
            APPS_INVALID_VALUE,
            APPS_SKIP_FRAME,
            INV_TIMEOUT,
            INT_PEAK
        };

    std::vector<std::string> tc_string_states {
                "Normal Operation",
                "Power Up",
                "APPS Timeout",
                "APPS Invalid Value",
                "APPS Skip Frame",
                "Inverter Timeout",
                "Inverter IPEAK"
                };
    
    void Update_Metrics();
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
    void Update_Metrics();
};
class Shutdown_Circut_front{
    public:
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

    void Update_Time();
};

}

template<typename T>
void Check_SC(T *SC, uint8_t new_s);