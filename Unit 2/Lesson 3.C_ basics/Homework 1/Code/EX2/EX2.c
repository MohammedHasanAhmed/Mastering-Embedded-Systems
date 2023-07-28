//C Program to Print an Integer Entered by a User 

#include <stdio.h>

int main()
{
	int integer_num;

	printf("Enter a integer: ");
	fflush(stdout);fflush(stdin);

	scanf("%d",&integer_num);
	printf("You entered : %d",integer_num);

	return 0;
}
