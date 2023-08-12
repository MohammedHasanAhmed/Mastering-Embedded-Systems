/*
 * EX_2.c
 * ################################################################
 * # C Function to take an integer number and calculate it's sqrt #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
#include <math.h>

float square_root(int number)
{
	return sqrt(number);
}

int main()
{
	int number ;

	printf("Enter The Number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &number);

	printf("sqrt(%d) = %.3f",number , square_root(number));
	return 0;
}
