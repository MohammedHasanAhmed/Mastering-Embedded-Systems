//C Program to Find the Largest Number Among Three Numbers 
#include <stdio.h>

int main()
{
	float a,b,c;

	printf("Enter three numbers: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);

	if(a>b)
	{
		if(a>c)
			printf("Largest number = %f",a);
	}
	else if(b>c)
	{
		printf("Largest number = %.2f",b);
	}
	else
	{
		printf("Largest number = %f",c);
	}

	return 0;
}
