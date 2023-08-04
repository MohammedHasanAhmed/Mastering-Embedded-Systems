/*
 * EX2.c
 * ==>> Calculate Factorial of a Number <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int factorial(int num); //function Using Recursion
int fact(int num);     //function Using for loop
int main()
{
	int num;

	printf("Enter an positive integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num);

	printf("=====================\n");
	printf("Factorial of %d = %d\n",num ,factorial(num)); // Using Recursion
	printf("=====================\n");
	printf("Factorial of %d = %d\n",num ,fact(num));     // Using for loop

	return 0;
}
/*********************************************/
int factorial(int num)
{
	if(num == 0)
		return 1;
	return num * factorial(num - 1);
}
/*********************************************/
int fact(int num)
{
	int f = 1;
	for( ; num>0 ; num--)
	{
		f*=num ;
	}
	return f;
}
/*********************************************/
