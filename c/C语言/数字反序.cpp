

#include <stdio.h>

int main()
{
    printf("������һ��������0~99999����");
    int num, a, b, c, d, e;
    scanf("%d", &num);
    
    a = num / 10000;
    b = num % 10000 / 1000;
    c = num % 1000 / 100;
    d = num % 100 / 10;
    e = num % 10;
    
    if (a != 0)
        printf("������λ��\n");
    else if (b != 0)
        printf("������λ��\n");
    else if (c != 0)
        printf("������λ��\n");
    else if (d != 0)
        printf("������λ��\n");
    else if (e != 0)
        printf("����һλ��\n");
        
    printf("%d,%d,%d,%d,%d\n", a, b, c, d, e);
    printf("��������Ϊ��%d%d%d%d%d\n", e, d, c, b, a);
    
    return 0;
}

