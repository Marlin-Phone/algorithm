#include <stdio.h>

int main()
{
    float length, width;
    float perimeter, area;

    printf("�����볤���εĳ��ȣ�");
    scanf("%f", &length);

    printf("�����볤���εĿ�ȣ�");
    scanf("%f", &width);

    perimeter = 2 * (length + width);
    area = length * width;

    printf("�����ε��ܳ��ǣ�%.2f\n", perimeter);
    printf("�����ε�����ǣ�%.2f\n", area);

    return 0;
}

