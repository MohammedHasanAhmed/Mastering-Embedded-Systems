/*
 * EX6.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Mohammed Hasan
 */
#include "stdio.h"
#include "string.h"

int main()
{

	char name[100];
	char character;
	int i ,count = 0, found = 0;

	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(name);

	printf("Enter a character to find frequency : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&character);

	strlwr(name);
	for(i = 0 ; i <strlen(name);i++)
	{
		if(character == name[i])
		{
			count++;
			found = 1;
		}
	}
	if(found == 1)
		printf("Frequency of character %c = %d",character,count);
	else
		printf("character %c not found in the text ",character);

	return 0;
}

