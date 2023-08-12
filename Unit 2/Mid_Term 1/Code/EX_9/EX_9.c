/*
 * EX_9.c
 * ################################################################
 * #           C Function to reverse words in string              #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>
#include <string.h>
void reverse_words(char *str , int size);
int main()
{
	char str[100] ;
	printf("Enter The String : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	reverse_words(str , strlen(str));

	return 0;
}

void reverse_words(char *str , int size)
{
	char arr[100] ;
	int i = 0 , j = 0 ;

	while(str[i] != '\0')
	{
		i++;
	}

	while(i > 0)
	{
		arr[j] = str[--i];
		j++;
	}
	arr[j] = '\0';
	printf("Reverse String : ");

	for(i = 0 ; arr[i] != '\0' ; i++)
	{
		if(arr[i+1] == ' ' || arr[i+1] == '\0')
		{
			for(j = i ; j>=0 && arr[j] != ' ' ; j--)
			{
				printf("%c" , arr[j]);
			}
			printf(" ");
		}

	}
}
