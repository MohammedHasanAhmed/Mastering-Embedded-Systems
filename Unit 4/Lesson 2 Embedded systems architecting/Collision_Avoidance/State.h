/*
 ==========================================================================
 Name        : State.h
 Author      : Mohammed Hasan
 Created on	 : Oct 4, 2023
 Description :
 ==========================================================================
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>
#include <stdlib.h>

/*=========== Automatic State Function Generated ===========*/
#define State_Define(_STFUNC_)	void ST_##_STFUNC_()
#define State(_STFUNC_)	ST_##_STFUNC_

// States Collection
void US_Get_Distance(int distance);
void DC_Motor_Set(int speed);

#endif /* STATE_H_ */
