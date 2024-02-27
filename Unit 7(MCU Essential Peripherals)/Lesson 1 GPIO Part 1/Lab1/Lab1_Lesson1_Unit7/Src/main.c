/*
 ==========================================================================
 Name        : Lab1_Lesson1_Unit7.c
 Author      : Mohammed Hassan
 Created on	 : Feb 27, 2024
 Description : Lab1_Lesson1_Unit7
 ==========================================================================
 */

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// RCC
#define RCC_BASE     	0x40021000
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR     	*(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR     		*(volatile uint32_t *)(RCC_BASE + 0x00)

// GPIOA
#define GPIOA_BASE   	0x40010800
#define GPIOA_CRH     	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL     	*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR     	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR     	*(volatile uint32_t *)(GPIOA_BASE + 0x08)

// GPIOB
#define GPIOB_BASE   	0x40010C00
#define GPIOB_CRH     	*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL     	*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR     	*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR     	*(volatile uint32_t *)(GPIOB_BASE + 0x08)


void clock_init()
{
	//GPIO port A clock enable
	RCC_APB2ENR |= (1 << 2) ;

	//GPIO port B clock enable
	RCC_APB2ENR |= (1 << 3) ;

}

void GPIO_init()
{
	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;

	// PA.1 Input High Z ==>> external pull up
	GPIOA_CRL |= 1<<6 ;

	// PB.1 Output Push-pull mode
	GPIOB_CRL &= ~(0b11 << 6) ; // 00: General purpose output push-pull
	GPIOB_CRL |= (0b01 << 4) ; // 01: Output mode, max speed 10 MHz.

	// PA.13 Input High Z ==>> external pull down
	GPIOA_CRH &= ~(0b11 << 20);  //00: Input mode (reset state) ==>> bit 20
	GPIOA_CRH |= (0b01 << 22);   // 01: Floating input (reset state) ==>> bit 22

	// PB.13 Output Push-pull mode ==>> external pull down
	GPIOB_CRH |= (0b01 << 20);	// 01: Output mode, max speed 10 MHz ==>> bit 20
	GPIOB_CRH &= ~(0b11 << 22); // 00: General purpose output push-pull ==>> bit 22

}

void my_wait(int x)
{
	unsigned int i , j ;
	for(i = 0 ; i < x ; i++)
		for(j = 0 ; j < 255 ; j++);
}

int main()
{
	clock_init() ;
	GPIO_init() ;

	while(1)
	{
		// PA.1 connected by external pull up Resistance by default = 1
		if( ((GPIOA_IDR & (1<<1)) >> 1) == 0) // single press
		{
			GPIOB_ODR ^= 1<<1 ;	// Toggle PB.1
			while( ((GPIOA_IDR & (1<<1)) >> 1) == 0); // single pressing
		}

		// PA.13 connected by external pull down Resistance by default = 0
		if( ((GPIOA_IDR & (1<<13)) >> 13) == 1) // multi pressing
		{
			GPIOB_ODR ^= 1<<13 ;  // Toggle PB.13
		}
		my_wait(1);
	}

}
