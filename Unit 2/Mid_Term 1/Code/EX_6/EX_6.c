/*
 * EX_6.c
 * ################################################################
 * #  C Function to return unique number in array with one loop   #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int unique_num(int a[],int size);

int main()
{
	int a[] = {4,2,5,2,5,7,4};
	int size = sizeof(a)/sizeof(a[0]);
	printf("unique number in this array is : %d" ,unique_num(a,size));

	return 0;
}
int unique_num(int a[],int size)
{
	int i,result = 0 ;
	for(i = 0 ; i <size ; i++)
	{
		result ^=a[i];
	}
	return result;
}
