#include <iostream>
#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include "std_msgs/String.h"
#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/Communication.hpp"
#include "../Parser/Parser.hpp"
#include "../Loki/Loki.hpp"
#include "std_msgs/String.h"

std::shared_ptr<prometheus::Registry> registry_prometheus = std::make_shared<prometheus::Registry>();

Tlogs logger;

Communication::RosComs *rosDataHandler;

int main(int argc, char *argv[])
{  
    Exposer exposer{"127.0.0.1:8081"};
    exposer.RegisterCollectable(registry_prometheus);

    ROS_INFO("Prometheus Online.");
 
    logger.Push_Info(&logger.Telemetry_logger, "Telemetry", "Telemetry online!");

    ros::init(argc, argv, "Telemetry");

    rosDataHandler = new Communication::RosComs();

    Parser::Run();

    return 0;
}
