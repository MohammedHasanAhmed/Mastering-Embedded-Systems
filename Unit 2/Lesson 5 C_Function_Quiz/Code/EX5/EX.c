/*
 * EX.c
 * ==>> Clears Bit in a given number <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int clear_specifed_bit(int n , int bit);
int main()
{
	int num , bit , result ;
	printf("Enter the number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);

	printf("Enter Bit position : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &bit);

	result = clear_specifed_bit(num , bit);
	printf("Result = %d", result);

	return 0;
}
int clear_specifed_bit(int n , int bit)
{
	return n &= ~(1 << bit);
}
