#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 10

char* findLongestString(char *strings[], int numStrings);

int main() {
    char buffer[ROWS][COLS];
    char *strings[ROWS];

    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "�޷����ļ� in.txt\n");
        return 1;
    }

    for (int i = 0; i < ROWS; ++i) {
        if (fscanf(file, "%s", buffer[i]) != 1) {
            fprintf(stderr, "��ȡ�ļ�ʧ��\n");
            fclose(file);
            return 1;
        }

        strings[i] = buffer[i];
    }

    fclose(file);

    char *longestString = findLongestString(strings, ROWS);

    printf("\n��ַ����ǣ�%s\n", longestString);

    return 0;
}

char* findLongestString(char *strings[], int numStrings) {
    char *longest = strings[0];

    for (int i = 1; i < numStrings; ++i) {
        if (strlen(strings[i]) > strlen(longest)) {
            longest = strings[i];
        }
    }

    return longest;
}

