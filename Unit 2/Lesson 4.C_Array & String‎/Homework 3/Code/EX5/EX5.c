/*
 * EX5.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int main()
{
	int nums[100];
	int n , element , i ,found = 0;

	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	for(i = 0;i < n ;i++)
	{
		scanf("%d",&nums[i]);
	}

	printf("Enter the elements to be searched : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&element);

	for(i = 0; i < n ; i++)
	{
		if(nums[i]==element)
		{
			found = 1;
			break;
		}
	}

	if(found == 1)
	{
		printf("Number found at the location = %d ",i+1);
	}
	else
	{
		printf("Number is not found in the array");
	}

	return 0;
}
