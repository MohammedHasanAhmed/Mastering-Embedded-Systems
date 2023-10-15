/*
 ==========================================================================
 Name        : Alarm_Actuator.h
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_
#include "State.h"
/*============= Define States =============*/
enum 
{
    AC_Waiting   ,
    AC_Alarm_OFF ,
    AC_Alarm_ON  
}AC_State_id;

void AC_init();
// Declare State Function
State_Define(AC_Waiting);
State_Define(AC_Alarm_OFF);
State_Define(AC_Alarm_ON);

// extern State pointer
extern void(*AC_State)();
#endif /*ALARM_ACTUATOR_DRIVER_H_*/