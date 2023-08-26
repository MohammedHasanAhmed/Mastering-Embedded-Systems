/*
 ==========================================================================
 Name        : EX_2.c
 Author      : Mohammed Hasan
 Created on	 : Aug 26, 2023
 Description : C Program To Print All the Alphabets Using a Pointer
 ==========================================================================
 */

#include <stdio.h>

int main()
{
	char Alph[27];
	char *ptr = Alph;
	int i = 0;
	printf("** Print All the Alphabets Using a Pointer **\n");
	printf("---------------------------------------------\r\n");
	while(i < 26)
	{
		*ptr = i+'A';
		printf("%c " , *ptr);
		ptr++;
		i++;
	}

	return 0;
}

