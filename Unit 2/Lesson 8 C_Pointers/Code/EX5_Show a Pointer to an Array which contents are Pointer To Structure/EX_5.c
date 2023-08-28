/*
 ==============================================================================================
 Name        : EX_5.c
 Author      : Mohammed Hasan
 Created on	 : Aug 29, 2023
 Description : C Program To Show a Pointer to an Array which contents are Pointer To Structure
 ==============================================================================================
 */

#include <stdio.h>

struct SEmployee
{
	char* emp_name;
	int emp_ID;
};

int main()
{

	struct SEmployee emp1 = {"Mohammed",2100}, emp2 = {"Hasan",2200}, emp3 = {"Ahmed",2500};

	struct SEmployee *arr[]={&emp1,&emp2,&emp3};

	struct SEmployee*(*Ptr_arr)[3]= &arr;

	printf(" Employee Name : %s \n",(*(*Ptr_arr))->emp_name);
	printf(" Employee ID :  %d \n",(*(*Ptr_arr))->emp_ID);

	return 0;
}
