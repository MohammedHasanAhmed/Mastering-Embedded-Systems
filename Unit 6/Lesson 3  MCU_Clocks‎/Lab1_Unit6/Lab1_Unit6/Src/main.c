/*
 ==========================================================================
 Name        : Lab1_Unit6.c
 Author      : Mohammed Hassan
 Created on	 : Feb 17, 2024
 Description : Lab1_Unit6
 ==========================================================================
 */

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// GPIOA
#define GPIOA_BASE    0x40010800
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

// RCC
#define RCC_BASE     0x40021000
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE + 0x18)


int main()
{
	//IO port A clock enable
	RCC_APB2ENR |= (1 << 2) ;


	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	while(1)
	{
		GPIOA_ODR |=  1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR  &=  ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
