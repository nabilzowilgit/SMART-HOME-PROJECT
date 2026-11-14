#include "../../SERV/std_types.h"
#include "../../SERV/bit_Math.h"
#include "dio_privt.h"
#include "dio_init.h"

volatile uint8 *Arr_DIR[4]  ={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
volatile uint8 *Arr_PORT[4] ={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG,};
volatile uint8 *Arr_Pin[4]  ={PINA_REG,PINB_REG,PINC_REG,PIND_REG,};

void DIO_vidSetPortDir(uint8 u8CopyPort,uint8 u8CopyDir){
	if(u8CopyPort <= PORTD){
		*Arr_DIR[u8CopyPort] = u8CopyDir;
	}
}
void DIO_vidSetPortVal(uint8 u8CopyPort,uint8 u8CopyVal){
	if(u8CopyPort <= PORTD){
		*Arr_PORT[u8CopyPort] = u8CopyVal;
	}

}
uint8 DIO_u8GetPortVal(uint8 u8CopyPort){
	uint8 Copy_Data =0;
	if(u8CopyPort <= PORTD){
		Copy_Data = *Arr_Pin[u8CopyPort];
	}
	return Copy_Data;
}

//void DIO_vidSetPinDir(uint8 u8CopyPort,uint8 u8CopyPin,uint8 u8CopyDir){

//}

void DIO_vidSetPinDir(uint8 u8CopyPin,uint8 u8CopyDir){
	switch(u8CopyDir){
	case INPUT_PIN :    CLEAR_BIT(*Arr_DIR[u8CopyPin / 8] , (u8CopyPin % 8)); break;
	case OUTPUT_PIN :   SET_BIT(*Arr_DIR[u8CopyPin / 8] , (u8CopyPin % 8)); break;
	}
}

void DIO_vidSetPinVal(uint8 u8CopyPin,uint8 u8CopyVal){
	switch(u8CopyVal){
	case HIGH_PIN :     SET_BIT(*Arr_PORT[u8CopyPin / 8] , (u8CopyPin % 8)); break;
	case LOW_PIN :      CLEAR_BIT(*Arr_PORT[u8CopyPin / 8] , (u8CopyPin % 8)); break;
	case TOGGLE_PIN :   TOGGLE_BIT(*Arr_PORT[u8CopyPin / 8] , (u8CopyPin % 8)); break;
	}
}
uint8 DIO_u8GetPinVal(uint8 u8CopyPin){
	return GET_BIT(*Arr_Pin[u8CopyPin / 8] , (u8CopyPin % 8));
}

void DIO_vidSetPinsDir(uint8 *u8Pin,uint8 u8CopyBound,uint8 u8CopyDir){
	uint8 i;
	for(i = 0;i<u8CopyBound;i++){
		switch(u8CopyDir){
		case OUTPUT_PIN:SET_BIT(*Arr_DIR[(u8Pin[i]/8)],(u8Pin[i]%8));break;
		case INPUT_PIN :CLEAR_BIT(*Arr_DIR[(u8Pin[i]/8)],(u8Pin[i]%8));break;
		}
	}
}

void DIO_vidSetPinsVal(uint8 *u8Pin,uint8 u8CopyBound,uint8 u8CopyVal){
	uint8 i;
	for(i = 0;i<u8CopyBound;i++){
		switch(u8CopyVal){
		case HIGH_PIN:SET_BIT(*Arr_PORT[(u8Pin[i]/8)],(u8Pin[i]%8));break;
		case LOW_PIN :CLEAR_BIT(*Arr_PORT[(u8Pin[i]/8)],(u8Pin[i]%8));break;
		}
	}
}






















