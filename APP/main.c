#include "../SERV/std_types.h"
#include "../SERV/bit_math.h"

#include "../MCAL/UART/UART_Init.h"
#include "../MCAL/TIMER/TIMER2/Tim2_Init.h"
#include "../MCAL/EEPROM/EEPROM_init.h"

#include "../HAL/LCD/lcd_Init.h"
#include "../HAL/LM35/LM35_init.h"
#include "../HAL/SERVO/SERVO_init.h"
#include "../HAL/LEDS/LEDS_init.h"
#include "../HAL/DIMMER/DIMMER_Lamp.h"
#include "../HAL/KEYPAD/keypad_init.h"

#include "Login_System/LOG_Init.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#define delay(x)	(_delay_ms(x));


uint8 name[9],pass[9];


int main(void)
{
	Keypad_vidInit();
	LCD_vid4BitInit();
	USART_voidInitMaster();
	LOG_voidInit();

	while(1)
	{
//		for (uint8 i=0;i<8;i++){
//			name[i]=USART_uint8ReceiveData();
//			USART_voidSendData(name[i]);
//		}
//		for (uint8 i=0;i<8;i++){
//			pass[i]=USART_uint8ReceiveData();
//			USART_voidSendData(pass[i]);
//		}

		LCD_vid4BitWriteCmd(LCD_CMD_CLEAR_DIS);
		LCD_vid4BitGoto(0, 0);

		EEPROM_voidReadStr(ADMIN_START_ADDRESS, name);
		LCD_vid4BitWriteStr(name);
		delay(500);

		LCD_vid4BitGoto(1, 0);
		EEPROM_voidReadStr(ADMIN_START_ADDRESS + 8, pass);
		LCD_vid4BitWriteStr(pass);
		delay(500);
	}

	return 0;
}
