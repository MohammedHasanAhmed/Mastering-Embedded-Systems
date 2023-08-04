/*
 * EX1.c
 * ==>>  Get Prime Numbers Between Two Intervals <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int Check_PrimeNum(int num);
int main()
{
	int num1 , num2 , flag , i;

	printf("Enter Two Numbers(Intervals) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d" , &num1 , &num2);

	printf("Prime numbers between %d and %d are : " , num1 , num2);

	for( i = num1+1 ; i < num2 ; i++)
	{
		flag = Check_PrimeNum(i);

		if(flag == 1)
			printf("%d ", i);
	}

	return 0;
}
int Check_PrimeNum(int num)
{
	int i , flag = 1;

	for(i = 2 ; i <= num/2 ; i++)
	{
		if(num % i == 0)
		{
			flag = 0 ;
			break;
		}

	}
	return flag;
}
