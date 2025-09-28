#include <stdio.h>
#include <limits.h>

#define K 4   // 归并路数
#define N 20  // 最大归并结果长度

int tree[K];       // 败者树，存放“败者”的下标
int leaves[K];     // 叶子结点，存放当前各路的值
int data[K][N] = { // 模拟 4 路数据，每路都是有序的
    {1,  9, 15, 21, INT_MAX},
    {2, 10, 16, 22, INT_MAX},
    {3, 11, 17, 23, INT_MAX},
    {4, 12, 18, 24, INT_MAX}
};
int idx[K] = {0};  // 每路已取数据的下标位置

// 调整败者树
void adjust(int s) {
    int t = (s + K) / 2;  // 父节点
    while (t > 0) {
        if (leaves[s] > leaves[tree[t]]) {
            int tmp = s;
            s = tree[t];
            tree[t] = tmp;
        }
        t /= 2;
    }
    tree[0] = s; // 根节点存放胜者
}

// 建立败者树
void createLoserTree() {
    for (int i = 0; i < K; i++) {
        tree[i] = K; // 初始全设为哨兵
    }
    leaves[K] = INT_MIN; // 哨兵最小
    for (int i = 0; i < K; i++) {
        adjust(i);
    }
}

int main() {
    // 初始化每路数据的第一个元素
    for (int i = 0; i < K; i++) {
        leaves[i] = data[i][idx[i]];
    }

    createLoserTree();

    printf("多路归并结果：\n");
    for (int count = 0; count < K * 4; count++) {
        int winner = tree[0];   // 取出最小值下标
        printf("%d ", leaves[winner]);

        // 取 winner 路的下一个元素
        idx[winner]++;
        leaves[winner] = data[winner][idx[winner]];

        // 调整败者树
        adjust(winner);
    }
    printf("\n");

    return 0;
}
