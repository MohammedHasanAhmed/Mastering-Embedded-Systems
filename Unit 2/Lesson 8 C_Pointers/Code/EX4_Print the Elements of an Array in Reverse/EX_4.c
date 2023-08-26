/*
 ===========================================================================
 Name        : EX_4.c
 Author      : Mohammed Hasan
 Created on	 : Aug 26, 2023
 Description : C Program To Print the Elements of an Array in Reverse order
 ===========================================================================
 */


#include <stdio.h>

int main()
{
	int n , i;
	printf("Input the number of elements to store in the array : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &n);

	char nums[n];
	char *ptr = nums;
	printf("Input %d number of elements in the array :\n",n);
	for(i = 0 ; i < n ; i++)
	{
		printf("element_%d : " , i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d" ,(int*)ptr);
		++ptr;
	}

	ptr = &nums[n-1];

	printf("The elements of Array in reverse order are :\n");
	for(i = n-1 ; i >=0 ; i--)
	{
		printf("element_%d : %d\n" , i+1 , *ptr--);
	}
	return 0;
}
