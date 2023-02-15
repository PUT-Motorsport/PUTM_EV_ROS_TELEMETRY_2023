#include <iostream>
#include <ros/ros.h>
#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/Communication.hpp"
#include "../ROS/ROS.hpp"
#include "../Loki/Loki.hpp"

using namespace prometheus;
std::shared_ptr<prometheus::Registry> registry_prometheus = std::make_shared<prometheus::Registry>();

Communication::variable_labels labels{"Practice", "default", "Dry"};

Tlogs logger;

int main(int argc, char *argv[])
{  
    Exposer exposer{"127.0.0.1:8081"};

    ROS_INFO("Prometheus Online.");

    logger.Push_Info(&logger.Telemetry_logger, "Server", "Server online");

    ros::init(argc, argv, "Telemetry");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("APPS", 1000, Apps_Callback);

    ROS_INFO("ROS init done. Now spinning.");

    ros::spin();

    return 0;
}
