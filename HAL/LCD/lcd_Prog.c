#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "lcd_conf.h"
#include "lcd_Init.h"

#define F_CPU 16000000UL
#include <util/delay.h>


#if LCD_MODE == LCD_8BIT_MODE



void LCD_vid8BitInit(){
	DIO_vidSetPortDir(LCD_PORT,OUTPUT_PORT);
	DIO_vidSetPinDir(RS,OUTPUT_PIN);
	DIO_vidSetPinDir(E,OUTPUT_PIN);
	_delay_ms(40);
	LCD_vid8BitWriteCmd(LCD_CMD_8BIT_MODE);
	_delay_ms(1);
	LCD_vid8BitWriteCmd(LCD_CMD_DISPLAY_ON);
	_delay_ms(1);
	LCD_vid8BitWriteCmd(LCD_CMD_CLEAR_DIS);
	_delay_ms(2);
	LCD_vid8BitWriteCmd(LCD_CMD_ENTRY_MODE_INC);
}

void LCD_vid8BitWriteCmd(uint8 u8CopyCMD){
	DIO_vidSetPinVal(RS,LOW_PIN);
	DIO_vidSetPortVal(LCD_PORT,u8CopyCMD);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}

void LCD_vid8BitWriteChar(uint8 u8CopyChar){
	DIO_vidSetPinVal(RS,HIGH_PIN);
	DIO_vidSetPortVal(LCD_PORT,u8CopyChar);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}


void LCD_vid8BitWriteStr(uint8 *u8Str){
	uint8 i=0;
	DIO_vidSetPinVal(RS,HIGH_PIN);
	for(i =0 ;u8Str[i] != '\0';i++){
		DIO_vidSetPortVal(LCD_PORT,u8Str[i]);
		DIO_vidSetPinVal(E,HIGH_PIN);
		_delay_ms(1);
		DIO_vidSetPinVal(E,LOW_PIN);
	}
}

void LCD_vid8BitWriteInt(sint32 s32CopyNumber){
	sint8 i=0;
	uint8 arr[11] ={0};
	if(s32CopyNumber < 0){
		LCD_vid8BitWriteChar('-');
		s32CopyNumber *= -1;
	}else if(s32CopyNumber == 0){
		LCD_vid4BitWriteChar('0');
	}
	while(s32CopyNumber){
		arr[i] = (uint8)(s32CopyNumber % 10);
		s32CopyNumber /= 10;
		i++;
	}
	for(i = i -1; i >=0 ;i--){
		LCD_vid8BitWriteChar(arr[i] + '0');
	}
}
void LCD_vid8BitGoto(uint8 u8CopyRow,uint8 u8CopyCol){
	uint8 add=0;
	switch(u8CopyRow){
	case 0: add = u8CopyCol;         break;
	case 1: add = u8CopyCol + 0x40;  break;
	}
	LCD_vid8BitWriteCmd(LCD_CMD_ADD_DDRAM + add);
}



#elif LCD_MODE == LCD_4BIT_MODE

void LCD_vid4BitInit(){
	uint8 i=0;
	DIO_vidSetPinsDir(LCD_4Bit_Data_Pin,4,OUTPUT_PIN);
	DIO_vidSetPinDir(RS,OUTPUT_PIN);
	DIO_vidSetPinDir(E,OUTPUT_PIN);
	DIO_vidSetPinDir(RW,OUTPUT_PIN);
	_delay_ms(40);
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(LCD_CMD_4BIT_MODE,(4+i)));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	LCD_vid4BitWriteCmd(LCD_CMD_4BIT_MODE);
	_delay_ms(1);
	LCD_vid4BitWriteCmd(LCD_CMD_DISPLAY_ON);
	_delay_ms(1);
	LCD_vid4BitWriteCmd(LCD_CMD_CLEAR_DIS);
	_delay_ms(2);
	LCD_vid4BitWriteCmd(LCD_CMD_ENTRY_MODE_INC);

}

