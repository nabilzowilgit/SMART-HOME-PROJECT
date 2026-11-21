#define MCAL_TIMER2_TIM2_CONF_H_
#define MCAL_TIMER2_TIM2_CONF_H_

//WAVEFORM GENERATION MODE
#define WAVEFORM_NORMAL					0x00
#define WAVEFORM_PWM_PHASE_CORRECT		0x40
#define WAVEFORM_CTC					0x08
#define WAVEFORM_FAST_PWM				0x48

#define WAVEFORM_GENERATION_MODE		WAVEFORM_NORMAL

#define WAVEFORM_GENERATION_MODE_MASK	0xB7

#define WAVEFORM_GENERATION_MODE_SEL(WAVEFORM_MODE)	\
		(TCCR2_R = ((TCCR2_R & WAVEFORM_GENERATION_MODE_MASK) | WAVEFORM_MODE))

/*********************************************************/

//USED ONLY IF NEEDS OUTPUT
#define OC2_PIN		PD3

//OC2 MODES ON COMPARE MATCH
#define NON_PWM_OC2_DISCONNECTED	0x00
#define NON_PWM_OC2_TOGGLE			0x10
#define NON_PWM_OC2_CLEAR			0x20
#define NON_PWM_OC2_SET				0x30

#define FAST_PWM_OC2_DISCONNECTED	0x00
#define FAST_PWM_OC2_CLEAR			0x20	/* Clear OC2 on compare match, set OC2 at BOTTOM, (non-inverting mode) */
#define FAST_PWM_OC2_SET			0x30	/* Set OC2 on compare match, set OC2 at BOTTOM, (inverting mode) */

#define PHASE_CORRECT_PWM_OC2_DISCONNECTED		0x00
#define PHASE_CORRECT_PWM_OC2_CLEAR				0x20	/* Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting */
#define PHASE_CORRECT_PWM_OC2_SET				0x30	/* Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting */

#define OC2_COMP_MATCH_MODE			NON_PWM_OC2_DISCONNECTED

#define OC2_COMP_MATCH_MODE_MASK	0xCF

#define OC2_COMP_MATCH_MODE_SEL(OC2_COMP_MATCH_MODE) 	\
		(TCCR2_R = ((TCCR2_R & OC2_COMP_MATCH_MODE_MASK) | OC2_COMP_MATCH_MODE))

/*********************************************************/

//TIMER2 PRESCALER SELECT
#define NO_CLOCK							0x00	//STOPS TIMER2
#define NO_PRESCALING						0x01
#define PRESCALER_DIVISION_FACTOR_8 		0x02
#define PRESCALER_DIVISION_FACTOR_32 		0x03
#define PRESCALER_DIVISION_FACTOR_64 		0x04
#define PRESCALER_DIVISION_FACTOR_128 		0x05
#define PRESCALER_DIVISION_FACTOR_256 		0x06
#define PRESCALER_DIVISION_FACTOR_1024 		0x07

#define DIVISION_FACTOR				PRESCALER_DIVISION_FACTOR_128

#define DIVISION_FACTOR_MASK		0xF8

#define PRESCALAR_SEL(PRESCALER) 	\
		(TCCR2_R = ((TCCR2_R & DIVISION_FACTOR_MASK) | PRESCALER))

/*********************************************************/

//EXTERNAL OSCILLATOR WHEN AS2 IS HIGH
#define TOSC1_PIN	PC6	//INPUT
#define TOSC2_PIN	PC7 //INPUT

#define EXTERNAL_SOURCE		1 /* This means timer2 will be feeded from the eternal clock(Crystal Oscillator) connected on TOSC1 & TOSC2 */
#define INTERNAL_SOURCE		0

#define CLOCK_SOURCE	INTERNAL_SOURCE

#define CLOCK_SOURCE_SEL(SOURCE) \
		((SOURCE) ? SET_BIT(ASSR_R, ASSR_AS2) : CLEAR_BIT(ASSR_R, ASSR_AS2))

