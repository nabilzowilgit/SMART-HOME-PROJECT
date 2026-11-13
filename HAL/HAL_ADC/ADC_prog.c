#include "../../SERVICE/std_types.h"
#include "../../SERVICE/bit_math.h"

#include "../../MCAL/DIO/dio_init.h"

#include "../../MCAL/MCAL_ADC/MCAL_ADC_registers.h"

#include "ADC_config.h"
#include "ADC_init.h"

#define F_CPU 16000000UL
#include <util/delay.h>

ISR(ADC_VECTOR16)
{
    ADC_ISR_FUN();
}

void ADC_voidInit()
{
	VOLTAGE_REF_SEL(VOLTAGE_REF);

	CLEAR_BIT(ADMUX_R, ADMUX_ADLAR);

	PRESCALAR_SELECT(DIVISION_FACTOR);

	ADC_voidInterruptOn();
	ADC_voidSwitchOn();
}

void ADC_voidSwitchOn()//NOT NEEDED IF USED INITIALED FUN
{
	SET_BIT(ADCSRA_R, ADCSRA_ADEN);
}

void ADC_voidSwitchOff()
{
	CLEAR_BIT(ADCSRA_R, ADCSRA_ADEN);
}

void ADC_voidChannelSel(u8 u8copy_channel)//NOT NEEDED IF USED START CONVERSION FUN
{
	ADMUX_R = (ADMUX_R & CHANNELS_MASK) | u8copy_channel;
}

void ADC_voidInterruptOn()
{
	SET_BIT(SREG_R, SREG_GIE);//GLOBAL
	SET_BIT(ADCSRA_R, ADCSRA_ADIE);//ADC
}

void ADC_voidInterruptOff()
{
	SET_BIT(ADCSRA_R, ADCSRA_ADIE);
}

void ADC_voidStartConversion(u8 u8copy_channel)//ACTION HAPPENS WHEN INTERRUPT OCCURS
{
	ADC_voidChannelSel(u8copy_channel);
	SET_BIT(ADCSRA_R, ADCSRA_ADSC);
}

u16 ADC_u16RetrunResult(u8 u8copy_channel)//POOLING TILL INTERUPT FLAG
{
	ADC_voidChannelSel(u8copy_channel);
//	CLEAR_BIT(ADCSRA_R, ADCSRA_ADIF);//RESET BEFORE ANOTEHR CONVERSION

//	ADC_voidStartConversion(u8copy_channel);
//	while((GET_BIT(ADCSRA_R, ADCSRA_ADSC)));//START CONVERION BIT
//	while(!GET_BIT(ADCSRA_R, ADCSRA_ADIF));//INT FLAG BIT

	return ADCL_R;
}

void ADC_voidAutoTrigerOn()
{
	SET_BIT(ADCSRA_R, ADCSRA_ADATE);
	AUTO_TRIGER_MODE_SEL(AUTO_TRIGER_MODE);
}

void ADC_voidAutoTrigerOff()
{
	CLEAR_BIT(ADCSRA_R, ADCSRA_ADATE);
}
