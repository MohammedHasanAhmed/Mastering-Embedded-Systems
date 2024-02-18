/*
 ==========================================================================
 Name        : Lab1_Lesson4_Unit6.c
 Author      : Mohammed Hassan
 Created on	 : Feb 18, 2024
 Description : Lab1_Lesson4_Unit6
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

// AFIO
#define AFIO_BASE   	 0x40010000
#define AFIO_EXTICR1     *(volatile uint32_t *)(AFIO_BASE + 0x08)

// EXTI
#define EXTI_BASE      	0x40010400
#define EXTI_IMR     	*(volatile uint32_t *)(EXTI_BASE + 0x00) // Interrupt mask register
#define EXTI_RTSR     	*(volatile uint32_t *)(EXTI_BASE + 0x08) // Rising trigger selection register
#define EXTI_PR     	*(volatile uint32_t *)(EXTI_BASE + 0x014) // Pending register

#define NVIC_EXTIE0		*(volatile uint32_t *)(0xE000E100)
void clock_init()
{
	//IO port A clock enable
	RCC_APB2ENR |= (1 << 2) ;
	// Alternate function I/O clock enable >> 1:Alternate Function I/O clock enabled
	RCC_APB2ENR |= (1 << 0) ;
}

void GPIO_init()
{
	// pin 13 port A output
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	// Pin A0 : floating input (reset state)
	GPIOA_CRL |= (1 << 2) ;
}

int main()
{
	clock_init() ;
	GPIO_init() ;
	// EXTI0 configuration PortA0
	AFIO_EXTICR1 |= (0b0000 << 0) ;

	// Enable rising trigger register
	EXTI_RTSR |= (1 << 0) ;

	// Enable EXTI interrupt line 0 (mask 1)
	EXTI_IMR |= (1 << 0) ;

	// Enable NVIC IRQ6 >> EXTI0
	NVIC_EXTIE0 |= (1 << 6) ;

	while(1) ;

}

void EXTI0_IRQHandler(void)
{
	// IRQ is Happened  >>>> port A pin 0 | Rising edge
	// Toggle Led pin A.13
	GPIOA_ODR ^= (1 << 13) ;

	// Clear Pending request for line 0 (write 1 to clear)
	EXTI_PR |= (1 << 0) ;
}
