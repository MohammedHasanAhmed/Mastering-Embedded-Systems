/*
 ==========================================================================
 Name        : Pressure_Sensor.c
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#include "Pressure_Sensor.h"
/*========= Variables =========*/
unsigned int PS_Value = 0;
unsigned int PS_Pull_Time = 100;

// State Pointer to Function
void (*PS_State)();

void PS_init()
{
    // Intialize the Pressure Sensor
}

State_Define(PS_Reading)
{
    // State Name
    PS_State_id = PS_Reading;
    // Read from Pressure Sensor
    PS_Value = getPressureVal();
    Set_Pressure_Value(PS_Value);
    PS_State = State(PS_Waiting);
}

State_Define(PS_Waiting)
{
    // State Name
    PS_State_id = PS_Waiting;
    Delay(50000);
    PS_State = State(PS_Reading);
}