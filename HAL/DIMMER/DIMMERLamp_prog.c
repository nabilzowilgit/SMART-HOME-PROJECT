#include "DIMMER_Lamp.h"
#include "../../MCAL/TIMER/TIMER0/Tim_Init.h"
#include "../../SERV/std_types.h"

//MUST BE CONNECTED TO TIMER0 PIN

void DIMlAMP_Init(void){
	TIM0_init(PWM_FAST);
}

void DIMLamp_brightness(uint16 per){
	TIM0_SetTimComp((per*256)/100);
}
