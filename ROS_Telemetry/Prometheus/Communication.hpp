#pragma once
#include <string>
#include <vector>
#include <ros/ros.h>

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
}
void Read_Terminal_async();