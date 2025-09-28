#include <stdio.h>
#include <limits.h>

#define K 4   // �鲢·��
#define N 20  // ���鲢�������

int tree[K];       // ����������š����ߡ����±�
int leaves[K];     // Ҷ�ӽ�㣬��ŵ�ǰ��·��ֵ
int data[K][N] = { // ģ�� 4 ·���ݣ�ÿ·���������
    {1,  9, 15, 21, INT_MAX},
    {2, 10, 16, 22, INT_MAX},
    {3, 11, 17, 23, INT_MAX},
    {4, 12, 18, 24, INT_MAX}
};
int idx[K] = {0};  // ÿ·��ȡ���ݵ��±�λ��

// ����������
void adjust(int s) {
    int t = (s + K) / 2;  // ���ڵ�
    while (t > 0) {
        if (leaves[s] > leaves[tree[t]]) {
            int tmp = s;
            s = tree[t];
            tree[t] = tmp;
        }
        t /= 2;
    }
    tree[0] = s; // ���ڵ���ʤ��
}

// ����������
void createLoserTree() {
    for (int i = 0; i < K; i++) {
        tree[i] = K; // ��ʼȫ��Ϊ�ڱ�
    }
    leaves[K] = INT_MIN; // �ڱ���С
    for (int i = 0; i < K; i++) {
        adjust(i);
    }
}

int main() {
    // ��ʼ��ÿ·���ݵĵ�һ��Ԫ��
    for (int i = 0; i < K; i++) {
        leaves[i] = data[i][idx[i]];
    }

    createLoserTree();

    printf("��·�鲢�����\n");
    for (int count = 0; count < K * 4; count++) {
        int winner = tree[0];   // ȡ����Сֵ�±�
        printf("%d ", leaves[winner]);

        // ȡ winner ·����һ��Ԫ��
        idx[winner]++;
        leaves[winner] = data[winner][idx[winner]];

        // ����������
        adjust(winner);
    }
    printf("\n");

    return 0;
}
