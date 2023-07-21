/*
 * EX3.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Mohammed Hasan
 */
#include <stdio.h>

int main()
{
	int nums[20][20] , transpose[20][20];
	int i,j,r,c;

	printf("Enter Rows And Columns Of Matrix : ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d", &r,&c);

	printf("Enter The Elements Of Matrix :\n");
	for(i = 0; i < r;i++ )
	{
		for(j = 0; j < c;j++)
		{
			printf("Enter Element a%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&nums[i][j]);
		}
	}

	printf("===============\n");
	printf("Entered Matrix :\n");
	for(i = 0; i < r;i++ )
	{
		for(j = 0; j < c;j++)
		{
			printf("%d\t",nums[i][j]);
		}
		printf("\n");
	}

	printf("===================\n");
	printf("Transpose Of Matrix :\n");
	for(i = 0; i < r;i++ )
	{
		for(j = 0; j < c;j++)
		{
			transpose[j][i] = nums[i][j];
		}
	}

	for(i = 0; i < c;i++ )
	{
		for(j = 0; j < r;j++)
		{
			printf("%d\t",transpose[i][j]);
		}
		printf("\n");
	}
	return 0;
}
