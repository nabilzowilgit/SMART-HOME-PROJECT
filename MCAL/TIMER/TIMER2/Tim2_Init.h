#ifndef MCAL_TIMER2_TIM2_INIT_H_
#define MCAL_TIMER2_TIM2_INIT_H_

#define CLOCK_NORMAL	0
#define CLOCK_ASYNCH	1

void TMR2_voidInit();

void TMR2_voidStart();
void TMR2_voidStop();

void TMR2_voidOVFInterruptOn();
void TMR2_voidOVFInterruptOff();

void TMR2_voidCompMatchInterruptOn();
void TMR2_voidCompMatchInterruptOff();

void TMR2_voidWriteOCR2(uint8 u8copy_top_value);
void TMR2_voidWriteTCNT2(uint8 u8copy_top_value);

void TMR2_voidAsynchSwitch(uint8 u8copy_asynch_select);

void (*TMR2_OVF_FUN)(void);
void (*TMR2_COMP_FUN)(void);

#endif
