#include "Prometheus.hpp"

using namespace Data;


void Apps::Update_metrics(PUTM_CAN::Apps_main apps_frame)
{
    Counter.Set(apps_frame.counter);
    Difference.Set(apps_frame.position_diff);
    Pedal_Position.Set(apps_frame.pedal_position);
    std::cout << int(apps_frame.counter) << std::endl;
    Update_State(this, uint8_t(apps_frame.device_state));
}

void AQ_Card::Update_metrics(PUTM_CAN::AQ_acceleration aq_acc)
{

}
