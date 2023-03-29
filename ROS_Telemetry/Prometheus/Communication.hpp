#pragma once
#include <string>
#include <vector>
#include <ros/ros.h>
#include "ROS_Telemetry/APPSKURWAKOZA.h"
#include "ROS_Telemetry/AQ_CARD.h"
#include "ROS_Telemetry/BMSHV.h"
#include "ROS_Telemetry/BMSLV.h"
#include "ROS_Telemetry/TC.h"

namespace Communication{

    struct variable_labels{
        std::string driver;
        std::string run;
        std::string condition;
    };

    struct semafora{
        bool change;
    };

    class sanity_check{
        public:
        static inline const std::vector<std::string> Runs =   {     
                                    "Practice", 
                                    "Acceleration", 
                                    "Skidpad", 
                                    "Autocross", 
                                    "Endurance"};

        static inline const std::vector<std::string> Drivers = {     
                                    "Jan Węgrzynowski", 
                                    "Maksymilian Jaruga", 
                                    "Szymon Stempniak", 
                                    "Mikołaj Pogonowski", 
                                     };
        static inline const std::vector<std::string> Condition{
                                    "Dry",
                                    "Wet"

        };
    };
class RosComs{

    public:

    ros::NodeHandle nd;

    ros::Publisher tcPublisher   = nd.advertise<ROS_Telemetry::TC>     ("TC_Data", 5);
    ros::Publisher aqPublisher   = nd.advertise<ROS_Telemetry::AQ_CARD>("AQ_Card_Data", 5);
    ros::Publisher lvPublisher   = nd.advertise<ROS_Telemetry::BMSLV>  ("BMSLV_Data", 5);
    ros::Publisher hvPublisher   = nd.advertise<ROS_Telemetry::BMSHV>  ("BMSHV_Data", 5);
    ros::Publisher appsPublisher = nd.advertise<ROS_Telemetry::APPSKURWAKOZA> ("APPS_Data", 5);

    ROS_Telemetry::TC tractionControlROS;
    ROS_Telemetry::AQ_CARD aqCardROS;
    ROS_Telemetry::BMSLV bmsLvROS;
    ROS_Telemetry::BMSHV bmsHvROS;
    ROS_Telemetry::APPSKURWAKOZA appsROS;
};
}
void Read_Terminal_async();