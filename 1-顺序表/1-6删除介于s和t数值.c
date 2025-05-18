#include <stdio.h>
#include <stdlib.h> // 为了 exit()
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
        printf("错误：s 和 t 的值不合理，应满足 s < 1 且 s <= t。\n");
        exit(1);
    }
    if (L->leng == 0) {
        printf("错误：顺序表为空，无法删除。\n");
        exit(1);
    }

    int k = 0;  // k 表示当前写入位置
    for (int i = 0; i < L->leng; i++) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k++] = L->data[i];  // 保留不在 [s, t] 区间的元素
        }
    }
    L->leng = k;

    printf("删除后顺序表为：");
    printfList(L);
}

int main() {
    List L = {{-3, 0, 1, 2, 5, 6}, 6};

    int s = -1;
    int t = 1;

    delList(&L, s, t);  // 删除值在 [-1, 1] 区间的元素（含端点）
    return 0;
}
