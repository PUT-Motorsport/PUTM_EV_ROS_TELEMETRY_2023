#include "Loki.hpp"


void Tlogs::Push_Error  (loki::AgentJson *Logger_Handler, std::string device, std::string message)
{
    Logger_Handler->Errorf("[{}], {}", device, message);
}
void Tlogs::Push_Warning(loki::AgentJson *Logger_Handler, std::string device, std::string message)
{
    Logger_Handler->Warnf("[{}], {}", device, message);
}
void Tlogs::Push_Info   (loki::AgentJson *Logger_Handler, std::string device, std::string message)
{
    Logger_Handler->Infof("[{}], {}", device, message);
}
void Tlogs::Push_Debug  (loki::AgentJson *Logger_Handler, std::string device, std::string message)
{
    Logger_Handler->Debugf("[{}], {}", device, message);
}
//Overloaded members with comment
void Tlogs::Push_Error  (loki::AgentJson *Logger_Handler, std::string device, std::string message, std::string comment)
{
    Logger_Handler->Errorf("[{}], {}, {}", device, message, comment);
}
void Tlogs::Push_Warning(loki::AgentJson *Logger_Handler, std::string device, std::string message, std::string comment)
{
    Logger_Handler->Warnf("[{}], {}, {}", device, message, comment);
}
void Tlogs::Push_Info   (loki::AgentJson *Logger_Handler, std::string device, std::string message, std::string comment)
{
    Logger_Handler->Infof("[{}], {}, {}", device, message, comment);
}
void Tlogs::Push_Debug  (loki::AgentJson *Logger_Handler, std::string device, std::string message, std::string comment)
{
    Logger_Handler->Debugf("[{}], {}, {}", device, message, comment);
}
