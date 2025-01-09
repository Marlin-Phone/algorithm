#include <stdio.h>
#include <string.h>

struct Product {
    char name[100];
    float price;
    char production_date[20];
    int stock_quantity;
    char attributes[100];
};

int main() {

    struct Product products[3];

    for (int i = 0; i < 3; i++) {
        printf("�� %d ����Ʒ:\n", i + 1);
        printf("����: ");
        scanf("%s", products[i].name);
        printf("����: ");
        scanf("%f", &products[i].price);
        printf("��������: ");
        scanf("%s", products[i].production_date);
        printf("�������: ");
        scanf("%d", &products[i].stock_quantity);
        printf("��Ʒ����: ");
        scanf("%s", products[i].attributes);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (products[j].price < products[j + 1].price) {
                struct Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("\n�۸��ɸߵ�������Ϊ:\n");
    for (int i = 0; i < 3; i++) {
        printf("����: %s\n", products[i].name);
        printf("����: %.2f\n", products[i].price);
        printf("��������: %s\n", products[i].production_date);
        printf("�������: %d\n", products[i].stock_quantity);
        printf("��Ʒ����: %s\n\n", products[i].attributes);
    }

    return 0;
}

