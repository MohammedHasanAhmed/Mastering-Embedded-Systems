/*
 * EX_7.c
 * ################################################################
 * #     C Function sum numbers from 1 to 100 (without loop)      #
 * ################################################################
 *  Created on: Aug 11, 2023
 *      Author: Mohammed Hasan
 */

#include <stdio.h>

int sum_nums(int number);
int sum_nums2(int number);

int main()
{
	printf("========= with 1st fun =========\n");
	printf("sum1 = %d\n" , sum_nums(100));
	printf("========= with 2nd fun =========\n");
	printf("sum2 = %d\n" , sum_nums2(100));

	return 0;
}
int sum_nums(int number)
{
	static int sum = 0 ;
	if(number > 0)
	{
		sum_nums(number - 1);
		sum+=number;
	}
	return sum ;
}
int sum_nums2(int number)
{
	return (number*(number+1)) / 2 ;
}
