#pragma once 
#include "loki/builder.hpp"

using namespace loki;

class Tlogs{
    public:
    
    loki::Registry<AgentJson> registry = Builder<AgentJson>{}
                    .Remote("127.0.0.1:3100")
                    .LogLevel(Level::Debug)
                    .PrintLevel(Level::Debug)
                    .Colorize(Level::Warn,  Color::Yellow)
                    .Colorize(Level::Error, Color::Red)
                    .Colorize(Level::Info, Color::Green)
                    .Colorize(Level::Debug, Color::Blue)
                    .FlushInterval(100)
                    .MaxBuffer(1000)
                    .Labels({})
                    .Build();

    AgentJson &Telemetry_logger = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device", "Telemetry"}})};

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message);

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
};

extern Tlogs logger;

template<typename T>
void Update_State(T object, int newstate)
{
    if(newstate != object->current_state)
    {
        if(newstate <= object->ok_states.size())
        {
            //push info
            logger.Push_Info(&object->device_logger, object->device_name, object->ok_states[newstate]);
            
        }
        else if((newstate > object->ok_states.size()) && (newstate <= (object->ok_states.size() + object->warning_states.size())))
        {
            //push warning
            logger.Push_Warning(&object->device_logger, object->device_name, object->warning_states[newstate]);
        }
        else
        {
            //push error
            logger.Push_Error(&object->device_logger, object->device_name, object->error_states[newstate]);
        }
    }
    object->current_state = newstate;
}

