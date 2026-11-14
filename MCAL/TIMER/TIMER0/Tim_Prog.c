#include "../../../SERV/std_types.h"
#include "../../../SERV/bit_math.h"
#include "../../DIO/dio_init.h"
#include "Tim_Init.h"
#include "Tim_Conf.h"
#include "Tim_Reg.h"




void TIM0_init(uint8 mode){
	DIO_vidSetPinDir(PB3,OUTPUT_PIN);
	SET_BITS(TCCR0,3,mode);
	SET_BITS(TCCR0,0,Init_PRESCALER);
	SET_BITS(TCCR0,4,Init_CO0FUNCTION);
}

void TIM0_SetTimVal(uint8 val){
	TCNT0=val;
}

void TIM0_SetTimComp(uint8 comp){
	OCR0=comp;
}

void TIM0_ChangeCLK(uint8 clk){
	CLR_BITS(TCCR0,0,7);
	SET_BITS(TCCR0,0,clk);
}

void TIM0_ChangeMODE(uint8 mode){
	CLR_BITS(TCCR0,3,9);
	SET_BITS(TCCR0,3,mode);
}

void TIM0_ChangeOC(uint8 func){
	CLR_BITS(TCCR0,4,3);
	SET_BITS(TCCR0,4,func);
}

void TIM0_OVRInterruptEnable(void){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TOIE0);
}
void TIM0_OVRInterruptDisable(void){
	CLEAR_BIT(TIMSK,TIMSK_TOIE0);
}
void TIM00_vidCOMPInterruptEnable(void){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE0);
}
void TIM0_vidCOMPInterruptDisable(void){
	CLEAR_BIT(TIMSK,TIMSK_OCIE0);
}
