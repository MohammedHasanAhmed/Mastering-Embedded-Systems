/*
 ==========================================================================
 Name        : DC_Motor.c
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#include "DC_Motor.h"
/*========= Variables =========*/
void (*DC_State)() ;
unsigned int DC_Speed = 0 ;
/*============= Define States =============*/
enum{
	DC_Idle ,
	DC_Busy
}DC_state_id;
// State Pointer to Function



void DC_Init()
{
	// init DC_Motor
	printf("===================== DC_Init =====================\n");

}

void DC_Motor_Set(int speed)
{
	DC_Speed = speed ;
	DC_State = State(DC_Busy) ;

	printf("CA ====== Speed = %d ======>> DC_Motor\n\n" , DC_Speed);

}

State_Define(DC_Idle)
{
	// State Name
	DC_state_id = DC_Idle ;
	// State Action
	// Call PWM to make speed  = DC_Speed

	printf("DC_Idle State: Speed = %d\n" , DC_Speed);
}

State_Define(DC_Busy)
{
	// State Name
	DC_state_id = DC_Busy ;

	// State Action
	// Call PWM to make speed  = DC_Speed
	DC_State = State(DC_Idle) ;
	printf("DC_Busy State: Speed = %d\n\n" , DC_Speed);
}





