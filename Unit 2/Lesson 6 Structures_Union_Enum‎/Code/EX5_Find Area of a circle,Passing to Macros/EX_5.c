/*
 ====================================================================
 Name        : EX_5.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program To Find Area of a circle, Passing to Macros
 ====================================================================
 */

#include <stdio.h>

#define Pi 3.14
#define Area(r)(Pi *(r) *(r))

int main()
{
	int radius;
	printf("Enter the radius : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &radius);

	printf("Area = %.2f" , Area(radius));

	return 0;
}
