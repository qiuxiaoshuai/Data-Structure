#include <stdio.h>

#define N 8  // A~H，共8个节点

int parent[N];
int firstchild[N];
int nextsibling[N];
char name[N] = {'A','B','C','D','E','F','G','H'};

// 初始化
void init() {
    for (int i = 0; i < N; i++) {
        parent[i] = -1;       // 每个节点独立成树
        firstchild[i] = -1;
        nextsibling[i] = -1;
    }
}

// 查找（Find）带路径压缩
int find(int x) {
    if (parent[x] == -1) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

// 合并（Union）——将 y 所在的集合合并到 x
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;  // rootY 挂到 rootX 下
        // 把 rootY 加入 rootX 的孩子链中
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

// 构造森林
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

// 打印树结构（递归）
void printTree(int root, int depth) {
    if (root == -1) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("%c\n", name[root]);

    printTree(firstchild[root], depth + 1);
    printTree(nextsibling[root], depth);
}

// 打印整个森林
void printForest() {
    printf("\n森林结构：\n");
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {  // 是根节点
            printTree(i, 0);
            printf("\n");
        }
    }
}

// 打印数组关系
void printArrays() {
    printf("结点   双亲   第一个孩子   下一个兄弟\n");
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

    printf("查找测试：\n");
    printf("节点 E 的根是 %c\n", name[find(4)]);
    printf("节点 H 的根是 %c\n", name[find(7)]);

    return 0;
}
