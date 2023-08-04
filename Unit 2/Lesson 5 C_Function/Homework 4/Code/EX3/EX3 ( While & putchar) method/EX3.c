/*
 * EX3.c
 * ==>> Reverse a Sentence <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
#include <string.h>

void reverse(char str[]); // Using putchar
void reverse2(char str[]); // Using while

int main()
{
	char str[100] ;
	printf("Enter a sentence : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	printf("=====================================\n");
	reverse(str);
	printf("\n=====================================");
	reverse2(str);

	return 0;
}
/****************************************************/
void reverse(char str[])
{
	int i;

	printf("Reverse string is : ");

	for(i = strlen(str) - 1 ; i >= 0 ;i--)
	{
		putchar(str[i]);
	}

}
/****************************************************/
//another solution
void reverse2(char str[])
{
	int i ,temp ,j;

	i = 0 ;
	j = strlen(str) - 1 ;

	while(i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	printf("\nReverse string is : %s\n" , str);
}
/****************************************************/
