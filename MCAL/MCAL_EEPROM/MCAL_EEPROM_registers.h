#ifndef MCAL_MCAL_EEPROM_MCAL_EEPROM_REGISTERS_H_
#define MCAL_MCAL_EEPROM_MCAL_EEPROM_REGISTERS_H_

#define ISR(vector)		\
    void vector(void)  __attribute__ ((signal, used, externally_visible)); \
    void vector(void)

#define EEPROM_VECTOR17    __vector_17

#define EEARL_R		(*((volatile u16*)(0x3E)))// Address Register (10 bits) (FROM 0 TO 1023)
#define EEDR_R		(*((volatile u8*)(0x3D)))// Data Register

#define EECR_R		(*((volatile u8*)(0x3C)))// Control Register
#define EECR_EERIE		3 // Ready Interrupt Enable
#define EECR_EEMWE		2 // Master Write Enable
#define EECR_EEWE		1 // EEPROM Write Enable
#define EECR_EERE		0 // EERPOM Read Enable

#define SREG_R		(*((volatile u8*)(0x5F)))	// Status Register
#define SREG_GIE  		7 // Global Interrupt Enable

#endif
