#include "../SERV/std_types.h"
#include "../SERV/bit_math.h"

#include "../HAL/LCD/lcd_Init.h"
#include "../HAL/LM35/LM35_init.h"
#include "../HAL/SERVO/SERVO_init.h"
#include "../HAL/LEDS/LEDS_init.h"
#include "../HAL/DIMMER/DIMMER_Lamp.h"

#include "../MCAL/UART/UART_Init.h"

# define F_CPU 16000000UL
#include <util/delay.h>

#define delay(x)	(_delay_ms(x));

int main(void)
{
	DIMlAMP_Init();
	UART_vidInit();
	LCD_vid4BitInit();
	LM35_voidInit();
	SERVO_Init();
	LEDS_voidInit(LED1);

	while(1)
	{

		for(uint8 i = 50; i <= 100; i++)
		{
			delay(100);
			LCD_vid4BitWriteCmd(LCD_CMD_CLEAR_DIS);
			LCD_vid4BitWriteInt(i);
			DIMLamp_brightness(i);
		}
//		LEDS_voidSwitch(LED1, LED_OFF);
//		delay(500);
//		LM35_voidGetTemp();
//		LCD_vid4BitWriteCmd(LCD_CMD_CLEAR_DIS);
//		SERVO_MoveTo(90);
//		LM35_voidStart();
//		LEDS_voidSwitch(LED1, LED_ON);
	}

	return 0;
}
