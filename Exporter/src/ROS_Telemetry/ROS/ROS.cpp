#include "ROS.hpp"
#include "../Prometheus/Prometheus.hpp"
#include "../Loki/Loki.hpp"

Data::Bms_Lv *lv = new Data::Bms_Lv();
Data::Apps *apps = new Data::Apps();
Data::Bms_Hv *hv = new Data::Bms_Hv();
Data::AQ_Card *aq = new Data::AQ_Card();
Data::Traction_Control *tc = new Data::Traction_Control();
Data::Temperatures *temps = new Data::Temperatures();
Data::Time *times = new Data::Time();

extern Tlogs logger;

void Apps_Callback(const ROS_Telemetry::Apps_main::ConstPtr& msg)
{
    std::vector<double> Data {
        msg->pedal_position, 
        msg->counter, 
        msg->position_diff,  
    };

    logger.Push_Info(&logger.Telemetry_logger, "Server", "Server online");


    Update_Data(apps, Data);
    Update_State(apps, msg->device_state);
}

void bmslv_Callback(const ROS_Telemetry::Apps_main::ConstPtr& msg)
{
    std::vector<double> Data {
    };

    Update_Data(lv, Data);
    Update_State(lv, msg->device_state);
}