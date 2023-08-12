/*
 * EX_3.c
 * ################################################################
 * #  C Function to print all prime numbers between two numbers   #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */
#include <stdio.h>

int check_prime(int number);
int main()
{
	int num1 , num2 ,i ,flag;

	printf("Enter Number 1 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num1);

	printf("Enter Number 2 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num2);

	printf("Prime Numbers Between %d and %d : ",num1 ,num2);
	for(i = num1 ; i<num2 ; i++)
	{
		flag = check_prime(i);
		if(flag == 1)
			printf("%d " , i);
	}

	return 0 ;
}

int check_prime(int number)
{
	int flag = 1 , i ;
	for(i = 2 ; i<= number/2 ; i++)
	{
		if(number % i == 0)
		{
			flag = 0 ; //it is not prime number
			break;
		}
	}
	return flag ;
}
