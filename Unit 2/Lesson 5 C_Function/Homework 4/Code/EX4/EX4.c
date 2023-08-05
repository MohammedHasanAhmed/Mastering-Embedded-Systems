/*
 * EX4.c
 * ==>> Calculate The Power of a Number Using Recursion <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int power(int base , int exp);

int main()
{
	int base , exp;
	printf("Enter Base Number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &base);

	printf("Enter power Number(positive integer) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &exp);

	printf("%d ^ %d = %d" , base , exp , power(base , exp));
	return 0;
}

int power(int base , int exp)
{
	if(exp != 0)
		return (base*power(base , exp-1));
	else
		return 1;

}
