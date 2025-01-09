#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char publisher[50];
    float price;
};

void inputBooks(struct Book *books, int numBooks);
void printBooks(struct Book *books, int numBooks);
void findAndModifyBook(struct Book *books, int numBooks, const char *title, const char *newPublisher, float newPrice);

int main() {
    const int numBooks = 5;
    struct Book books[numBooks];

    struct Book *booksPtr = books;

    inputBooks(booksPtr, numBooks);

    printf("ԭʼͼ����Ϣ��\n");
    printBooks(booksPtr, numBooks);

    findAndModifyBook(booksPtr, numBooks, "C language", "SUST", 39.6);

    printf("\n�޸ĺ��ͼ����Ϣ��\n");
    printBooks(booksPtr, numBooks);

    return 0;
}

void inputBooks(struct Book *books, int numBooks) {
    for (int i = 0; i < numBooks; ++i) {
        printf("�������%d�������Ϣ��\n", i + 1);
        printf("������");
        scanf("%s", (books + i)->title);
        printf("�����磺");
        scanf("%s", (books + i)->publisher);
        printf("�۸�");
        scanf("%f", &(books + i)->price);
    }
}

void printBooks(struct Book *books, int numBooks) {
    for (int i = 0; i < numBooks; ++i) {
        printf("������%s\t�����磺%s\t�۸�%.2f\n", (books + i)->title, (books + i)->publisher, (books + i)->price);
    }
}

void findAndModifyBook(struct Book *books, int numBooks, const char *title, const char *newPublisher, float newPrice) {
    for (int i = 0; i < numBooks; ++i) {
        if (strstr((books + i)->title, title) != NULL) {
            strcpy((books + i)->publisher, newPublisher);
            (books + i)->price = newPrice;
            printf("���ҵ��������� %s ��ͼ�飬������ͼ۸����޸ġ�\n", title);
            return;
        }
    }
    printf("δ�ҵ��������� %s ��ͼ�顣\n", title);
}

