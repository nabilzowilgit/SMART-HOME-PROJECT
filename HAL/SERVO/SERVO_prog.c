#include "../../MCAL/TIMER/TIMER1/Tim1_init.h"
#include "SERVO_init.h"


void SERVO_Init(void){
	TIM1_init();
	TIM1_WriteICR(40000);

}

void SERVO_MoveTo(uint8 deg){
	//0def == 2000 , 180 == 4000

	TIM1_WriteOCRA((uint16)(((uint32)deg * 2000UL) / 180UL) + 2000);
	TIM1_Start();
}
