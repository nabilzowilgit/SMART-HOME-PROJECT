#include "../../../SERV/std_types.h"
#include "../../../SERV/bit_math.h"

#include "../../DIO/dio_init.h"

#include "Tim2_Reg.h"

#include "Tim2_Conf.h"
#include "Tim2_Init.h"

ISR(TMR2_OVF_VECTOR5)
{
	TMR2_OVF_FUN();
}

ISR(TMR2_COMP_VECTOR4)
{
	TMR2_COMP_FUN();
}

void TMR2_voidInit()
{
//USING OC2 PIN AS AN OUTPUT ON COMPARE MATCH
#if OC2_COMP_MATCH_MODE > NON_PWM_OC2_DISCONNECTED
	DIO_vidSetPinDir(OC2_PIN, OUTPUT_PIN);
#endif

#if CLOCK_SOURCE == EXTERNAL_SOURCE
	DIO_vidSetPinDir(TOSC1_PIN, INPUT_PIN);
	DIO_vidSetPinDir(TOSC2_PIN, INPUT_PIN);
#endif

	CLOCK_SOURCE_SEL(CLOCK_SOURCE);
	WAVEFORM_GENERATION_MODE_SEL(WAVEFORM_GENERATION_MODE);
	OC2_COMP_MATCH_MODE_SEL(OC2_COMP_MATCH_MODE);

	TMR2_voidCompMatchInterruptOn();
}

void TMR2_voidStart()
{
	PRESCALAR_SEL(DIVISION_FACTOR);
}

void TMR2_voidStop()
{
	PRESCALAR_SEL(NO_CLOCK);
}

void TMR2_voidOVFInterruptOn()
{
	SET_BIT(SREG_R, SREG_GIE);
	SET_BIT(TIMSK_R, TIMSK_TOIE2);
}

void TMR2_voidOVFInterruptOff()
{
	CLEAR_BIT(TIMSK_R, TIMSK_TOIE2);
}

void TMR2_voidCompMatchInterruptOn()
{
	SET_BIT(SREG_R, SREG_GIE);
	SET_BIT(TIMSK_R, TIMSK_OCIE2);
}

void TMR2_voidCompMatchInterruptOff()
{
	CLEAR_BIT(TIMSK_R, TIMSK_OCIE2);
}

void TMR2_voidWriteOCR2(uint8 uint8copy_top_value)
{
	OCR2_R = uint8copy_top_value;
}

void TMR2_voidWriteTCNT2(uint8 uint8copy_top_value)
{
	TCNT2_R = uint8copy_top_value;
}

void TMR2_voidAsynchSwitch(uint8 uint8copy_asynch_select)
{
	switch(uint8copy_asynch_select)
	{
		case CLOCK_NORMAL :	/* NOTHING TO DO */
		case CLOCK_ASYNCH : /* NOTHING TO DO */

		default : return;   /* INVALID INPUT */
	}

/* Warning: When switching between asynchronous and synchronous clocking of
Timer/Counter2, the Timer Registers TCNT2, OCR2, and TCCR2 might be corrupted. A
safe procedure for switching clock source is: */

//	1. Disable the Timer/Counter2 interrupts by clearing OCIE2 and TOIE2.
	TMR2_voidOVFInterruptOff();
	TMR2_voidCompMatchInterruptOff();
//	2. Select clock source by setting AS2 as appropriate.
	uint8copy_asynch_select ? SET_BIT(ASSR_R, ASSR_AS2) : CLEAR_BIT(ASSR_R, ASSR_AS2);
//	3. Write new values to TCNT2, OCR2, and TCCR2.
	TCNT2_R = 0x00;
	OCR2_R  = 0x00;
//	4. To switch to asynchronous operation: Wait for TCN2UB, OCR2UB, and TCR2UB.
	if(uint8copy_asynch_select) // only for asynch
	{
		while(GET_BIT(ASSR_R, ASSR_TCN2UB)   ||
			  GET_BIT(ASSR_R, ASSR_OCR2UB)   ||
			  GET_BIT(ASSR_R, ASSR_TCR2UB));
	}

//	5. Clear the Timer/Counter2 Interrupt Flags.
	CLEAR_BIT(TIMSK_R, TIMSK_TOIE2);
	CLEAR_BIT(TIMSK_R, TIMSK_OCIE2);
//	6. Enable interrupts, if needed
	TMR2_voidOVFInterruptOn();
	TMR2_voidCompMatchInterruptOn();
}
