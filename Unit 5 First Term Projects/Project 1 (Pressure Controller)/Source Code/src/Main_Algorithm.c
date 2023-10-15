/*
 ==========================================================================
 Name        : Main_Algorithm.c
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
#include "Main_Algorithm.h"
/*========= Variables =========*/
unsigned int MA_Pressure_Value = 0 ;
unsigned int MA_Pressure_Threshold = 20 ;

// State Pointer to Function
void (*MA_State)() ;

void Set_Pressure_Value(int Pressure_Value)
{
    MA_Pressure_Value = Pressure_Value ;
    MA_State = State(MA_High_Pressure_Detect);
}
// Declare State Function
State_Define(MA_High_Pressure_Detect)
{
    // State Name 
    MA_State_id = MA_High_Pressure_Detect ;

    //State Action
    if(MA_Pressure_Value <= MA_Pressure_Threshold)
    {
        MA_State = State(MA_High_Pressure_Detect);
    }
    else
    {
        High_Pressure_Detected();
        MA_State = State(MA_High_Pressure_Detect);
    }
}