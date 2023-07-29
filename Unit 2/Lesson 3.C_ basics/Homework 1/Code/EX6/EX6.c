//Source Code to Swap Two Numbers 
#include <stdio.h>

int main() {
    float a, b, temp;

    printf("Enter value of a: ");
    fflush(stdout);fflush(stdin);
    scanf("%f", &a);

    printf("Enter value of b: ");
    fflush(stdout);fflush(stdin);
    scanf("%f", &b);

    // swapping logic using temp variable
    temp = a;
    a = b;
    b = temp;

    printf("After swapping, value of a = %.2f\n", a);
    printf("After swapping, value of b = %.2f\n", b);

    return 0;
}
