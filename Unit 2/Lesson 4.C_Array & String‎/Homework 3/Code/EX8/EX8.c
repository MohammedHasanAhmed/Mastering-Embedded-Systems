/*
 * EX8.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Mohammed Hasan
 */

#include "stdio.h"
#include "string.h"

int main()
{

	char str[100];
	int i , j , temp;

	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	i = 0;
	j = strlen(str) - 1;
	while(i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	printf("Reverse string is : %s\n",str);

	// Using library function
	//printf("Reverse string is : %s\n",strrev(str));


	//   Anther solution
	//	for(i = strlen(str) - 1 ; i>=0; i--)
	//	{
	//		putchar(str[i]);
	//	}



	return 0;
}
