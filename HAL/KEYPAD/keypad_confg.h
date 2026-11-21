#ifndef HALL_KEYPAD_KEYPAD_CONFG_H_
#define HALL_KEYPAD_KEYPAD_CONFG_H_

#define KEYPAD_NO_ROW  	    4
#define KEYPAD_NO_COL 	    4
#define NO_ROW				10
#define LET_COL				5
#define TABLE_COL			5
#define TABLE_ROW			16
#define TABLE_ROW_SHIFT 	45


extern uint8 Key_MultiTap[NO_ROW][LET_COL];
extern uint8 Key_Pattern[KEYPAD_NO_ROW][KEYPAD_NO_COL];
extern uint8 Key_Row_Pin[KEYPAD_NO_ROW];
extern uint8 Key_Col_Pin[KEYPAD_NO_COL];
extern uint8 table[16][5];

#endif
