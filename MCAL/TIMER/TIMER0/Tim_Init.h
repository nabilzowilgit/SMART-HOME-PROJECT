#ifndef MCAL_TIMER_TIM_INIT_H_
#define MCAL_TIMER_TIM_INIT_H_

/************** TIMER0 MODES **************/
#define NORMAL					0
#define PWM_PHASE_CORRECT		1
#define COMPARE					8
#define PWM_FAST				9

/************** OC0 FUNCTIONS **************/
#define DISCONNECT_OC0					 					0
#define NORM_TOGG_OC0_OnComp								1
#define NORM_CLR_OC0_OnComp									2
#define NORM_SET_OC0_OnComp									3
#define FPWM_CLR_OC0_OnComp_SET_AtBottom					2
#define FPWM_SET_OC0_OnComp_CLR_AtBottom					3
#define PCPWM_CLR_OC0_OnComp_SET_OnComp						2 //Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
#define PCPWM_SET_OC0_OnComp_CLR_OnComp						3 //Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.

/************** TIMER CLOCK **************/
#define TIMER_STOP				0
#define CLKby1					1
#define CLKby8					2
#define CLKby64					3
#define CLKby256				4
#define CLKby1024				5
#define EXT_CLK_FallAdge		6
#define EXT_CLK_RaisAdge		7



void TIM0_init(uint8 mode);

void TIM0_SetTimVal(uint8 val);

void TIM0_SetTimComp(uint8 comp);

void TIM0_ChangeCLK(uint8 clk);

void TIM0_ChangeMODE(uint8 mode);

void TIM0_ChangeOC(uint8 func);

void TIM0_OVRInterruptEnable(void);
void TIM_vidOVRInterruptDisable(void);


void TIM0_vidCOMPInterruptEnable(void);
void TIM_vidCOMPInterruptDisable(void);





#endif /* MCAL_TIMER_TIM_INIT_H_ */
