#include "../../SERVICE/std_types.h"
#include "../../SERVICE/bit_math.h"

#include "dio_init.h"
#include "dio_registers.h"

static volatile u8 *regs_PINS [regs_no] = {&PINA_R,  &PINB_R,  &PINC_R,  &PIND_R};
static volatile u8 *regs_DDRS [regs_no] = {&DDRA_R,  &DDRB_R,  &DDRC_R,  &DDRD_R};
static volatile u8 *regs_PORTS[regs_no] = {&PORTA_R, &PORTB_R, &PORTC_R, &PORTD_R};

void DIO_voidSetPinsDir(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_direction)
{
	u8 u8count = 0;

	for(u8count = 0; u8count < u8copy_size; u8count++)
	{
		switch(u8copy_direction)
		{
			case PIN_OUTPUT :
				SET_BIT(*regs_DDRS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;

			case PIN_INPUT :
				CLEAR_BIT(*regs_DDRS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;
		}
	}
}

void DIO_voidSetPinsVal(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_val)
{
	u8 u8count = 0;

	for(u8count = 0; u8count < u8copy_size; u8count++)
	{
		switch(u8copy_val)
		{
			case PIN_HIGH :
				SET_BIT(*regs_PORTS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;

			case PIN_LOW :
				CLEAR_BIT(*regs_PORTS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;
		}
	}
}

void DIO_voidCopyPinsVal(u8 *u8copy_pins, u8 u8copy_size, u8 u8copy_values)
{
	u8 u8count;

	for(u8count = 0; u8count < u8copy_size; u8count++)
	{
		switch(GET_BIT(u8copy_values, u8count))
		{
			case PIN_HIGH :
				SET_BIT(*regs_PORTS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;

			case PIN_LOW :
				CLEAR_BIT(*regs_PORTS[u8copy_pins[u8count] / 8], u8copy_pins[u8count] % 8);
				break;
		}
	}
}

void DIO_voidSetPinDir(u8 u8copy_pin, u8 u8copy_direction)
{
	if(u8copy_pin <= PD7)
	{
		switch(u8copy_direction)
		{
			case PIN_OUTPUT :
				SET_BIT(*regs_DDRS[u8copy_pin / 8], u8copy_pin % 8);
			break;

			case PIN_INPUT :
				CLEAR_BIT(*regs_DDRS[u8copy_pin / 8], u8copy_pin % 8);
			break;

			default : break; /* NOTHING TO DO :) */
		}
	}
	else
		return;
}

void DIO_voidSetPinVal(u8 u8copy_pin, u8 u8copy_val)
{
	if(u8copy_pin <= PD7)
	{
		switch(u8copy_val)
		{
			case PIN_TOGGLE :
				TOGGLE_BIT(*regs_PORTS[u8copy_pin / 8], u8copy_pin % 8);
			break;

			case PIN_HIGH :
				SET_BIT(*regs_PORTS[u8copy_pin / 8], u8copy_pin % 8);
			break;

			case PIN_LOW :
				CLEAR_BIT(*regs_PORTS[u8copy_pin / 8], u8copy_pin % 8);
			break;

			default : break; /* NOTHING TO DO :) */
		}
	}
	else
		return;
}

u8 DIO_u8GetPinVal(u8 u8copy_pin)
{
	if(u8copy_pin <= PD7)
	{
		 return GET_BIT(*regs_PINS[u8copy_pin / 8], u8copy_pin % 8);
	}

	return ERROR;
}

void DIO_voidSetPortDir(u8 u8copy_port, u8 u8copy_direction)
{
	if(u8copy_port <= PORTD)
	{
		*regs_DDRS[u8copy_port] = u8copy_direction;
	}
	else
		return;
}

void DIO_voidSetPortVal(u8 u8copy_port, u8 u8copy_val)
{
	if(u8copy_port <= PORTD)
	{
		*regs_PORTS[u8copy_port] = u8copy_val;
	}
	else
		return;
}

u8 DIO_u8GetPortVal(u8 u8copy_port)
{
	if(u8copy_port <= PORTD)
	{
		return *regs_PINS[u8copy_port];
	}
	else
		return ERROR;
}

void DIO_voidTogglePort(u8 u8copy_port)
{
	if(u8copy_port <= PORTD)
	{
		TOGGLE_REG(*regs_PORTS[u8copy_port]);
	}
	else
		return;
}
