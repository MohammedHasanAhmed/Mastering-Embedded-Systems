/*
 * EX4.c
 * ==>> Reverse an input Array <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

void rev(int arr[],int size);
int main()
{
	int size ,i ;
	int arr[100];

	printf("Enter the size of an array : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);

	for(i = 0 ; i < size ; i++)
	{
		printf("Enter element number %d : ",i+1);
		fflush(stdout);
		scanf("%d" , &arr[i]);
	}
	rev(arr , size);

	return 0;
}
void rev(int arr[],int size)
{
	int i;
	printf("Reverse Array is ==> ");
	for(i = size-1 ; i >= 0 ;i--)
	{
		printf("%d " , arr[i]);
	}

}
