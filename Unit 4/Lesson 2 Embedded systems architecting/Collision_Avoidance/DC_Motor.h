/*
 ==========================================================================
 Name        : DC_Motor.h
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "State.h"

// Declare State Function
void DC_Motor_Set(int speed);
void DC_Init();
State_Define(DC_Idle);
State_Define(DC_Busy);

extern void (*DC_State)() ;


#endif /* DC_MOTOR_H_ */
