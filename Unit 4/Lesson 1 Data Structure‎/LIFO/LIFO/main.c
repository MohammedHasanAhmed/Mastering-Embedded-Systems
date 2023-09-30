/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hasan
 Created on	 : 9/29/2023
 Description : LIFO
 ==========================================================================
 */

#include "lifo.h"
#define buffer_length 5

element_type buffer[buffer_length] ;

int main()
{
	element_type i , temp = 0 ;
	lifo_buf_t uart_lifo ;

	lifo_init(&uart_lifo , buffer , buffer_length) ;

/*============== Add item ==============*/
	printf("=========== LIFO Writing ========\n");
	for(i = 0 ; i < buffer_length ; i++)
	{
		if(lifo_add_buf(&uart_lifo , i) == lifo_no_error )
		printf("UART_ADD_LIFO: %d\n" , i);
	}

/*============== Get item ==============*/
	printf("\n=========== LIFO Reading ========\n");
	for(i = 0 ; i < buffer_length ; i++)
	{
		if( lifo_get_buf(&uart_lifo , &temp) ==  lifo_no_error)
		printf("UART_GET_LIFO: %d\n" , temp);
	}

	return 0 ;
}
