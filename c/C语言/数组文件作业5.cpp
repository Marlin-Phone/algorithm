#include <stdio.h>

int main() {
    char input[1000]; 
    int count = 0;
    char c;

    printf("������һ���ַ�����\n");

    do {
        c = getchar();
        if (c != '!') {
            input[count] = c;
            count++;
        }
    } while (c != '!' && count < 999);

    input[count] = '\0';

    printf("��������ַ�����: %s\n", input);
    printf("�ַ�����: %d\n", count);

    return 0;
}

