#ifndef MCAL_TIMER1_TIMER1_REG_H_
#define MCAL_TIMER1_TIMER1_REG_H_

#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		\
	void vector(void)



#define TCCR1A_ADDRESS  (0x4F)
#define TCCR1B_ADDRESS  (0x4E)
#define TCNT1H_ADDRESS  (0x4D)
#define TCNT1L_ADDRESS  (0x4C)
#define OCR1AH_ADDRESS  (0x4B)
#define OCR1AL_ADDRESS  (0x4A)
#define OCR1BH_ADDRESS  (0x49)
#define OCR1BL_ADDRESS  (0x48)
#define ICR1H_ADDRESS   (0x47)
#define ICR1L_ADDRESS   (0x46)
#define TIMSK_ADDRESS   (0x59)
#define TIFR_ADDRESS    (0x58)


#define TCCR1A   *((volatile uint8 *) TCCR1A_ADDRESS )
#define TCCR1B   *((volatile uint8 *) TCCR1B_ADDRESS )

#define TCNT1    *((volatile uint16 *) TCNT1L_ADDRESS )
//#define TCNT1L   *((volatile uint8  *) TCNT1L_ADDRESS )
//#define TCNT1H   *((volatile uint8  *) TCNT1H_ADDRESS )

#define OCR1A    *((volatile uint16 *) OCR1AL_ADDRESS )
//#define OCR1AL   *((volatile uint8  *) OCR1AL_ADDRESS )
//#define OCR1AH   *((volatile uint8  *) OCR1AH_ADDRESS )

#define OCR1B    *((volatile uint16 *) OCR1BL_ADDRESS )
//#define OCR1BL   *((volatile uint8  *) OCR1BL_ADDRESS )
//#define OCR1BH   *((volatile uint8  *) OCR1BH_ADDRESS )

#define ICR1     *((volatile uint16 *) ICR1L_ADDRESS  )
//#define ICR1L    *((volatile uint8  *) ICR1L_ADDRESS  )
//#define ICR1H    *((volatile uint8  *) ICR1H_ADDRESS  )


#define TIMSK    *((volatile uint8 *) TIMSK_ADDRESS  )
#define TIFR     *((volatile uint8 *) TIFR_ADDRESS   )



#define SREG    *((volatile uint8 *) 0x5F)//

/***----GIE_BIT---**/
#define SREG_GIE   (uint8)7//

/*****---TIMSK Interrupt Register Control Enable/Disable---*****/
#define TIMSK_TOIE1   (uint8)2
#define TIMSK_OCIE1B  (uint8)3
#define TIMSK_OCIE1A  (uint8)4
#define TIMSK_TICIE1  (uint8)5

/*****---TIMER1 Control BIT Register select the clock source---*****/
#define TCCR1B_CS10   (uint8)0
#define TCCR1B_CS11   (uint8)1
#define TCCR1B_CS12   (uint8)2


/*****---TIMER1_BIT_Register_Select_Mode---*****/

#define TCCR1A_WGM10  (uint8)0
#define TCCR1A_WGM11  (uint8)1
#define TCCR1B_WGM12  (uint8)3
#define TCCR1B_WGM13  (uint8)4

/********Input Capture********/
#define TCCR1B_ICES1  (uint8)6
#define TCCR1B_ICNC1  (uint8)7



/*****---TIMER1_BIT_Register_OUTPUT_Mode---****/

#define TCCR1A_COM1B0     4
#define TCCR1A_COM1B1     5
#define TCCR1A_COM1A0     6
#define TCCR1A_COM1A1     7

#endif /* MCAL_TIMER1_TIMER1_REG_H_ */
