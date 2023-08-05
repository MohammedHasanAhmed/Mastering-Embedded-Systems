/*
 * EX2.c
 * ==>> Compare Two String <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */


#include <stdio.h>
#include <string.h>
int main()
{
	int result ;
	char name1[20],name2[20];
	printf("Enter a string : ");
	fflush(stdout);fflush(stdin);
	gets(name1);

	printf("Enter your name : ");
	fflush(stdout);fflush(stdin);
	gets(name2);

	result = stricmp(name1 , name2);

	if(result  == 0)
		printf("Identical\n");
	else
		printf("Different\n");

	return 0;
}
