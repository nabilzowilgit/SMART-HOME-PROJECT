#ifndef HALL_KEYPAD_KEYPAD_INIT_H_
#define HALL_KEYPAD_KEYPAD_INIT_H_

#define NOTHING_PRESSED	0x00

void Keypad_vidInit();
uint8 Keypad_u8Stat();// for normal keypad (Patern)
uint8 Keypad_u8CharStat();// multitap keypad



#endif
