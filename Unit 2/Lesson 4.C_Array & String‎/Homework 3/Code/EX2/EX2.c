/*
 * EX2.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int main()
{
	float nums[100];
	float sum = 0.0 , average = 0.0;
	int i,n;

	printf("Enter The Numbers Of Data : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	for(i = 0;i < n;i++)
	{
		printf("%d. Enter Number : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&nums[i]);
		sum += nums[i];
	}
	average = sum / n ;
	printf("Sum = %.2f\n",sum);
	printf("Average = %.2f" , average);
	return 0;
}

