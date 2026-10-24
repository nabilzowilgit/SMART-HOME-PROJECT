#ifndef DIO_INIT_H_
#define DIO_INIT_H_

#define ERROR	(u8)0

#define regs_no (u8)4

#define PORTA	(u8)0
#define PORTB	(u8)1
#define PORTC	(u8)2
#define PORTD	(u8)3

typedef enum
{
	PA0 = 0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,//7

	PB0,//8
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,//15

	PC0,//16
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,//23

	PD0,//24
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7	//31
}pins;

#define PIN_HIGH	(u8)1
#define PIN_LOW		(u8)0

#define PULL_UP		(u8)1
#define PULL_DOWN	(u8)0

#define PIN_TOGGLE	(u8)2
#define PIN_OUTPUT  (u8)1
#define PIN_INPUT	(u8)0

#define PORT_OUTPUT	0xff
#define PORT_INPUT 	0x00

#define PORT_HIGH	0xff
#define PORT_LOW	0x00

void DIO_voidSetPinsDir(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_direction);
void DIO_voidSetPinsVal(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_val);
void DIO_voidCopyPinsVal(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_values);

void DIO_voidSetPinDir (u8 u8copy_pin, u8 u8copy_direction);
void DIO_voidSetPinVal (u8 u8copy_pin, u8 u8copy_val);
void DIO_voidTogglePin (u8 u8copy_pin);
u8   DIO_u8GetPinVal   (u8 u8copy_pin);

void DIO_voidSetPortDir(u8 u8copy_port, u8 u8copy_direction);
void DIO_voidSetPortVal(u8 u8copy_port, u8 u8copy_val);
u8   DIO_u8GetPortVal  (u8 u8copy_port);
void DIO_voidTogglePort(u8 u8copy_port);

#endif
