#include<stdio.h>
int main(){
	printf("������10������:");
	static int num[10];
	int i,s,j;
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	} 
	for(i=1;i<10;i++){
		for(j=0;j<10-i;j++){
			if(num[j]<num[j+1]){
				s=num[j];
				num[j]=num[j+1];
				num[j+1]=s;
			}
		}
	}
	printf("��Щ�����ɴ�С����Ϊ��"); 
	for(i=0;i<10;i++){
		printf("%d ",num[i]);
	}
	return 0;
} 
