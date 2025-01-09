#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_STRING_LENGTH 100

struct Book {
    char title[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    float price;
};

void readBooksFromFile(struct Book books[]) {
    FILE *file = fopen("books.txt", "r");

    if (file == NULL) {
        printf("�ļ���ʧ�ܡ�\n");
        return;
    }

    for (int i = 0; i < MAX_BOOKS; ++i) {
        fscanf(file, "%s %s %f", books[i].title, books[i].author, &books[i].price);
    }

    fclose(file);
}

void writeBooksToFile(const struct Book books[]) {
    FILE *file = fopen("books.txt", "w");

    if (file == NULL) {
        printf("�ļ���ʧ�ܡ�\n");
        return;
    }

    for (int i = 0; i < MAX_BOOKS; ++i) {
        fprintf(file, "%s %s %.2f\n", books[i].title, books[i].author, books[i].price);
    }

    fclose(file);
}

void addBook(struct Book books[], int index) {
    printf("����������ͼ����Ϣ��\n");
    printf("������");
    scanf("%s", books[index].title);
    printf("���ߣ�");
    scanf("%s", books[index].author);
    printf("���ۣ�");
    scanf("%f", &books[index].price);
}

void modifyBook(struct Book books[], int index) {
    printf("�������޸ĺ��ͼ����Ϣ��\n");
    printf("��������");
    scanf("%s", books[index].title);
    printf("�����ߣ�");
    scanf("%s", books[index].author);
    printf("�¶��ۣ�");
    scanf("%f", &books[index].price);
}

int main() {
    struct Book books[MAX_BOOKS];
    int choice, index;

    readBooksFromFile(books);

    printf("1. ����ͼ����Ϣ\n");
    printf("2. �޸�ͼ����Ϣ\n");
    printf("��ѡ�������1��2����");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("����������ͼ���������0-%d����", MAX_BOOKS - 1);
            scanf("%d", &index);
            if (index >= 0 && index < MAX_BOOKS) {
                addBook(books, index);
            } else {
                printf("����������Χ��\n");
            }
            break;
        case 2:
            printf("������Ҫ�޸ĵ�ͼ���������0-%d����", MAX_BOOKS - 1);
            scanf("%d", &index);
            if (index >= 0 && index < MAX_BOOKS) {
                modifyBook(books, index);
            } else {
                printf("����������Χ��\n");
            }
            break;
        default:
            printf("��Ч��ѡ��\n");
            break;
    }

    writeBooksToFile(books);

    return 0;
}

