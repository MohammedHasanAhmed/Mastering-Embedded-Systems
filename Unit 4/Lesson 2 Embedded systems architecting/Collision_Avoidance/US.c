/*
 ==========================================================================
 Name        : US.c
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#include "US.h"
/*========= Variables =========*/
void (*US_State)() ;
unsigned int US_Distance = 0 ;

/*============= Define States =============*/
enum{
	US_Busy
}US_state_id;
// State Pointer to Function


void US_Init()
{
	// Init US Drivers
	printf("===================== US_Init =====================\n");

}

State_Define(US_Busy)
{
	// State Name
	US_state_id = US_Busy ;
	// Read from US_Sensor
	US_Distance = US_Get_Distance_Random(45 , 55 , 1);

	printf("US_Busy State: Distance = %d \n" , US_Distance );
	US_Get_Distance(US_Distance);
	US_State = State(US_Busy) ;
}

int US_Get_Distance_Random(int low , int rang , int count)
{
	int i  , rand_num;
	for(i = 0 ; i< count ; i++)
	{
		rand_num = (rand() % (rang - low + 1)) + low ;
		return rand_num ;
	}
}

