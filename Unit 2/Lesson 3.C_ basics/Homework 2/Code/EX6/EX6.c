//C Program to Calculate Sum of Natural Numbers
#include <stdio.h>

int main()
{
	int n;
	int sum=0;

	printf("Enter an integer: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	for(int i=0;i<=n;i++)
	{
		sum+=i;
	}
	printf("Sum = %d",sum);

	return 0;
}
