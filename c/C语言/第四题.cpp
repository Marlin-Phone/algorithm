#include<stdio.h>
int main()
{
	printf("����������һ����λ����");
	int num,a,b,c;
	scanf("%d",&num);
	a=num/100;
	b=num%100/10;
	c=num%10;
	printf("����λ����λ���ϵĺ�Ϊ��%d",a+b+c);
	return 0;
	
 } 
