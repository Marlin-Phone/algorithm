#include<stdio.h>
int main(){
	static int a[5],b[5];
	int i=0;
	
	printf("������5����ֵ��");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("��������5����ֵ��");
	for(i=0;i<5;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<5;i++){
		b[i]=b[i]+a[i];
		printf("%d ",b[i]);
	}
	return 0;
} 
