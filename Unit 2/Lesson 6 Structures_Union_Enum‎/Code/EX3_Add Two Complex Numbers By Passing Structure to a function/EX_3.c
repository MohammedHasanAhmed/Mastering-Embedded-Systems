/*
 ======================================================================================
 Name        : EX_3.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program to Add Two Complex Numbers By Passing Structure to a function
 ======================================================================================
 */

#include <stdio.h>

struct Scomplex
{
	double m_R;
	double m_I;
};
struct Scomplex add_com(struct Scomplex num1 , struct Scomplex num2);
int main()
{
	struct Scomplex num1 , num2 , sum ;
	printf("Enter 1st complex number\n");

	printf("Enter real & imaginary part respectively : ");
	fflush(stdin);fflush(stdout);
	scanf("%lf %lf" , &num1.m_R , &num1.m_I);

	printf("===============================\n");

	printf("Enter 2nd complex number\n");
	printf("Enter real & imaginary part respectively : ");
	fflush(stdin);fflush(stdout);
	scanf("%lf %lf" , &num2.m_R , &num2.m_I);

	sum = add_com(num1 ,num2);

	printf("Sum = %.2lf + %.2lfi" ,sum.m_R , sum.m_I);

	return 0;
}
struct Scomplex add_com(struct Scomplex num1 , struct Scomplex num2)
{
	struct Scomplex c ;
	c.m_R = num1.m_R + num2.m_R;
	c.m_I = num1.m_I + num2.m_I;
	return c;
}
