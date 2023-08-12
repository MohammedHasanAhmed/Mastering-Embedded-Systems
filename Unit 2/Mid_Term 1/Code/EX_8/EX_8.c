/*
 * EX_8.c
 * ################################################################
 * #    C Function to take An Array and  Reverse its elements     #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

void rev(int arr[],int size);

int main()
{
	int arr[5],i;
	printf("Enter the Elements of Array[5] : ");
	fflush(stdin);fflush(stdout);
	for(i = 0 ; i < 5 ; i++ )
	{
		scanf("%d" , &arr[i]);
	}

	printf("Entered Array are : ");
	for(i = 0 ; i < 5 ; i++ )
	{
		printf("%d " , arr[i]);
	}

	printf("\nReverse Array : ");
	rev(arr,5);

	return 0;
}

void rev(int arr[],int size)
{
	int i = 0;
	for(i = size-1 ; i >=0 ; i--)
	{
		printf("%d ",arr[i]);
	}
}
