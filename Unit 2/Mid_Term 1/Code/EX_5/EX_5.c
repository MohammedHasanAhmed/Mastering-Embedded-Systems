/*
 * EX_5.c
 * ################################################################
 * #     C function to count number of ones in binary number      #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

void Convert_To_Binary(int num);
void count_ones(int num);

int main()
{
	int number ;

	printf("Enter The Number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &number);

	printf("%d in Binary Number = ", number );

	Convert_To_Binary(number);
	count_ones(number);

	return 0;
}
void Convert_To_Binary(int num)
{
	if(num > 1)
	{
		Convert_To_Binary(num>>1) ;
	}
	printf("%d" , num&1);
}
void count_ones(int num)
{
	int i ,count = 0;

	for(i = 0 ; i < 32 ; i++)
	{
		if(num &(1<<i))
		{
			count++;
		}
	}
	printf("\nCount Number of Ones in Binary Number = %d",count);
}
