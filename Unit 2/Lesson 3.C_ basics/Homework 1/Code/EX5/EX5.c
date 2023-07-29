//C Program to Find ASCII Value of a Character 

#include <stdio.h>

int main(){

	char character;

	printf("Enter a character: ");
	fflush(stdout);fflush(stdin);

	scanf("%c",&character);
	printf("ASCII value of %c = %d ",character,character);

	return 0;
}