void LCD_vid4BitWriteCmd(uint8 u8CopyCMD){
	uint8 i=0;
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyCMD,(4+i)));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);

	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyCMD,(i)));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	_delay_ms(1);
}
void LCD_vid4BitWriteChar(uint8 u8CopyChar){
	uint8 i=0;
	DIO_vidSetPinVal(RS,HIGH_PIN);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyChar,(4+i)));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);

	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyChar,(i)));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	_delay_ms(1);
}
void LCD_vid4BitWriteStr(uint8 *u8Str){
	uint8 i=0;
	DIO_vidSetPinVal(RS,HIGH_PIN);
	for(i =0 ;u8Str[i] != '\0';i++){
		LCD_vid4BitWriteChar(u8Str[i]);
	}
}
void LCD_vid4BitWriteInt(sint32 s32CopyNumber){
	sint8 i=0;
	uint8 arr[11] ={0};
	if(s32CopyNumber < 0){
		LCD_vid4BitWriteChar('-');
		s32CopyNumber *= -1;
	}else if(s32CopyNumber == 0){
		LCD_vid4BitWriteChar('0');
	}
	while(s32CopyNumber){
		arr[i] = (uint8)(s32CopyNumber % 10);
		s32CopyNumber /= 10;
		i++;
	}
	for(i = i -1; i >=0 ;i--){
		LCD_vid4BitWriteChar(arr[i] + '0');
	}

}

void LCD_vid4BitWriteflt(float f32CopyNumber){
	sint8 i=0,j=0;
	uint8 arrp[6] ={0};
	uint8 arrf[flimit] ={0};
	if(f32CopyNumber < 0){
		LCD_vid4BitWriteChar('-');
		f32CopyNumber *= -1;
	}else if(f32CopyNumber == 0){
		LCD_vid4BitWriteChar('0');
	}
	while((sint32)f32CopyNumber){
		arrp[i] = (uint8)((uint8)f32CopyNumber % 10);
		f32CopyNumber /= 10;
		i++;
	}
	while(j<i){
		f32CopyNumber *= 10;
		j++;
	}
	j=0;
	for(i = i -1; i >=0 ;i--){
		LCD_vid4BitWriteChar(arrp[i] + '0');
	}
	LCD_vid4BitWriteChar('.');
	while(j<flimit){
		f32CopyNumber *= 10;
		LCD_vid4BitWriteChar((uint8)((uint32)f32CopyNumber % 10) + '0');
		j++;
	}
}

void LCD_vid4BitGoto(uint8 u8CopyRow,uint8 u8CopyCol){
	uint8 add=0;
	switch(u8CopyRow){
	case 0: add = u8CopyCol;         break;
	case 1: add = u8CopyCol + 0x40;  break;
	}
	LCD_vid4BitWriteCmd(LCD_CMD_ADD_DDRAM + add);
}
char LCD_vid4BitReadChar(uint8 u8CopyRow,uint8 u8CopyCol){
	uint8 i=0,j=0,add=0;
	char r=0;

	switch(u8CopyRow){
	case 0: add = u8CopyCol;         break;
	case 1: add = u8CopyCol + 0x40;  break;
	}
	LCD_vid4BitWriteCmd(LCD_CMD_ADD_DDRAM + add);
	DIO_vidSetPinsDir(LCD_4Bit_Data_Pin,4,INPUT_PIN);
	DIO_vidSetPinsVal(LCD_4Bit_Data_Pin,4,LOW_PIN);
	DIO_vidSetPinVal(RS,HIGH_PIN);
	DIO_vidSetPinVal(RW,HIGH_PIN);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	j=16;
	for(i=0;i<4;i++){
		r+=(DIO_u8GetPinVal(LCD_4Bit_Data_Pin[i]))*j;
		j*=2;
	}
	DIO_vidSetPinVal(E,LOW_PIN);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	j=1;
	for(i=0;i<4;i++){
		r+=(DIO_u8GetPinVal(LCD_4Bit_Data_Pin[i]))*j;
		j*=2;
	}
	DIO_vidSetPinVal(E,LOW_PIN);
	DIO_vidSetPinVal(RW,LOW_PIN);
	DIO_vidSetPinsDir(LCD_4Bit_Data_Pin,4,OUTPUT_PIN);
	return r;
}

#endif
