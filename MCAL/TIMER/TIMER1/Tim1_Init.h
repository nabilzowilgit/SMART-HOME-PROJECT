#ifndef MCAL_TIMER_TIMER1_TIM1_INIT_H_
#define MCAL_TIMER_TIMER1_TIM1_INIT_H_

#include "../../../SERV/std_types.h"

/*********-------INputCAP-----**********/



/************ Timer1 Mode *****************/

#define TIMER1_NORMAL                 TCCR1A |= (uint8)0x00; \
	                                  TCCR1B |= (uint8)0x00

#define TIMER1_FAST_PWM_MODE          TCCR1A |= (uint8)0x02; \
	                                  TCCR1B |= (uint8)0x18

#define TIMER1_CTC_MODE               TCCR1A |= ((0 << TCCR1A_WGM11) | (0 << TCCR1A_WGM10)); \
	                                  TCCR1B |= ((1 << TCCR1B_WGM13) | (1 << TCCR1B_WGM12))

#define TIMER1_PHASE_CORRECT          TCCR1A |= (uint8)0x02; \
	                                  TCCR1B |= (uint8)0x10


/*---Compare Output Mode  OCA---*/

#define NORMAL_OUTPUT_MODE       0x00
#define START_TOGGLE_COMPA       0x40
#define START_CLEAR_COMPA        0x80
#define START_SET_COMPA          0xC0



/*---Compare Output Mode  OCB---*/

#define NORMAL_OUTPUT_MODE       0x00
#define START_TOGGLE_COMPB       0x10
#define START_CLEAR_COMPB        0x20
#define START_SET_COMPB          0x30


/**********-------Select Pin-----------************/

#define TIEMR1_OC1A_SEL         0U
#define TIEMR1_OC1B_SEL         1U
#define TIEMR1_OC1A_OC1B_SEL    2U


/******----------TIMER1 PIN NUMBER --------*******/

#define TIMER1_PIN_OC1A    PD5
#define TIMER1_PIN_OC1B    PD4
#define TIMER1_PIN_ICP1    PD6


/******** Stop Timer Clear Bit ********/

#define TIMER1_CLOCK_STOP     (uint8)0xF8


/***** Clock Select ENABLE TIMER*****/

/*---TIMER SELSET FACTOR---*/
#define TIMER1_FACTOR_1                     (uint8)0x01    // 1U
#define TIMER1_FACTOR_8                     (uint8)0x02    // 2U
#define TIMER1_FACTOR_64                    (uint8)0x03    // 3U
#define TIMER1_FACTOR_256                   (uint8)0x04    // 4U
#define TIMER1_FACTOR_1024                  (uint8)0x05    // 5U
#define TIMER1_FACTOR_EXT_FALLING_PIN_T0    (uint8)0x06    // 6U   //using Counter with S.W
#define TIMER1_FACTOR_EXT_RISING_PIN_T0     (uint8)0x07    // 7U   //using Counter with S.W







void TIM1_init();


void TIM1_WriteTCNT1(uint16 Copy_u16ValueTCNT);
void TIM1_WriteOCRA(uint16 Copy_u16ValueOCRA);
void TIM1_WriteOCRB(uint16 Copy_u16ValueOCRB);
void TIM1_WriteICR(uint16 Copy_u16ValueICR);

void TIM1_Start(void);
void TIM1_Stop(void);

void TIM1_OVRInterruptEnable(void);
void TIM1_COMPAInterruptEnable(void);
void TIM1_COMBInterruptEnable(void);
void TIM1_CAPInterruptEnable(void);

void TIM1_OVRInterruptDisable(void);
void TIM1_COMPAInterruptDisable(void);
void TIM1_COMBInterruptDisable(void);
void TIM1_CAPInterruptDisable(void);





#endif /* MCAL_TIMER_TIMER1_TIM1_INIT_H_ */
