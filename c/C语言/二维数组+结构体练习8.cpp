#include<stdio.h>

typedef struct 
{
	char name[100];
	char chuban[100];
	int year;
	int mon;
}bookinfo;

int main(){
	bookinfo book[4];
	int i; 
	
	for(i=0;i<4;i++){
		printf("�������%d����������������硢������ݡ��۸�\n",i+1);
		scanf("%s%s%d%d",&book[i].name,&book[i].chuban,&book[i].year,&book[i].mon);
	}
	
	printf("������ݴ���2020�������ϢΪ��\n"); 
	for(i=0;i<4;i++){
		if(book[i].year>2020){
			printf("%s %s %d %d\n",book[i].name,book[i].chuban,book[i].year,book[i].mon);
		}
	}
	
	return 0;
}
