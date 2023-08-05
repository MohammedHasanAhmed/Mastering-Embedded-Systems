/*
 * EX6.c
 * ==>> print the last occurrence of number <<==
 *  Created on: Aug 5, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int Last_occurrence(int arr[] , int size);
int main()
{
	int i , arr[100] , size ;
	printf("Enter size of Array : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &size);

	for(i = 0 ; i < size ; i++)
	{
		printf("Enter element number %d : " , i+1);
		fflush(stdout);
		scanf("%d", &arr[i]);
	}

	printf("Last occurrence is : %d",Last_occurrence(arr , size));

	return 0;
}
int Last_occurrence(int arr[] , int size)
{
	int i , Get_Key ;

	printf("Enter the number you want to get its last occurrence : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &Get_Key);

	for(i = size ; i > 0 ; i--)
	{
		if(arr[i] == Get_Key)
		{
			return i+1;
		}
	}

	return -1 ;
}
