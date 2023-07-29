//C Program to Add Two Integers number 

#include <stdio.h>

int main()
{
	int num1,num2;
	int sum;

	printf("Enter two integers : ");
	fflush(stdout);fflush(stdin);

	scanf("%d %d",&num1,&num2);

	sum = num1+num2;
	printf("sum: %d",sum);

	return 0;
}
