/*
 ==========================================================================
 Name        : EX_6.c
 Author      : Mohammed Hasan
 Created on	 : Aug 29, 2023
 Description : C Program To print Data of employees (pointer to structure)
 ==========================================================================
 */
#include <stdio.h>
#include <string.h>

struct Semployee
{
	char employee_name[50];
	int ID ;
};

int main()
{
	int i ;
	struct Semployee data[] = { {"Mohammed" , 1000} , {"Hasan" , 1100} , {"Ahmed" , 1200}};
	struct Semployee *ptr  ;
	ptr = data;

	for(i = 0 ; i<sizeof(data)/sizeof(struct Semployee) ; i++)
	{
		printf("Employee number %d :\n" , i+1);
		printf("Employee_name : %s\n" ,ptr->employee_name);
		printf("Employee_ID : %d\n" , ptr->ID);
		printf("=================================\n");
		ptr++;
	}
	return 0;
}

