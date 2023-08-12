/*
 * EX_1.c
 * ############################################################
 * #     C Function to take a number and sum all digits	      #
 * ############################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int Sum_Digits(int num);

int main()
{
	int number ;

	printf("Enter The Number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &number);

	printf("Sum Of Digits = %d",Sum_Digits(number));

	return 0;
}
int Sum_Digits(int num)
{
	int sum = 0;
	if(num != 0)
	{
		sum = num%10 ;
		return sum + Sum_Digits(num/10);
	}
	return 0;
}
