#include <stdio.h>
#include <string.h>

char *fun(char *s, char *t) {
    int j = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (i % 2 == 0) {
            t[j] = s[i]; 
            j++; 
        }
    }

    t[j] = '\0'; 
    return t;}

int main() {
    char s[100];
    printf("\n�������ַ��� S: ");
    gets(s);

    char t[100]; 
    printf("\n�����: %s\n", fun(s, t));

    return 0;
}

