#include<stdio.h>

int main(){
	float scores[4][3]; // �޸������С
	int i,j;
	
	printf("������3��ѧ����ѧ�ż�ÿ�ſγɼ���\n");
	printf("==================================\n");
	printf("ѧ��    Ӣ��     ����     C����\n");
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){ // �޸�ѭ���߽�
			scanf("%f",&scores[i][j]);
		}
		printf("\n");
	}
	
	for(j=0;j<3;j++){ // �޸�ѭ���߽�
		for(i=0;i<3;i++){
			scores[3][j]+=scores[i][j];
		}
		scores[3][j] /= 3; // ����ƽ����
	}
	
	printf("==================================\n");
	printf("ƽ����:   ");
	for(j=0;j<3;j++){ // �޸�ѭ���߽�
		printf("%.1f    ",scores[3][j]);
	}
	 
	return 0;
}

