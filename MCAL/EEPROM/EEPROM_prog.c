#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"

#include "../DIO/dio_init.h"

#include "EEPROM_registers.h"

#include "EEPROM_init.h"

void EEPROM_voidStoreChar(uint16 address, uint8 data)
{
/*
 *  MY MANUAL CODE USING ONLY C
 *
	// USING THE ORDER OF THE STEPS LISTED IN THE DATASHEET

	while(GET_BIT(EECR_R, EECR_EEWE)); // INTERRUPT CAN BE USED INSTEAD

	EEARL_R = address;
	EEDR_R  = data;

	EECR_R |= (1 << EECR_EEMWE); // MASTER WRITE ENABLE
	EECR_R |= (1 << EECR_EEWE); // EEPROM WRITE ENABLE
*/

	/* AI CODE USING ASSEMPLY */

	  uint8 savedSREG;

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

uint8 EEPROM_u8ReadChar(uint16 address)
{
/*
 * 	MY MANUAL CODE USING ONLY C
 *
	while(GET_BIT(EECR_R, EECR_EEWE)); // INTERRUPT CAN BE USED INSTEAD

	EEARL_R = address;

	EECR_R |= (1 << EECR_EERE);

	return EEDR_R;
*/

	/* AI CODE USING ASSEMPLY */

	uint8 savedSREG;
	uint8 data;

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

void  EEPROM_voidStoreStr(uint16 starting_address, uint8 *string)
{
	for(uint8 i = 0; i < STRING_LIMIT; i++)
	{
		EEPROM_voidStoreChar(starting_address + i, string[i]);
	}
}

void EEPROM_voidReadStr(uint16 starting_address, uint8 *string)
{
	for(uint8 i = 0; i < STRING_LIMIT; i++)
	{
		string [i] = EEPROM_u8ReadChar(starting_address + i);
	}
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
