#include<stdio.h>
int main() {
	printf("�������㽫�������ֵĸ���(������10��)��");
	int i,n;
	scanf("%d",&n);
	if (n>10||n<0){
		printf("�������");
		return 1;
	}
	printf("������%d�����֣�",n);
	float a[10]; 
	for(i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	float max=a[0],min=a[0];
	for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	}
	printf("max=%.2f,min=%.2f",max,min);
	return 0;
}
