/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
 ==========================================================================
 */
 /*
  * PS	===>> Pressure_Sensor
  * AC 	===>> Alarm_Actuator
  * MA 	===>> Main_Algorithm
  * MoA ===>> Monitor_Alarm
  */
#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Pressure_Sensor.h"
#include "Main_Algorithm.h"
#include "Monitor_Alarm.h"
#include "Alarm_Actuator.h"

void Setup()
{
	/*
	 * init all the drivers
	 * init IRQ...
	 * init HAL US_Driver DC_Driver
	 * init Block
	 * set States Pointers for each Block
	 */
	PS_init();
	AC_init();
	PS_State = State(PS_Reading);
	MA_State = Set_Pressure_Value;
	MoA_State =State(MoA_Alarm_OFF);
	AC_State = State(AC_Waiting);
}

int main (){
	GPIO_INITIALIZATION();
	Setup();
	while (1)
	{
		PS_State();
		MA_State();
		MoA_State();
		AC_State();
	}
}