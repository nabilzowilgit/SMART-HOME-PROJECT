#include "../../SERVICE/std_types.h"
#include "../../SERVICE/bit_math.h"

#include "../../MCAL/DIO/dio_init.h"

#include "../../MCAL/MCAL_EEPROM/MCAL_EEPROM_registers.h"

#include "HAL_EEPROM_init.h"

//void EEPROM_voidInit() // not needed
//{
//}

void EEPROM_voidWriteData(u16 address, u8 data)
{
/*
	// USING THE ORDER OF THE STEPS LISTED IN THE DATASHEET

	while(GET_BIT(EECR_R, EECR_EEWE)); // INTERRUPT CAN BE USED INSTEAD

	EEARL_R = address;
	EEDR_R  = data;

	EECR_R |= (1 << EECR_EEMWE); // MASTER WRITE ENABLE
	EECR_R |= (1 << EECR_EEWE); // EEPROM WRITE ENABLE
*/

	  u8 savedSREG;

	/* Valid addresses: 0–1023 */
	if (address > 1023)
	{
		return;
	}

	/* Wait for any previous write to finish */
	while (GET_BIT(EECR_R, EECR_EEWE))
	{
	}

	savedSREG = SREG_R;
	__asm__ __volatile__("cli" ::: "memory");

	EEARL_R = address;
	EEDR_R = data;

	/* Enable writing within the required four cycles */
	__asm__ __volatile__(
		"sbi 0x1C, 2\n\t" /* EEMWE */
		"sbi 0x1C, 1\n\t" /* EEWE  */
		::: "memory"
	);

	SREG_R = savedSREG;
}

u8 EEPROM_u8ReadData(u16 address)
{
/*
	while(GET_BIT(EECR_R, EECR_EEWE)); // INTERRUPT CAN BE USED INSTEAD

	EEARL_R = address;

	EECR_R |= (1 << EECR_EERE);

	return EEDR_R;
*/

	u8 savedSREG;
	u8 data;

	if (address > 1023)
	{
		return 0xFF;
	}

	/* Wait for any previous write to finish */
	while (GET_BIT(EECR_R, EECR_EEWE))
	{
	}

	savedSREG = SREG_R;
	__asm__ __volatile__("cli" ::: "memory");

	EEARL_R = address;
	SET_BIT(EECR_R, EECR_EERE);
	data = EEDR_R;

	SREG_R = savedSREG;

	return data;

}

void EEPROM_voidReadyInterruptOn()
{
	SET_BIT(SREG_R, SREG_GIE);
	SET_BIT(EECR_R, EECR_EERIE); // READY INTERRUPT ENABLE
}

void EEPROM_voidReadyInterruptOff()
{
	CLEAR_BIT(EECR_R, EECR_EERIE);
}

ISR(EEPROM_VECTOR17)
{
	EEPROM_ISR_FUN();
}
