#pragma once 
#include "loki/builder.hpp"

using namespace loki;

class Tlogs{
    private:
    
    loki::Registry<AgentJson> registry = Builder<AgentJson>{}
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

    public:loki

    AgentJson &PUTM_Logger     = {registry.Add({{"Source", "PUTM_Telemetry"}})};
    AgentJson &APPS_Logger     = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","APPS"}})};
    AgentJson &BMSLV_Logger    = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","BMS_LV"}})};
    AgentJson &BMSHV_Logger    = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","BMS_HV"}})};
    AgentJson &AQ_Logger       = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","Aq_Card"}})};
    AgentJson &TC_Logger       = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","Tracio_control"}})};
    AgentJson &Sh_Circut       = {registry.Add({{"Source", "PUTM_Telemetry"}, {"Device","Shutdown_Circut"}})};

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message);

    void Push_Error  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Warning(AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Info   (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);
    void Push_Debug  (AgentJson *Logger_Handler, std::string device, std::string message, std::string comment);

};
