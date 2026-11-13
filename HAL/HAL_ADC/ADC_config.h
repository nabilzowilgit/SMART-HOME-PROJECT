#ifndef HAL_HAL_ADC_ADC_CONFIG_H_
#define HAL_HAL_ADC_ADC_CONFIG_H_

//AUTO TRIGER MODES
#define free_running_mode				0
#define analog_comparator				0x20
#define external_interrupt_request_0	0x40
#define timer_counter0_compare_match	0x60
#define timer_counter0_overflow			0x80
#define timer_counter1_compare_match_b	0xA0
#define timer_counter1_overflow			0xC0
#define timer_counter1_capture_event	0xE0

#define AUTO_TRIGER_MODE	external_interrupt_request_0

#define AUTO_TRIGER_MODE_SEL(MODE) \
    (SFIOR_R = (SFIOR_R & AUTO_TRIGER_MASK) | MODE)

/*********************************************************/

#define AUTO_TRIGER_MASK	0x1F
#define PRESCALER_MASK		0xF8
#define CHANNELS_MASK		0xE0
#define VOLT_REF_MASK		0x3F

#define AREF			0
#define AVCC			0x40
#define INTERNAL_2_56V	0xC0

#define VOLTAGE_REF		AVCC

#define VOLTAGE_REF_SEL(REFERENCE) \
    (ADMUX_R = (ADMUX_R & VOLT_REF_MASK) | (REFERENCE))

/*********************************************************/

#define	PRESCALER_DIVISION_FACTOR_2 	0x01
#define PRESCALER_DIVISION_FACTOR_4		0x02
#define PRESCALER_DIVISION_FACTOR_8		0x03
#define PRESCALER_DIVISION_FACTOR_16	0x04
#define PRESCALER_DIVISION_FACTOR_32	0x05
#define PRESCALER_DIVISION_FACTOR_64	0x06
#define PRESCALER_DIVISION_FACTOR_128	0x07

#define DIVISION_FACTOR	PRESCALER_DIVISION_FACTOR_128

#define PRESCALAR_SELECT(DIV_FACTOR) \
	(ADCSRA_R = (ADCSRA_R & PRESCALER_MASK) | DIV_FACTOR)

#endif
