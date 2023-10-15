/*
 ==========================================================================
 Name        : Monitor_Alarm.c
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#include "Monitor_Alarm.h"

/*========= Variables =========*/
unsigned int MoA_Periode = 50000;

// State Pointer to Function
void(*MoA_State)();

void High_Pressure_Detected()
{
    MoA_State = State(MoA_Alarm_ON);
}

State_Define(MoA_Alarm_OFF)
{
    // State Name
    MoA_State_id = MoA_Alarm_OFF ;
    Stop_Alarm();
    MoA_State = State(MoA_Alarm_OFF);
}
State_Define(MoA_Alarm_ON)
{
    // State Name
    MoA_State_id = MoA_Alarm_ON ;
    Start_Alarm();
    MoA_State = State(MoA_Waiting);
}
State_Define(MoA_Waiting)
{
    // State Name
    MoA_State_id = MoA_Waiting ;
    Stop_Alarm();
    Delay(MoA_Periode);
    MoA_State = State(MoA_Alarm_OFF);
}