#include<stdio.h>

int main(){
	int i,num=5,num0,count;
	
	printf("��һ����100���ڵ����֣�");
	
	do{
		scanf("%d",&num0);
		count++;
		if(num0==num){
			printf("����%d�β�����",count);
		}
		else if(num0>num){
			printf("�´���");
		}
		else if(num0<num){
			printf("��С��");
		} 
	}while(num0!=num);
	
	return 0;
} 
