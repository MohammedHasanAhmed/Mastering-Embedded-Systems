/*
 * EX10.c
 * ################################################################
 * # C Function to count the max number of ones between two zeros #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
int max_ones(int number);
void Convert_To_Binary(int num);
int main()
{
	int num ;
	printf("Enter the number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num);

	printf("%d in Binary Number = ", num );
	Convert_To_Binary(num);
	printf("\nThe max number of ones between two zeros = %d",max_ones(num));

	return 0;
}
void Convert_To_Binary(int num)
{
	if(num > 1)
	{
		Convert_To_Binary(num/2);
	}
printf("%d" , num % 2);
}
int max_ones(int number)
{
	int count = 0;
	while(number !=0)
	{
		number = (number & (number<<1));
		count++;
	}
	return count ;
}
