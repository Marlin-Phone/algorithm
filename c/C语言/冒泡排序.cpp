#include <stdio.h>

int main() {
    printf("������10������");
    static float num[10];
    int i;
    
    for (i = 0; i < 10; i++) {
        scanf("%f", &num[i]);
    }
    
    for (i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (num[j] > num[j + 1]) {
                // ʹ�üӼ���������ɽ�������
                num[j] = num[j] + num[j + 1];
                num[j + 1] = num[j] - num[j + 1];
                num[j] = num[j] - num[j + 1];
            }
        }
    }
    
    for (i = 0; i < 10; i++) {
        printf("%.2f ", num[i]);
    }
    
    return 0;
}

