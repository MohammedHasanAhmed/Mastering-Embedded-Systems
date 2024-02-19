/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hassan
 Created on	 : Feb 19, 2024
 Description : Lab2_Lesson4(MCU Interrupts)-unit6
 ==========================================================================
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 8000000UL

#define Set_Bit(add ,no_bit)	add |=  (1<<no_bit)
#define Reset_Bit(add ,no_bit)	add &= ~(1<<no_bit)
#define Toggle_Bit(add ,no_bit)	add ^=  (1<<no_bit)
#define Read_Bit(add , no_bit)  ((add & (1<<no_bit)) >> no_bit)

#define IO_BASE	0x20
#define MCUCR 		*(volatile uint32_t*)(IO_BASE + 0x35)
#define MCUCSR 		*(volatile uint32_t*)(IO_BASE + 0x34)
#define GICR 		*(volatile uint32_t*)(IO_BASE + 0x3B)
#define IO_DDRD 	*(volatile uint32_t*)(IO_BASE + 0x11)
#define IO_PORTD 	*(volatile uint32_t*)(IO_BASE + 0x12)


int main(void)
{
	// Set INT0 logical
	Set_Bit(MCUCR,0);
	Reset_Bit(MCUCR,1);
	
	// Set INT1 Rising edge
	Set_Bit(MCUCR,2);
	Set_Bit(MCUCR,3);
	
	// Set INT2 Falling edge
	Reset_Bit(MCUCSR,6) ;

	// Enables Interrupts ==>> INT0 , INT1 ,INT2 ==>> GICR General interrupt control register 
	Set_Bit(GICR,5) ; // External Interrupt Request 1 Enable INT1
	Set_Bit(GICR,6) ; // External Interrupt Request 0 Enable INT0
	Set_Bit(GICR,7) ; // External Interrupt Request 2 Enable INT2

	// Enable SREG Status register ==>>  Global Interrupt Enable
	sei();

	// Allow pins (5 , 6 , 7) as output in portD (Pin0)
	Set_Bit(IO_DDRD,5);
	Set_Bit(IO_DDRD,6);
	Set_Bit(IO_DDRD,7);
	
    while(1)
    {
    	Reset_Bit(IO_PORTD,5);
		Reset_Bit(IO_PORTD,6);
		Reset_Bit(IO_PORTD,7);      
    }
return 0 ;
}
    ISR(INT0_vect)
    {
	    Set_Bit(IO_PORTD,5);
	    _delay_ms(1000);
    }
    ISR(INT1_vect)
    {
	    Set_Bit(IO_PORTD,6);
	    _delay_ms(1000);
    }
    ISR(INT2_vect)
    {
	    Set_Bit(IO_PORTD,7);
	    _delay_ms(1000);
    }