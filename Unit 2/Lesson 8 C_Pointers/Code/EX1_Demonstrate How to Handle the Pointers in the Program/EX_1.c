/*
 =================================================================================
 Name        : EX_1.c
 Author      : Mohammed Hasan
 Created on	 : Aug 26, 2023
 Description : C Program To Demonstrate How to Handle the Pointers in the Program
 =================================================================================
 */


#include <stdio.h>

int main()
{
	int m = 29 ;
	int *ab = &m;
	printf("*****************************************\n");
	printf("==>>  Address of m : %p \n" ,&m);
	printf("==>>  Value of m : %d \n" , m);
	printf("*****************************************\r\n");

	printf("***** Now ab is assigned with the address of m *****\r\n");
	printf("==>>  Address of pointer ab : %p\n" ,ab );
	printf("==>>  Content of pointer ab : %d\r\n" , *ab);

	m = 34;
	printf("***** The value of m assigned to 34 now *****\r\n");
	printf("==>>  Address of pointer ab : %p\n" ,ab );
	printf("==>>  Content of pointer ab : %d\r\n" , *ab);

	*ab = 7;
	printf("***** the pointer variable ab is assigned with the value of 7 now *****\r\n");
	printf("==>>  Address of pointer ab : %p\n" ,ab );
	printf("==>>  Content of pointer ab : %d\r\n" , m);

	return 0;
}
