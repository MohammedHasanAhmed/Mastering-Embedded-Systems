/*
 ===============================================================
 Name        : EX_6.c
 Author      : Mohammed Hasan
 Created on	 : Aug 14, 2023
 Description : C Program to Calculate Size of Structure & Union
 ===============================================================
 */

#include <stdio.h>

union UNUMjob
{
	char name[32];
	float salary ;
	int worker_no;
}u;

struct Sjob1
{
	char name [32];
	float salary ;
	int worker_no;

}s;
int main()
{
	printf("size of Union = %d\n",sizeof(u)); // size ==>> 32
	printf("size of structure = %d",sizeof(s)); //size ==>> 40
	return 0;
}
