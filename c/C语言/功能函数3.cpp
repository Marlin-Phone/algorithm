#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    printf("�������һ����������");
    scanf("%d", &num1);
    printf("������ڶ�����������");
    scanf("%d", &num2);

    int result_gcd = gcd(num1, num2);
    printf("���Լ���ǣ�%d\n", result_gcd);

    int result_lcm = lcm(num1, num2);
    printf("��С�������ǣ�%d\n", result_lcm);

    return 0;
}

