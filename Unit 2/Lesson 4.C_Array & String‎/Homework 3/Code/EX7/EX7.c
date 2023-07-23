/*
 * EX7.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Mohammed Hasan
 */

#include "stdio.h"
#include "string.h"

int main()
{

	char str[100];
	int i = 0, length = 0 ;

	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	while(str[i] != 0)
	{
		length++;
		i++;
	}
	printf("Length of string : %d",length);

	return 0;
}
