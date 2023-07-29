//C Program to Check Whether a Character is an Alphabet or not 
#include <stdio.h>

int main()
{
	char char_check;

	printf("Enter a character: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&char_check);

	if((char_check >='a'&& char_check <='z')||(char_check >='A'&& char_check <='Z'))
	{
		printf("%c is an alphabet ",char_check);
	}
	else
	{
		printf("%c is not an alphabet ",char_check);
	}

	return 0;
}
