//Source Code to Swap Two Numbers without temp variable 
#include <stdio.h>

int main()
{
	float a,b;

    printf("Enter value of a: ");
    fflush(stdout);fflush(stdin);
    scanf("%f", &a);

    printf("Enter value of b: ");
    fflush(stdout);fflush(stdin);
    scanf("%f", &b);
    // swapping logic without temp variable.
    a+=b;
    b=a-b;
    a=a-b;

    printf("After swapping, value of a = %.2f\n", a);
    printf("After swapping, value of b = %.2f\n", b);

	return 0;
}
