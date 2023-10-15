/*
 ==========================================================================
 Name        : Main_Algorithm.h
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "State.h"

/*============= Define States =============*/
enum
{
    MA_High_Pressure_Detect
}MA_State_id ;

// Declare State Function
State_Define(MA_High_Pressure_Detect);

// extern pointer to function MA_State
extern void (*MA_State)() ;

#endif /*MAIN_ALGORITHM_H_*/