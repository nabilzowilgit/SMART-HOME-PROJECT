#ifndef HAL_SERVO_MOTOR_SERVO_INIT_H_
#define HAL_SERVO_MOTOR_SERVO_INIT_H_

#include "../../MCAL/TIMER/TIMER1/Tim1_init.h"
#include "../../SERV/std_types.h"

void SERVO_Init(void);

void SERVO_MoveTo(uint8 deg);

#endif
