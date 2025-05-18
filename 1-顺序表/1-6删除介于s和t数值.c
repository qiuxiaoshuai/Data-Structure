#include <stdio.h>
#include <stdlib.h> // Ϊ�� exit()
#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int leng;
} List;

void printfList(List *L) {
    for(int i = 0; i < L->leng; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

void delList(List *L, int s, int t) {
    if (s >= 1 || s > t) {
        printf("����s �� t ��ֵ������Ӧ���� s < 1 �� s <= t��\n");
        exit(1);
    }
    if (L->leng == 0) {
        printf("����˳���Ϊ�գ��޷�ɾ����\n");
        exit(1);
    }

    int k = 0;  // k ��ʾ��ǰд��λ��
    for (int i = 0; i < L->leng; i++) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k++] = L->data[i];  // �������� [s, t] �����Ԫ��
        }
    }
    L->leng = k;

    printf("ɾ����˳���Ϊ��");
    printfList(L);
}

int main() {
    List L = {{-3, 0, 1, 2, 5, 6}, 6};

    int s = -1;
    int t = 1;

    delList(&L, s, t);  // ɾ��ֵ�� [-1, 1] �����Ԫ�أ����˵㣩
    return 0;
}
