#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"

#include "../../MCAL/DIO/dio_init.h"

#include "keypad_init.h"
#include "keypad_confg.h"

#include "../../MCAL/TIMER/TIMER2/Tim2_Init.h"

#include <util/delay.h>

volatile uint16 timer_counter = 0;

void waitingTime()
{
	++timer_counter;
}

void Keypad_vidInit(void)
{
	DIO_vidSetPinsDir(Key_Row_Pin,KEYPAD_NO_ROW,INPUT_PIN);
	DIO_vidSetPinsDir(Key_Col_Pin,KEYPAD_NO_COL,OUTPUT_PIN);
	DIO_vidSetPinsVal(Key_Row_Pin,KEYPAD_NO_ROW,HIGH_PIN);
	DIO_vidSetPinsVal(Key_Col_Pin,KEYPAD_NO_COL,HIGH_PIN);
}

uint8 Keypad_u8Stat(void)
{
	uint8 pressed_key = 0, i, y;

	for(i =0;i <KEYPAD_NO_COL ;i++)
	{
		DIO_vidSetPinVal(Key_Col_Pin[i],LOW_PIN);

		for(y = 0;y < KEYPAD_NO_ROW ; y++)
		{
			if(DIO_u8GetPinVal(Key_Row_Pin[y]) == 0)
			{
				pressed_key = Key_Pattern[y][i];

				while(DIO_u8GetPinVal(Key_Row_Pin[y]) == 0);
//				_delay_ms(20);

				DIO_vidSetPinVal(Key_Col_Pin[i],HIGH_PIN);
				return pressed_key;//one = pressed
			}
		}

		DIO_vidSetPinVal(Key_Col_Pin[i],HIGH_PIN);
	}
	return NOTHING_PRESSED;// zero (nothing was pressed)
}

uint8 Keypad_u8CharStat(void)
{
	uint8 char_counter = 0;
	uint8 pressed_key = Keypad_u8Stat();// value of one if any key was pressed
	uint8 temporary_key = pressed_key;

	if(pressed_key != NOTHING_PRESSED) // a button was pressed
	{
		if((pressed_key >= '0') && (pressed_key <= '9'))
		{
			TMR2_COMP_FUN = waitingTime;// compare match function
			TMR2_voidInit();
			TMR2_voidWriteOCR2(249); // preload for 500 times for 1 SEC
			TMR2_voidStart();

			while(timer_counter < 500) // 500 times for 1 SEC
			{
				temporary_key = Keypad_u8Stat();

				if(temporary_key == pressed_key) // same key was pressed
				{
					char_counter++;
				}
			}

			TMR2_voidStop();
			timer_counter = 0;
			return table[pressed_key - TABLE_ROW_SHIFT][TABLE_COL + char_counter];
		}
		else // one of the special characters was pressed
		{
			return pressed_key;
		}
	}

	return NOTHING_PRESSED;
}


