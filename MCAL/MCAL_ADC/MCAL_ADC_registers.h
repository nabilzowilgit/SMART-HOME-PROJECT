#ifndef MCAL_MCAL_ADC_MCAL_ADC_REGISTERS_H_
#define MCAL_MCAL_ADC_MCAL_ADC_REGISTERS_H_

#define ISR(vector)		\
    void vector(void)  __attribute__ ((signal, used, externally_visible)); \
    void vector(void)

#define ADC_VECTOR16    __vector_16

#define ADMUX_R			(*((volatile u8*)(0x27)))//ADC Multiplexer Selection Register
#define ADMUX_REFS1 	7
#define ADMUX_REFS0 	6
#define ADMUX_ADLAR 	5
#define ADMUX_MUX4 		4
#define ADMUX_MUX3 		3
#define ADMUX_MUX2 		2
#define ADMUX_MUX1 		1
#define ADMUX_MUX0 		0

#define ADCSRA_R		(*((volatile u8*)(0x26)))//ADC Control and Status Register
#define ADCSRA_ADEN    	7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE   	5
#define ADCSRA_ADIF    	4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2   	2
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS0    0

#define ADCH_R			(*((volatile u8*)(0x25)))
#define ADCL_R			(*((volatile u16*)(0x24)))

#define SFIOR_R			(*((volatile u8*)(0x50)))
#define SRIOR_ADTS2 	7
#define SRIOR_ADTS1		6
#define SRIOR_ADTS0 	5

#define SREG_R  		(*((volatile u8*)(0x5F)))// Status Register
#define SREG_GIE  		7 // Global Interrupt Enable

#endif
