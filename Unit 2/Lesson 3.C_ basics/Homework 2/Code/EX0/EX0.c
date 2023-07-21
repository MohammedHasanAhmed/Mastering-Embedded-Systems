/*
* main.c
 *
 *  Created on: Jul 18, 2023
 *      Author: mohammed_hasan
 */
#include <stdio.h>

int main()
{
	int i;
	float student[10];

	for(i = 0; i < 10;i++)
	{
		printf("Enter Student %d degree : ", i+1);
		fflush(stdin);fflush(stdout);
		scanf("%.2f " , &student[i]);
	}
	for(i= 0 ; i < 10;i++)
	{
		printf("Student %d degree is : %f \n" , i+1,student[i]);
	}
	return 0 ;
}
