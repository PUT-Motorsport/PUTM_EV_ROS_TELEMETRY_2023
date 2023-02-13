#pragma once 
#include "loki/builder.hpp"
#include "fmt/format.h"


using namespace loki;

class Tlogs{
    public:
    
    loki::Registry<AgentJson> registry_loki = Builder<AgentJson>{}
                    .Remote("127.0.0.1:3100")
                    .LogLevel(Level::Warn)
                    .PrintLevel(Level::Debug)
                    .Colorize(Level::Warn,  Color::Yellow)
                    .Colorize(Level::Error, Color::Red)
                    .Colorize(Level::Info, Color::Green)
                    .Colorize(Level::Debug, Color::Blue)
                    .FlushInterval(100)
                    .MaxBuffer(1000)
                    .Build();

    AgentJson &Telemetry_logger = {registry_loki.Add({{"Source", "PUTM_Telemetry"}, {"Device", "Telemetry"}})};

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message);

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
};
template<typename T>
void Update_State(T object, int newstate)
{
    if(newstate != object->current_state)
    {
        if(newstate <= object->ok_states.size())
        {
            //push info
        }
        else if((newstate > object->ok_states.size()) && (newstate <= (object->ok_states.size() + object->warning_states.size())))
        {
            //push warning
        }
        else
        {
            //push error
        }
    }
}

