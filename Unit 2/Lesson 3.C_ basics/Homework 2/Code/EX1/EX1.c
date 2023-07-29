//C program to check whether a Number is Even or Odd 
#include <stdio.h>

int main()
{
	int x;

	printf("Enter an integer you want to check: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);

	if (x % 2 ==0)
	{
		printf("%d is Even ",x);
	}
	else
	{
		printf("%d is Odd ",x);
	}

	return 0;
}
