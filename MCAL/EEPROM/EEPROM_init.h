#ifndef HAL_HAL_EEPROM_EEPROM_INIT_H_
#define HAL_HAL_EEPROM_EEPROM_INIT_H_

#define STRING_LIMIT	0x08

void (*EEPROM_ISR_FUN)(void);

//void EEPROM_voidInit(); // not needed
void  EEPROM_voidStoreChar(uint16 address, uint8 data);
uint8 EEPROM_u8ReadChar(uint16 address);

void  EEPROM_voidStoreStr(uint16 starting_address, uint8 *string);
void  EEPROM_voidReadStr(uint16 starting_address, uint8 *string);

/* The EEPROM Ready interrupt generates a constant interrupt
 * when EEWE is cleared >> IT MUST BE TURNED OFF AFTER SIGNING THE DATA */
void EEPROM_voidReadyInterruptOn();
void EEPROM_voidReadyInterruptOff();

#endif
