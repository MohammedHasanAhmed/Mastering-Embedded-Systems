/*
 * EX5.c
 * ==>> Reverse a Sentence Using Recursion <<==
 *  Created on: Aug 1, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

void reverse();

int main()
{
	printf("Enter a sentence: ");
	reverse();

	return 0;
}

void reverse()
{
	char c;
	scanf("%c", &c);

	if (c != '\n')
	{
		reverse();
		printf("%c", c);
	}
}


