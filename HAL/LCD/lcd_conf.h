#ifndef HALL_LCD_LCD_CONF_H_
#define HALL_LCD_LCD_CONF_H_

/********** Mode of LCD ****************/
#define LCD_8BIT_MODE       0
#define LCD_4BIT_MODE       1
#define LCD_MODE      LCD_4BIT_MODE


/******* LCD Data 8Pin ******/
#define LCD_PORT    PORTB

/******* LCD Data 4Pin ******/
extern uint8 LCD_4Bit_Data_Pin[4];

/******** LCD Control Pin *********/
#define RS  PB0
#define RW	PB0
#define E   PB1
/********* LCD float limit *******/
#define flimit 4

#endif /* HALL_LCD_LCD_CONF_H_ */
