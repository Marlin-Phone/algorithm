#include <stdio.h>

int main() {
    static int score[3][4];
    int i, j, total = 0;

    printf("������3��ѧ����ÿ�ſεĳɼ���\n");
    
    // ��ȡ�ɼ�
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &score[i][j]);
        }
    }

    // �����ܷ�
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            total += score[i][j];
        }
    }

    // ����ƽ����
    double average = total / (3.0 * 4.0); // 3 students, 4 subjects

    printf("�ܷ֣�%d\n", total);
    printf("ÿ�ſγ�ƽ���֣�%.2lf\n", average);

    return 0;
}

