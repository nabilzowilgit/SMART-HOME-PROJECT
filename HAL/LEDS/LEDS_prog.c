#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"

#include "../../MCAL/DIO/dio_init.h"

#include "LEDS_init.h"

void LEDS_voidInit(uint8 led)
{
	if((led <= LED5) && (led >= LED1))
	{
		DIO_vidSetPinDir(led + PC2, OUTPUT_PIN);
		DIO_vidSetPinVal(led + PC2, LOW_PIN);
	}
}

void LEDS_voidSwitch(uint8 led, uint8 state)
{
	if((led <= LED5) && (led >= LED1))
	{
		DIO_vidSetPinVal(led + PC2, state);
	}
}
