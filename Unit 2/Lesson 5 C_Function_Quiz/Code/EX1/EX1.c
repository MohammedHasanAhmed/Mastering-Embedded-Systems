/*
 * EX1.c
 * Check if a given number is power of 3 or not
 *  Created on: Aug 3, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
#include <math.h>

int check_powerof3(unsigned num);
//another solution with another function
int check_power_3(unsigned num);

int main()
{
	int num ;
	printf("Enter the number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);

	printf("=====>> first function <<=====\n");
	check_powerof3(num) ? printf("%d ==>> 0\n" , num) : printf("%d ==>> 1\n" , num) ;
	printf("=====>> second function <<====\n");
	check_power_3 (num)? printf("%d ==>> 0\n" , num) : printf("%d ==>> 1\n" , num) ;

	return 0;
}
/***************************************************************************/
int check_powerof3(unsigned num)
{
	if(num == 0)
		return 0 ;
	double power = log(num) / log(3) ;

	return power == trunc(power); // It returns a double value whose values after the decimal point is 0 only.

}
/***************************************************************************/
int check_power_3(unsigned num)
{
	double power = log(num) / log(3) ;

	return (power - (int)power) == 0 ;
}
/***************************************************************************/
