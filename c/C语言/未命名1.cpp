#include<stdio.h>

int main() {
    FILE *fp;
    float scores[3][4]; // 3��ѧ����ÿ�ſγ�+ѧ��
    int i, j;
    
    printf("������3��ѧ����ѧ�ż�ÿ�ſγɼ���\n");
    printf("==================================\n");
    printf("ѧ��    Ӣ��     ����     C����\n");
    
    fp = fopen("ѧ���ɼ�.txt", "r"); // �����ļ���
    
    if (fp == NULL) {
        printf("�޷����ļ�\n");
        return 1;
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) { // ����ѭ���߽�
            fscanf(fp, "%f", &scores[i][j]);
        }
    }
    
    fclose(fp);
    
    for (j = 1; j < 4; j++) { // �޸�ѭ���߽�
        for (i = 0; i < 3; i++) {
            scores[3][j] += scores[i][j]; // �ۼ�ÿ�ſγ̵��ܷ�
        }
        scores[3][j] /= 3.0; // ����ƽ����
    }
    
    printf("==================================\n");
    printf("ƽ����:   ");
    for (j = 1; j < 4; j++) { // �޸�ѭ���߽�
        printf("%.1f    ", scores[3][j]);
    }
    
    return 0;
}

