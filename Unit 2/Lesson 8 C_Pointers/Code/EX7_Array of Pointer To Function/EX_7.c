/*
 ==========================================================================
 Name        : EX_7.c
 Author      : Mohammed Hasan
 Created on	 : Aug 29, 2023
 Description : C Program ==> Array of Pointer To Function
 ==========================================================================
 */
#include <stdio.h>

int add_num(int x,int y)
{
	return (x+y);
}
int sub_num(int x,int y)
{
	return (x-y);
}
int mul_num(int x,int y)
{
	return (x*y);
}

int main()
{
	int num1 , num2 , choice;
	int (*ptr[3])(int , int) = {add_num , sub_num , mul_num };
	printf("Enter choice 0 for Add and 1 for Sub and 2 for Mul : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &choice);

	printf("Enter number 1 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num1);

	printf("Enter number 2 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &num2);

	int ret = (*ptr[choice])(num1 , num2);

	printf("ret = %d\n" , ret);

	return 0;
}
