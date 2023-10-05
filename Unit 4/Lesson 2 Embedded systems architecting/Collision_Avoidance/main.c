/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#include "Collision_Avoidance.h"
#include "US.h"
#include "DC_Motor.h"

void Setup()
{
	/*
	 * init all the drivers
	 * init IRQ...
	 * init HAL US_Driver DC_Driver
	 * init Block
	 * set States Pointers for each Block
	 */
	US_Init();
	DC_Init();

	CA_State = State(CA_Waiting);
	US_State = State(US_Busy);
	DC_State = State(DC_Idle);

}
int main()
{
	volatile int i ;
	Setup();
	while(1)
	{
		// call State for each Block
		US_State();
		CA_State();
		DC_State();

		for(i = 0 ; i< 5000 ; i++);
	}

	return 0 ;
}
