#ifndef MCAL_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER1_TIMER1_CONFIG_H_

/************ Timer1 Mode *****************/

#define INIT_TIMER1_MODE   TIMER1_FAST_PWM_MODE

/***** Clock Select ENABLE TIMER*****/

#define INIT_TIMER1_SELECT_ENABLE         TIMER1_FACTOR_8

/*---Compare Output Mode  OCA---*/
#define INIT_TIMER1_COMPA_OUT_MODE   START_CLEAR_COMPA

/*---Compare Output Mode  OCB---*/
#define INIT_TIMER1_COMPB_OUT_MODE   START_CLEAR_COMPB

/**********-------Select Pin-----------************/
#define INIT_TIMER1_SELECTION_OUTPUT    TIEMR1_OC1A_OC1B_SEL


#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
