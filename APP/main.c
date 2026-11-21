#include "../SERV/std_types.h"
#include "../SERV/bit_math.h"

#include "../MCAL/UART/UART_Init.h"
#include "../MCAL/TIMER/TIMER2/Tim2_Init.h"

#include "../HAL/LCD/lcd_Init.h"
#include "../HAL/LM35/LM35_init.h"
#include "../HAL/SERVO/SERVO_init.h"
#include "../HAL/LEDS/LEDS_init.h"
#include "../HAL/DIMMER/DIMMER_Lamp.h"
#include "../HAL/KEYPAD/keypad_init.h"


# define F_CPU 16000000UL
#include <util/delay.h>

#define delay(x)	(_delay_ms(x));

int main(void)
{
	uint8 key;

	Keypad_vidInit();
	LCD_vid4BitInit();

	while(1)
	{
		key = Keypad_u8CharStat();

		if (key != 0)
		{
			LCD_vid4BitWriteChar(key);
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
