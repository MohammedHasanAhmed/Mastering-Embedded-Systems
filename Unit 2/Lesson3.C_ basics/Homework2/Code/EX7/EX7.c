//C Program to Find Factorial of a Number
#include <stdio.h>

int main()
{
	int num;
	int fact =1;

	printf("Enter an integer: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);

	if (num <0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else
	{
		for(int i=1;i<=num;i++)
		{
			fact*=i;
		}
		printf("Factorial = %d",fact);
	}


	return 0;
}
