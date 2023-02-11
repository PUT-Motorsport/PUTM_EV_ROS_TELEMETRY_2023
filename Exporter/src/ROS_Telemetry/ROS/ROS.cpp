#include "ROS.hpp"
#include "../Prometheus/Prometheus.hpp"

Data::Bms_Lv *lv = new Data::Bms_Lv();
Data::Apps *apps = new Data::Apps();
Data::Bms_Hv *hv = new Data::Bms_Hv();
Data::AQ_Card *aq = new Data::AQ_Card();
Data::Traction_Control *tc = new Data::Traction_Control();
Data::Temperatures *temps = new Data::Temperatures();
Data::Time *times = new Data::Time();

void Apps_Callback(const ROS_Telemetry::Apps_main::ConstPtr& msg)
{
    std::vector<double> Data {
        msg->pedal_position, 
        msg->counter, 
        msg->position_diff,  
        msg->device_state
    };

    Update(apps, Data);
}