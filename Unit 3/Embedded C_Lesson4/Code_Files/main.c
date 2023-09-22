/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hassan
 Created on	 : 9/22/2023
 Description : Unit 3 ==>> Lesson 4 ==>> Lab(3)
 ==========================================================================
 */
#include "Platform_Types.h"

#define SYSCTL_RCGC2_R 		*((vuint32_t*)0x400FE108)
#define GPIO_PORTF_DIR_R 	*((vuint32_t*)0x40025400)
#define GPIO_PORTF_DEN_R 	*((vuint32_t*)0x4002551C)
#define GPIO_PORTF_DATA_R 	*((vuint32_t*)0x400253FC)


int main()
{
	vuint32_t delay_count ;
	SYSCTL_RCGC2_R = 0x20 ;

	// delay to make sure GPIOF is up and running
	for(delay_count = 0 ; delay_count < 20000 ; delay_count++);
	GPIO_PORTF_DIR_R |= 1<<3 ; //DIR is Output for pin 3 port F
	GPIO_PORTF_DEN_R |= 1<<3 ; //DEN is Enable for pin 3 port F

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3 ; //set pit 3 ==>> pin3 = 1
		for(delay_count = 0 ; delay_count < 20000 ; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3) ; //reset pit 3 ==>> pin3 = 0
		for(delay_count = 0 ; delay_count < 20000 ; delay_count++);
	}
	return 0;
}