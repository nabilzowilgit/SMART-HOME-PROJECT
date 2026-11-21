#ifndef MCAL_TIMER2_TIM2_REG_H_
#define MCAL_TIMER2_TIM2_REG_H_

#define ISR(vector)		\
    void vector(void)  __attribute__ ((signal, used, externally_visible)); \
    void vector(void)

#define TMR2_COMP_VECTOR4    	__vector_4
#define TMR2_OVF_VECTOR5    	__vector_5

#define TCCR2_R		(*((volatile uint8*)(0x45)))	// Timer/Counter2 Control Register
#define TCCR2_FOC2 		7
#define TCCR2_WGM20 	6
#define TCCR2_COM21 	5
#define TCCR2_COM20 	4
#define TCCR2_WGM21 	3
#define TCCR2_CS22 		2
#define TCCR2_CS21 		1
#define TCCR2_CS20		0

#define ASSR_R		(*((volatile uint8*)(0x42)))	// Asynchronous Status Register	(all the bits are readable only)
#define ASSR_AS2 			3 //R/W
#define ASSR_TCN2UB 		2 //R
#define ASSR_OCR2UB 		1 //R
#define ASSR_TCR2UB			0 //R

#define TIMSK_R		(*((volatile uint8*)(0x59)))	// Timer/Counter2 Interrupt Mask Register
#define TIMSK_OCIE2 	7
#define TIMSK_TOIE2		6

#define TIFR_R		(*((volatile uint8*)(0x58)))	// Timer/Counter2 Interrupt Flag Register
#define TIFR_OCF2	 	7
#define TIFR_TOV2		6

#define TCNT2_R		(*((volatile uint8*)(0x44)))	// Timer/Counter2 Register
#define OCR2_R		(*((volatile uint8*)(0x43)))	// Output Compare2 Register

#define SREG_R		(*((volatile uint8*)(0x5F)))	// Status Register
#define SREG_GIE  		7 // Global Interrupt Enable

#endif
