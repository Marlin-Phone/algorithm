#include<stdio.h>
int main()
{
	float a,b;
	char ch;
	printf("����������������:\n");
	scanf("%f%f",&a,&b);
	printf("����������֮����������:\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case '+': printf("a+b=%.2f",a+b); break;
		case '-': printf("a-b=%.2f",a-b); break;
		case '*': printf("a*b=%.2f",a*b); break;
		case '/': 
		{
			if(b!=0)
			{
				printf("a/b=%.2f",a/b); 
			} 
			else printf("����������������롣") ; 
		} break;
		default: printf("���������������롣");
	}
	return 0;
 } 
