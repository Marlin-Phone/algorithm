#include<stdio.h>
int main()
{
	printf("���мƷ�ϵͳ2023��1.1\n");
	printf("���ߣ������\n");
	int n1,n2,n3;
	float a,b,c;
	printf("�������һ����Ʒ��������");
	scanf("%d",&n1);
	printf("\n�������һ����Ʒ�ļ۸�");
	scanf("%f",&a);
	printf("\n������ڶ�����Ʒ��������");
	scanf("%d",&n2);
	printf("\n������ڶ�����Ʒ�ļ۸�");
	scanf("%f",&b);
	printf("\n�������������Ʒ��������");
	scanf("%d",&n3);
	printf("\n�������������Ʒ�ļ۸�");
	scanf("%f",&c);
	int num=n1+n2+n3;
	float money=n1*a+n2*b+n3*c;
	if(num==1){
		money=money;
	}
	else{
		if(num==2){
			money=0.95*money;
		}
		else{
			if(num<=5&&num>=3){
				money=0.9*money;
			}
			else{
				if(num>5){
					money=0.85*money;
				}
				else{
					printf("����");
				}
			}
		}
	}
	printf("��ã���Ӧ����%.2fԪ��",money);
	return 0;
}
