#include<stdio.h>

int main(){
	FILE *fp;
	float scores[4][4];
	int i,j;
	
	printf("������3��ѧ����ѧ�ż�ÿ�ſγɼ���\n");
	printf("==================================\n");
	printf("ѧ��    Ӣ��     ����     C����\n");
	
	fp=fopen("ѧ���ɼ�.txt","r");
	
	if (fp == NULL) {
        printf("�޷����ļ�\n");
        return 1;
    }
    
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			fscanf(fp,"%f",&scores[i][j]);
		}
	}
	
	fclose(fp);
	
	
	for(j=1;j<4;j++){
		for(i=0;i<3;i++){
			scores[3][j]+=scores[i][j];
		}
		scores[3][j]/=3; 
	}
	
	printf("==================================\n");
	printf("ƽ����:   ");
	for(j=1;j<4;j++){
		printf("%.1f\t",scores[3][j]);
	}
	 
	return 0;
} 
