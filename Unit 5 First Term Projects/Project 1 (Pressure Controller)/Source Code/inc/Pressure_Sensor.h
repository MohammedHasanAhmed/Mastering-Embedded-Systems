/*
 ==========================================================================
 Name        : Pressure_Sensor.h
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_
#include "State.h"

/*============= Define States =============*/
enum
{
    PS_Reading ,
    PS_Waiting
}PS_State_id;

void PS_init();
// Declare State Function
State_Define(PS_Reading);
State_Define(PS_Waiting);

// extern State pointer
extern void (*PS_State)() ;

#endif /*PRESSURE_SENSOR_DRIVER_H_*/