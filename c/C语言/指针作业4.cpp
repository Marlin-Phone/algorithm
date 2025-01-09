 #include <stdio.h>
#include <string.h>

char* findShortestString(char (*strings)[10], int numStrings);

int main() {
    char strings[5][10];

    printf("������5���ַ�����ÿ���ַ������Ȳ�����10����\n");
    for (int i = 0; i < 5; ++i) {
        printf("�ַ��� %d��", i + 1);
        scanf("%s", strings[i]);
    }

    char *shortestString = findShortestString(strings, 5);

    printf("\n����ַ����ǣ�%s\n", shortestString);

    return 0;
}

char* findShortestString(char (*strings)[10], int numStrings) {
    char *shortest = strings[0];

    for (int i = 1; i < numStrings; ++i) {
        if (strlen(strings[i]) < strlen(shortest)) {
            shortest = strings[i];
        }
    }

    return shortest;
}

