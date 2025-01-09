#include <stdio.h>
#include <ctype.h> 

int main() {
    FILE *file;
    file = fopen("in.txt", "r"); 

    if (file == NULL) {
        printf("�޷����ļ� 'in.txt'\n");
        return 1;
    }

    char word[100]; 
    int wordCount = 0;
    int inWord = 0; 

    int c;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            word[inWord] = c;
            inWord = 1;
        } else if (inWord) {
            word[inWord] = '\0'; 
            wordCount++;
            inWord = 0;
        }
    }

    fclose(file);

    printf("�ı��е�Ӣ�ﵥ����: %d\n", wordCount);

    return 0;
}

