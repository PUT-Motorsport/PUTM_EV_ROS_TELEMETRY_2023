#pragma once

#include<algorithm>
#include <array>
#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <thread>
#include <iostream>
#include <vector>
#include <iterator>

#include "../Loki/Loki.hpp"

extern Tlogs logger;

/*

template<typename T>
void Check_SC(T *SC, uint8_t new_s)
{
    SC->safety_new = new_s;
    unsigned int mask = 1;
    if(SC->safety_last != SC->safety_new)
    {
        for(int i=0;i<SC->safety_strings.size();i++)
        {
            if(!(SC->safety_new & mask))
            {
                logger.Push_Error(&SC->device_logger, SC->device_name, SC->safety_strings[i], "Open");
            }
            else
            {
                logger.Push_Info(&SC->device_logger, SC->device_name, SC->safety_strings[i], "Closed");
            }
            mask <<= 1;
        }
    }
    SC->safety_last = SC->safety_new; 
}
*/