/*
 * EX2.c
 * ==>> Calculate Factorial of a Number <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int factorial(int num);

int main()
{
	int num;

	printf("Enter an positive integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num);

	printf("Factorial of %d = %d",num ,factorial(num));

	return 0;
}

int factorial(int num)
{
	if(num == 0)
		return 1;
	return num * factorial(num - 1);
}

