#include <stdio.h>

void fun(char s[], char c) {
    int i, k = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[k] = s[i];
            k++;
        }
    }
    s[k] = '\0'; // ȷ�����ַ�����ĩβ��ӿ��ַ�
}

int main() {
    char str[20], ch;
    printf("������һ���ַ�����");
    gets(str);
    printf("������Ҫɾ�����ַ���");
    ch = getchar();
    fun(str, ch);
    printf("ɾ������ַ���Ϊ: %s\n", str);
    return 0;
}

