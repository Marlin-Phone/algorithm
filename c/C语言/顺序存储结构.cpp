//˳��洢�ṹ�Ĳ�����ɾ�� 
#include<stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status; 
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList; 

SqList L;

//���Ԫ�ز��� 
Status GetElem(SqList L,int i,ElemType *e){
	if(L.length  == 0 || i<1 || i>L.length){
		return ERROR;
	}
	*e=L.data[i-1];
	
	return OK;
}

//����Ԫ�ز���
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length ==MAXSIZE){
		return ERROR;
	}
	if(i<1||i>L->length + 1){
		return ERROR;
	}
	if(i<=L->length){
		for(k=L->length-1;k>=i-1;k--){
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;
	L->length++;
} 

int main(void){
	int e;
	
	printf("��������Ҫ���������:");
	scanf("%d",&e);
	
	Status GetElem(L,e);
	
	
	
} 
