#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"

#include "../../MCAL/ADC/ADC_init.h"
#include "../LCD/lcd_Init.h"

#include "LM35_init.h"

void LM35_voidInit()
{
	ADC_ISR_FUN = LM35_voidGetTemp;

	ADC_voidInit();
}

void LM35_voidStart(void)
{
	ADC_voidStartConversion(LM35_CHANNEL);
}

void LM35_Stop(void)
{
	ADC_voidSwitchOff();
}

void LM35_voidGetTemp(void)
{
	LCD_vid4BitWriteInt(ADC_u16RetrunResult(LM35_CHANNEL) / LM35_CONVETION_RATIO);
}
