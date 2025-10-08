#include <stdio.h>

#define N 8  // A~H����8���ڵ�

int parent[N];
int firstchild[N];
int nextsibling[N];
char name[N] = {'A','B','C','D','E','F','G','H'};

// ��ʼ��
void init() {
    for (int i = 0; i < N; i++) {
        parent[i] = -1;       // ÿ���ڵ��������
        firstchild[i] = -1;
        nextsibling[i] = -1;
    }
}

// ���ң�Find����·��ѹ��
int find(int x) {
    if (parent[x] == -1) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

// �ϲ���Union�������� y ���ڵļ��Ϻϲ��� x
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;  // rootY �ҵ� rootX ��
        // �� rootY ���� rootX �ĺ�������
        if (firstchild[rootX] == -1)
            firstchild[rootX] = rootY;
        else {
            int temp = firstchild[rootX];
            while (nextsibling[temp] != -1)
                temp = nextsibling[temp];
            nextsibling[temp] = rootY;
        }
    }
}

// ����ɭ��
void buildForest() {
    // T1: A-B, A-C, A-D, C-E
    unite(0, 1); // A-B
    unite(0, 2); // A-C
    unite(0, 3); // A-D
    unite(2, 4); // C-E

    // T2: F-G, F-H
    unite(5, 6); // F-G
    unite(5, 7); // F-H
}

// ��ӡ���ṹ���ݹ飩
void printTree(int root, int depth) {
    if (root == -1) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("%c\n", name[root]);

    printTree(firstchild[root], depth + 1);
    printTree(nextsibling[root], depth);
}

// ��ӡ����ɭ��
void printForest() {
    printf("\nɭ�ֽṹ��\n");
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {  // �Ǹ��ڵ�
            printTree(i, 0);
            printf("\n");
        }
    }
}

// ��ӡ�����ϵ
void printArrays() {
    printf("���   ˫��   ��һ������   ��һ���ֵ�\n");
    for (int i = 0; i < N; i++) {
        printf("  %c      %2d        %2d           %2d\n",
               name[i], parent[i], firstchild[i], nextsibling[i]);
    }
}

int main() {
    init();
    buildForest();

    printArrays();
    printForest();

    printf("���Ҳ��ԣ�\n");
    printf("�ڵ� E �ĸ��� %c\n", name[find(4)]);
    printf("�ڵ� H �ĸ��� %c\n", name[find(7)]);

    return 0;
}
