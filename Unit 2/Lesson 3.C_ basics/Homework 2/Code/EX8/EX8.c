//C Program to Make a Simple Calculator to Add, Subtract, Multiply or Divide Using switch...case 
#include <stdio.h>

int main(){

	char operator;
	//the two operands is x,y
	float x,y;
	float add,sub,mul,div;

	printf("Enter operator either + or - or * or divide : ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&operator);

	printf("Enter two operands: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&x,&y);

	switch(operator)
	{
	case '+':
	{
		add=x+y;
		printf("%.2f %c %.2f = %.2f ",x,operator,y,add);
		break;
	}
	case '-':
	{
		sub=x-y;
		printf("%.2f %c %.2f = %.2f",x,operator,y,sub);
		break;
	}
	case '*':
	{
		mul=x*y;
		printf("%.2f %c %.2f = %.2f",x,operator,y,mul);
		break;
	}
	case '/':
	{
		div=x/y;
		printf("%.2f %c %.2f = %.2f",x,operator,y,div);
		break;
	}
    default:
        printf("Error: Invalid operator");
        break;

	}
	return 0;
}
