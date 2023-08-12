/*
 * EX_4.c
 * ################################################################
 * #            C Function to reverse digits number               #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
int reverse_digitsNum(int number)
{
	int rev = 0,rem = 0;
	while(number != 0)
	{
		rem = number % 10;
		rev = 10*rev + rem;
		number/=10;
	}
	return rev ;
}
int main()
{
	int num ;
	printf("Enter the number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num);

	printf("Reverse of digits number = %d",reverse_digitsNum(num));

	return 0;
}
