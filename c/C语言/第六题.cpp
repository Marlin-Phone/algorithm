#include<stdio.h>
int main() 
{
	printf("���мƷ�ϵͳ2023��\n���ߣ������\n");
	int num;
	printf("��������Ʒ��������");
	scanf("%d",&num);
	double rmb;
	printf("��������Ʒ�ļ۸�");
	scanf("%lf",&rmb);
	double z;
	printf("��������Ʒ���۵Ķ�ȣ�");
	scanf("%lf",&z);
	double f;
	f=num*rmb*z;
	printf("��ã�������Ʒ��Ӧ����%.3lf",f); 
	return 0;
	
 } 
