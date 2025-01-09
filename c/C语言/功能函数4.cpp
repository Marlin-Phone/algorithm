#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    hanoi(n - 1, source, target, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, target);

    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int numDisks;

    printf("���������ӵ����� (n <= 10)��");
    scanf("%d", &numDisks);

    if (numDisks <= 10 && numDisks > 0) {
        printf("�ᶯ�������£�\n");
        hanoi(numDisks, 'A', 'B', 'C');
    } else {
        printf("����������������1��10֮�䣩��\n");
    }

    return 0;
}

