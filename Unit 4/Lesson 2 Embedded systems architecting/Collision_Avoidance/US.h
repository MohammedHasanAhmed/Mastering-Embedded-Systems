/*
 ==========================================================================
 Name        : US.h
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#ifndef US_H_
#define US_H_
#include "State.h"

// Declare State Function
int US_Get_Distance_Random(int low , int rang , int count) ;
void US_Init();
State_Define(US_Busy);


extern void (*US_State)() ;


#endif /* US_H_ */
