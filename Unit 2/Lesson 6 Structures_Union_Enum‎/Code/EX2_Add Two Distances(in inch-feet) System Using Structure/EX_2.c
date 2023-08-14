/*
 ===================================================================================
 Name        : EX_2.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program to Add Two Distances(in inch-feet) System Using Structure
 ===================================================================================
 */

#include <stdio.h>
struct Sdistance
{
	int m_feet ;
	float m_inch;
};
struct Sdistance add_2dis(struct Sdistance d1 , struct Sdistance d2);
int main()
{
	struct Sdistance d1 , d2,sum;

	printf("Enter information for 1st distance :\n");
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &d1.m_feet);

	printf("Enter inch : ");
	fflush(stdin);fflush(stdout);
	scanf("%f" , &d1.m_inch);
	printf("====================================\n");
	printf("Enter information for 2nd distance :\n");
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &d2.m_feet);

	printf("Enter inch : ");
	fflush(stdin);fflush(stdout);
	scanf("%f" , &d2.m_inch);

	sum = add_2dis(d1 ,d2);

	printf("Sum of distance = %d\'-%.2f\"" ,sum.m_feet , sum.m_inch);

	return 0;
}
struct Sdistance add_2dis(struct Sdistance d1 , struct Sdistance d2)
{
	struct Sdistance c ;
	c.m_feet = d1.m_feet + d2.m_feet ;
	c.m_inch = d1.m_inch + d2.m_inch;
	while(c.m_inch >=12)
	{
		c.m_feet++;
		c.m_inch-=12;
	}
	return c;
}
