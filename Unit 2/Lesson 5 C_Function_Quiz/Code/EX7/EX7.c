/*
 * EX7.c
 * ==>> Know the value of the 4th Least Significant Bit in Binary <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int main()
{
	int n , c , k ;
	printf("Enter an integer in decimal number system : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &n);

	printf("(%d) in binary number system is : ", n);
	for(c = 31 ; c >= 0; c--)
	{
		k = n >> c ;
		if(k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	k = n >> 3 ;
	if(k & 1)
		printf("4th least significant bit is 1");
	else
		printf("4th least significant bit is 0");

	return 0;
}

