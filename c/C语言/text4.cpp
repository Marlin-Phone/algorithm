#include <stdio.h>

// �ݹ����쳲��������еĵ�n��
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("������쳲��������е����� n��");
    scanf("%d", &n);

    if (n < 0) {
        printf("������Ч��n ӦΪ�Ǹ�������\n");
    } else {
        int result = fibonacci(n);
        printf("쳲��������еĵ� %d ��Ϊ %d\n", n, result);
    }

    return 0;
}

