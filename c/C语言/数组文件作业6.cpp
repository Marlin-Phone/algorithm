#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("word.txt", "r"); 
    if (file == NULL) {
        printf("�޷����ļ� 'word.txt'\n");
        return 1;
    }

    char c;
    int count = 0;

    while ((c = fgetc(file)) != EOF && c != '!') {
        count++;
    }

    fclose(file); 

    printf("���ļ��ж�ȡ���ַ����ַ�����: %d\n", count);

    return 0;
}

