#include <iostream>
#include <ros/ros.h>
#include <thread>

#include "../Prometheus/Prometheus.hpp"
#include "../Prometheus/Communication.hpp"
#include "../Parser/Parser.hpp"
#include "../Loki/Loki.hpp"
#include "std_msgs/String.h"


std::shared_ptr<prometheus::Registry> registry_prometheus = std::make_shared<prometheus::Registry>();

Tlogs logger;

int main(int argc, char *argv[])
{  
    Exposer exposer{"127.0.0.1:8081"};
    
    exposer.RegisterCollectable(registry_prometheus);

    ROS_INFO("Prometheus Online.");

    //std::thread Read(Read_Terminal_async);
 
    logger.Push_Info(&logger.Telemetry_logger, "Telemetry", "Telemetry online!");

    Parser::Run();

    return 0;
}
