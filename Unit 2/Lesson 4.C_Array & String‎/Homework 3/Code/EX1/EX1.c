/*
 * EX1.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int main()
{
	float a[2][2];
	float b[2][2];
	float sum[2][2];
	int r,c ;

	printf("Enter The Elements Of 1st Matrix :\n");

	for(r = 0;r < 2; r++)
	{
		for(c = 0;c < 2; c++)
		{
			printf("Enter a%d%d : ",r+1,c+1);
			fflush(stdin);fflush(stdout);
			scanf("%f", &a[r][c]);
		}
	}
	printf("=================================\n");
	printf("Enter The Elements Of 2nd Matrix :\n");

	for(r = 0;r < 2; r++)
	{
		for(c = 0;c < 2; c++)
		{
			printf("Enter a%d%d : ",r+1,c+1);
			fflush(stdin);fflush(stdout);
			scanf("%f", &b[r][c]);
		}
	}
	printf("=================================\n");
	printf("Sum Of Matrix :\n");
	for(r = 0;r < 2; r++)
	{
		for(c = 0;c < 2; c++)
		{
			sum[r][c] = a[r][c] + b[r][c];
			printf("%.1f\t",sum[r][c]);
		}
		printf("\n");
	}
	return 0;
}


