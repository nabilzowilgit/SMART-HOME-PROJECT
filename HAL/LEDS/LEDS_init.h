#ifndef HAL_LEDS_LEDS_INIT_H_
#define HAL_LEDS_LEDS_INIT_H_

#define LED1	0//PC2
#define LED2	1//PC3
#define LED3	2//PC4
#define LED4	3//PC5
#define LED5	4//PC6

#define LED_ON		1
#define LED_OFF		0

void LEDS_voidInit(uint8 led);
void LEDS_voidSwitch(uint8 led, uint8 state);

#endif
