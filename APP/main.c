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
#include "../HAL/UART/UART_Init.h"

#include"Login_System/LOG_Init.h"

# define F_CPU 16000000UL
#include <util/delay.h>

#define delay(x)	(_delay_ms(x));


uint8 name[8],pass[8];


int main(void)
{
	uint8 key;

	Keypad_vidInit();
	LCD_vid4BitInit();
	USART_voidInitMaster();

	while(1)
	{
		for (uint8 i=0;i<8;i++){
			name[i]=USART_uint8ReceiveData();
			USART_voidSendData(USART_uint8ReceiveData());
		}
		for (uint8 i=0;i<8;i++){
			pass[i]=USART_uint8ReceiveData();
			USART_voidSendData(USART_uint8ReceiveData());
		}
		LOG_StoreData(name,pass);
		LCD_vid4BitWriteInt(LOG_CheckData(name,pass));
	}

	return 0;
}
