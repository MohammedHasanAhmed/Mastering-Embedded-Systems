/*
 ==========================================================================
 Name        : EX_1.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program to store information of a student Using Structure
 ==========================================================================
 */
#include <stdio.h>

struct Sstudents
{
	char m_name[50];
	int m_roll;
	double m_marks;
};

int main()
{
	struct Sstudents s;
	printf("Enter information of students :\n\n");

	printf("Enter name : ");
	fflush(stdin);fflush(stdout);
	fgets(s.m_name , 50 , stdin);

	printf("Enter roll number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &s.m_roll);

	printf("Enter marks : ");
	fflush(stdin);fflush(stdout);
	scanf("%lf" , &s.m_marks);
	printf("=================================\n");
	printf("Displaying information :\n");

	printf("name : %s", s.m_name);
	printf("roll : %d\n", s.m_roll);
	printf("marks : %.2lf\n", s.m_marks);

	return 0;
}
