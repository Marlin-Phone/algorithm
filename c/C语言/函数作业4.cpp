#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char sex;
    int age;
} people;

char* getlastname(char name[]) {
    int j = 0, i = 0;
    static char lastname[100];
    
    while (name[i] != ' ') {
        i++;
    }
    i++;
    while (name[i] != ' ') {
        lastname[j] = name[i];
        i++;
        j++;
    }

    lastname[j] = '\0'; 
    
    return lastname;
}

char getsex(char name[]) {
    char sex;
    int i = 0;

    while (name[i] != ' ') {
        i++;
    }
    i++;
    while (name[i] != ' ') {
        i++;
    }
    i++;
    sex = name[i];

    return sex;
}

int main() {
    char lastname[100];
    people pep;

    fgets(pep.name, sizeof(pep.name), stdin);
    char* lastname0 = getlastname(pep.name); 
    
    pep.sex = getsex(pep.name);
    
    if (pep.sex == 'M')
        printf("��ӭ%s�������й�", lastname0);
    else
        printf("��ӭ%sŮʿ���й�", pep.name);

    return 0;
}

