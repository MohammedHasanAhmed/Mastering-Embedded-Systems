//C Program to Check Vowel or Consonant 
#include <stdio.h>

int main()
{
	char ch;

	printf("Enter an alphabet: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&ch);

	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
	      ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
	{
		printf("%c is Vowel",ch);
	}
	else{
		printf("%c is Consonant",ch);
	}
	return 0;
}
