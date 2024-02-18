/*
 ==========================================================================
 Name        : Lab3_Unit6.c
 Author      : Mohammed Hassan
 Created on	 : Feb 17, 2024
 Description : Lab3_Unit6
 ==========================================================================
 */
/* APB1 Bus frequency 16 MHZ
 * APB2 Bus frequency 8 MHZ
 * AHB frequency 32 MHZ
 * SysClk 32MHZ
 * Use only internal HSI_RC
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
#define RCC_BASE     	0x40021000
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR     	*(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR     		*(volatile uint32_t *)(RCC_BASE + 0x00)

int main()
{
	//IO port A clock enable
	RCC_APB2ENR |= (1 << 2) ;

	//PLL selected as system clock
	RCC_CFGR |= (0b10 << 0) ;

	// PLL input clock x 8
	RCC_CFGR |= (0b0110 << 18) ;

	// for ABP1
	RCC_CFGR |= (0b100 << 8) ; // HCLK divided by 2
	// for ABP2
	RCC_CFGR |= (0b101 << 11) ; // HCLK divided by 4

	// PLL enable
	RCC_CR |= (1 << 24) ;

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
