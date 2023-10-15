/*
 ==========================================================================
 Name        : State.h
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

/*=========== Automatic State Function Generated ===========*/
#define State_Define(_STFUNC_) void ST_##_STFUNC_()
#define State(_STFUNC_) ST_##_STFUNC_

// States Collection
void Set_Pressure_Value(int Pressure_Value); 
void High_Pressure_Detected();               
void Start_Alarm();                          
void Stop_Alarm();                           

#endif /* STATE_H_ */