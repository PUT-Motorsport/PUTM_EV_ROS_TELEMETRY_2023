#include <iostream>
#include <ros/ros.h>
#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/Communication.hpp"
#include "../Parser/Parser.hpp"
#include "../Loki/Loki.hpp"

std::shared_ptr<prometheus::Registry> registry_prometheus = std::make_shared<prometheus::Registry>();

Tlogs logger;

int main(int argc, char *argv[])
{  
    Exposer exposer{"127.0.0.1:8081"};

    ROS_INFO("Prometheus Online.");
 
    logger.Push_Info(&logger.Telemetry_logger, "Telemetry", "Telemetry online!");

    ros::init(argc, argv, "Telemetry");
    ros::NodeHandle n;

    Parser::Run();

    return 0;
}
