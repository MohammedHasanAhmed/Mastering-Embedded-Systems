/*
 =========================================================================
 Name        : EX_4.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program To Store Information of Students Using Structure
 =========================================================================
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
	struct Sstudents s[5];
	int i = 0 ;
	printf("Enter information of students\n\n");

	for(i = 0 ; i< 5 ;i++)
	{
		printf("for roll number %d\n",i+1);

		printf("Enter name : ");
		fflush(stdin);fflush(stdout);
		scanf("%s" , s[i].m_name);

		printf("Enter marks : ");
		fflush(stdin);fflush(stdout);
		scanf("%lf" , &s[i].m_marks);
		printf("=================================\n");

	}
	printf("=================================\n");
	printf("Displaying information of students :\n\n");
	for(i = 0 ; i < 5 ;i++)
	{
		printf("information for roll number %d :\n" ,i+1);
		printf("name : %s\n" , s[i].m_name);
		printf("marks : %.2lf\n",s[i].m_marks);
		printf("=================================\n");

	}
	return 0;
}
