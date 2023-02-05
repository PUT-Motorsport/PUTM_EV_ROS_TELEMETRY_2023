#include <iostream>
#include <ros/ros.h>
#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/Communication.hpp"
#include "../ROS/ROS.hpp"

Communication::variable_labels labels;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Telemetry");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("APPS", 1000, Apps_Callback);

    ros::spin();

    return 0;
}
