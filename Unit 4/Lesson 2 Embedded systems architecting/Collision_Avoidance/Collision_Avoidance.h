/*
 ==========================================================================
 Name        : Collision_Avoidance.h
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include "State.h"

// Declare State Function
State_Define(CA_Waiting);
State_Define(CA_Driving);
void US_Get_Distance(int distance);

extern void (*CA_State)() ;


#endif /* COLLISION_AVOIDANCE_H_ */
