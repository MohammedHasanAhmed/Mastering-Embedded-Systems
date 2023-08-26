/*
 ==========================================================================
 Name        : EX_3.c
 Author      : Mohammed Hasan
 Created on	 : Aug 26, 2023
 Description : C Program To Print A String in Reverse Using A Pointer
 ==========================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	char *ptr_str = str;
	char rev[100];
	char *ptr_rev = rev;
	int i;

	printf("** Print A String in Reverse Using A Pointer **\n");
	printf("-----------------------------------------------\r\n");

	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	scanf("%s" , str);

	int n = strlen(str) - 1;
	ptr_str = &str[n];
	for(i = n; i>=0 ; i-- , ptr_str--)
	{
		*ptr_rev = *ptr_str;
		ptr_rev++;
	}
	*ptr_rev = 0;
	ptr_rev = rev;

	printf("Reverse of the string is : %s\n" , rev);
	return 0;
}
