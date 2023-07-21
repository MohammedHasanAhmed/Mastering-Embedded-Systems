//C Program to Multiply two Floating Point Numbers

#include <stdio.h>

int main()
{
	float num1,num2;
	float mul;

	printf("Enter two numbers : ");
	fflush(stdout);fflush(stdin);

	scanf("%f %f",&num1,&num2);

	mul = num1 * num2;
	printf("Product: %f",mul);


	return 0;
}
