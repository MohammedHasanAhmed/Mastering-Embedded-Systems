//C Program to Check Whether a Number is Positive or Negative or Zero 
#include <stdio.h>

int main()
{
	float num;

	printf("Enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num);

	if(num == 0)
	{
		printf("You entered zero ");
	}
	else if(num>0)
	{
		printf("%.2f is positive ",num);
	}
	else
	{
		printf("%.2f is Negative ",num);
	}

	return 0;
}
