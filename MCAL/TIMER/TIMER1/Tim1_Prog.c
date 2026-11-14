#include "../../../SERV/std_types.h"
#include "../../../SERV/bit_math.h"
#include "../../DIO/dio_init.h"
#include "Tim1_Config.h"
#include "Tim1_Init.h"
#include "Tim1_reg.h"










void TIM1_init(){
	INIT_TIMER1_MODE;

	/******* SEC method ********/
#if INIT_TIMER1_SELECTION_OUTPUT == TIEMR1_OC1A_SEL
	DIO_voidSetPinDir(TIMER1_PIN_OC1A,OUTPUT_PIN);
	TCCR1A |= (uint8)INIT_TIMER1_COMPA_OUT_MODE;
#elif INIT_TIMER1_SELECTION_OUTPUT == TIEMR1_OC1B_SEL
	DIO_voidSetPinDir(HTIMER1_PIN_OC1B,OUTPUT_PIN);
	TCCR1A |= (uint8)INIT_TIMER1_COMPB_OUT_MODE;
#elif INIT_TIMER1_SELECTION_OUTPUT == TIEMR1_OC1A_OC1B_SEL
	DIO_vidSetPinDir(TIMER1_PIN_OC1A,OUTPUT_PIN);
	DIO_vidSetPinDir(TIMER1_PIN_OC1B,OUTPUT_PIN);
	TCCR1A |= (uint8)INIT_TIMER1_COMPA_OUT_MODE | (uint8)INIT_TIMER1_COMPB_OUT_MODE;
#endif
}





void TIM1_WriteTCNT1(uint16 Copy_u16ValueTCNT){
	TCNT1 = Copy_u16ValueTCNT;
}
void TIM1_WriteOCRA(uint16 Copy_u16ValueOCRA){
	OCR1A = Copy_u16ValueOCRA;
}
void TIM1_WriteOCRB(uint16 Copy_u16ValueOCRB){
	OCR1B = Copy_u16ValueOCRB;
}
void TIM1_WriteICR(uint16 Copy_u16ValueICR){
	ICR1 = Copy_u16ValueICR;
}


void TIM1_Start(){
	TCCR1B |= INIT_TIMER1_SELECT_ENABLE;
}
void TIM1_Stop(){
	TCCR1B &= TIMER1_CLOCK_STOP;
}

void TIM1_OVRInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TOIE1);
}
void TIM1_COMPAInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE1A);
}
void TIM1_COMBInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE1B);
}
void TIM1_CAPInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void TIM1_OVRInterruptDisable(){
	CLEAR_BIT(TIMSK,TIMSK_TOIE1);
}
void TIM1_COMPAInterruptDisable(){
	CLEAR_BIT(TIMSK,TIMSK_OCIE1A);
}
void TIM1_COMBInterruptDisable(){
	CLEAR_BIT(TIMSK,TIMSK_OCIE1B);
}
void TIM1_CAPInterruptDisable(){
	CLEAR_BIT(TIMSK,TIMSK_TICIE1);
}
