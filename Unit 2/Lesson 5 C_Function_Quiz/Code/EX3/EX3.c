/*
 * EX3.c
 * ==>> Swapping two Arrays With Different lengths <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int main()
{
	int arr1[10] , arr2[10] , temp[10] , i;
	printf("Enter the first Array : ");
	fflush(stdin);fflush(stdout);
	for(i = 0 ; i <10 ;i++)
	{
		scanf("%d", &arr1[i]);
	}

	printf("Enter the second Array : ");
	fflush(stdin);fflush(stdout);
	for(i = 0 ; i <5 ;i++)
	{
		scanf("%d", &arr2[i]);
	}
	printf("================================================\n");
	printf("Array Before Swapping :\n");
	printf("the first array is : ");
	for(i = 0 ; i <10 ;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\nthe second array is : ");
	for(i = 0 ; i <5 ;i++)
	{
		printf("%d ", arr2[i]);
	}

	//Swap between two arrays
	for(i = 0 ; i <10 ;i++)
	{
		temp[i] = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp[i];
	}

	printf("\n================================================\n");
	printf("Array After Swapping :\n");
	printf("the first Array is : ");

	for(i = 0 ; i <5 ;i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\nthe second Array is : ");
	for(i = 0 ; i <10 ;i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n================================================\n");
	return 0;
}
