/*
 ==========================================================================
 Name        : Collision_Avoidance.c
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#include "Collision_Avoidance.h"

/*========= Variables =========*/
unsigned int CA_Speed = 0  , CA_Distance = 0 , CA_Threshold = 50;

// State Pointer to Function
void (*CA_State)() ;

/*============= Define States =============*/
enum{
	CA_Waiting ,
	CA_Driving
}CA_state_id;

void US_Get_Distance(int distance)
{
	CA_Distance = distance ;
	(CA_Distance <= CA_Threshold)? (CA_State = State(CA_Waiting)) : (CA_State = State(CA_Driving));
	printf("US ====== Distance = %d ======>> Collision_Avoidance\n" , CA_Distance);
}

State_Define(CA_Waiting)
{
	// State Name
	CA_state_id = CA_Waiting ;
	printf("CA_Waiting State: Distance = %d   Speed = %d\n" , CA_Distance , CA_Speed);
	// state Action
	CA_Speed = 0 ;
	// DC_Motor(CA_Speed)
	DC_Motor_Set(CA_Speed);

}

State_Define(CA_Driving)
{
	// State Name
	CA_state_id = CA_Driving ;
	printf("CA_Driving State: Distance = %d   Speed = %d\n" , CA_Distance , CA_Speed);
	// state Action
	CA_Speed = 30 ;
	// DC_Motor(CA_Speed)
	DC_Motor_Set(CA_Speed);
}

