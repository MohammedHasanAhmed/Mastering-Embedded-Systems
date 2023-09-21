/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hassan
 Created on	 : 9/20/2023
 Description : Unit 3==>> Lesson 3 ==>> Lab(2)
 ==========================================================================
 */
#include "Platform_Types.h"

#define RCC_BASE	 0x40021000
#define PortA_BASE 	 0x40010800

#define RCC_APB2ENR *(vuint32_t *) (RCC_BASE + 0x18)
#define GPIO_CRH 	*(vuint32_t *) (PortA_BASE + 0x04)
#define GPIO_ODR 	*(vuint32_t *) (PortA_BASE + 0x0C)

typedef union
{
	vuint32_t all_fields ;

	struct
	{
		vuint32_t reserved : 13 ;
		vuint32_t pin_13 : 1 ;
	} pin;

} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(PortA_BASE + 0x0C) ;
vuint32_t global_variables[3] = {1,2,3};
vuint32_t const const_variavles[3] = {1,2,3};

extern void NMI_Handler(void)
{

}

extern void Bus_Fault(void)
{

}

int main(void)
{
	RCC_APB2ENR |= (1<<2) ; //set pit 2
	GPIO_CRH 	&= 0xff0fffff ;
	GPIO_CRH	|= 0x00200000 ; //set pits(20-24) 2

	while(1)
	{
		R_ODR->pin.pin_13 = 1 ;
		for(int i = 0 ; i < 5000 ; i++);
		R_ODR->pin.pin_13 = 0 ;
		for(int i = 0 ; i < 5000 ; i++);
	}
	return 0 ;
}