#ifndef HAL_HAL_EEPROM_EEPROM_INIT_H_
#define HAL_HAL_EEPROM_EEPROM_INIT_H_

void (*EEPROM_ISR_FUN)(void);

//void EEPROM_voidInit(); // not needed
void EEPROM_voidWriteData(uint16 address, uint8 data);
uint8 EEPROM_u8ReadData(uint16 address);

/* The EEPROM Ready interrupt generates a constant interrupt
 * when EEWE is cleared >> IT MUST BE TURNED OFF AFTER SIGNING THE DATA */
void EEPROM_voidReadyInterruptOn();
void EEPROM_voidReadyInterruptOff();

#endif
