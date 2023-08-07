/*
 * EX4.c
 * ==>> Insert an Element in an Array <<==
 *  Created on: Jul 20, 2023
 *      Author: Mohammed Hasan
 */
#include <stdio.h>

int main()
{
	int nums[100];
	int n ,element , loc ,i;

	printf("Enter n of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	for(i = 0; i < n;i++)
	{
		scanf("%d",&nums[i]);
	}

	printf("Enter the element to be inserted : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &element);

	printf("Enter the location : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &loc);
	for(i = 0 ;i < n ;i++)
	{
		if(loc == i+1)
		{
			nums[i] = element;
		}
		printf("%d\t" , nums[i]);
	}
	return 0;
}


