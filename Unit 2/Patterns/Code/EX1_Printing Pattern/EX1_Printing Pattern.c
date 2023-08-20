/*
 ==========================================================================
 Name        : EX1_Printing Pattern.c
 Author      : Mohammed Hasan
 Created on	 : Aug 20, 2023
 Description : printing pattern
 ==========================================================================
 */

/*
	n = 3							 3 3 3 3 3
	size = 5						 3 2 2 2 3
	start = 0						 3 2 1 2 3
	end = 4							 3 2 2 2 3
								     3 3 3 3 3
 */

#include <stdio.h>

int main()
{
	int n ,i , j ,start ,end ,size;
	printf("Enter the number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d" , &n);

	size = 2*n - 1;
	start = 0;
	end = size - 1; //5

	int arr[size][size];

	while(n!=0)
	{
		for(i = start ; i <= end ;i++)
		{
			for(j = start ; j <=end ; j++)
			{
				if(i == start || i == end || j == start || j == end)
				{
					arr[i][j] = n;
				}
			}
		}
		++start;
		--end;
		--n;
	}

	for(i = 0 ; i< size ; i++ )
	{
		for(j = 0 ; j < size ; j++)
		{
			printf("%d " , arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

