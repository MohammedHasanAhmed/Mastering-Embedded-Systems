/*
 ==========================================================================
 Name        : Lab2_Lesson1 GPIO_Unit7.c
 Author      : Mohammed Hassan
 Created on	 : Feb 28, 2024
 Description : Atmega32
 ==========================================================================
 */

#include "MemMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{	
// Enable DDRA
		
		DDRA |= 0b11111111;

    while (1) 
    {
			// Set pit 
			for(int i = 0 ; i < 8 ; i++)
			{
				SET_BIT(PORTA , i) ; 
				_delay_ms(500);
			}	
			// reset pit
			_delay_ms(500);
			for(int i = 7 ; i >= 0 ; i--)
		    {
				RESET_BIT(PORTA , i) ;
				_delay_ms(500);
			}
    }
}

