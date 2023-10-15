/*
 ==========================================================================
 Name        : Monitor_Alarm.h
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#ifndef MONITOR_ALARM_H_
#define MONITOR_ALARM_H_
#include "State.h"

/*============= Define States =============*/
enum 
{
    MoA_Alarm_OFF ,
    MoA_Alarm_ON  ,
    MoA_Waiting
}MoA_State_id;

// Declare State Function
State_Define(MoA_Alarm_OFF);
State_Define(MoA_Alarm_ON);
State_Define(MoA_Waiting);

// extern pointer
extern void(*MoA_State)();

#endif /*MONITOR_ALARM_H_*/