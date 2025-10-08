#include <stdio.h>

// 二叉树顺序存储的算法求 LCA
// tree 是二叉树的顺序存储数组，n 是树的结点数
int findLCA(int tree[], int n, int i, int j) {
    // 如果 i 或 j 超出树的范围，直接返回 -1
    if (i < 1 || i > n || j < 1 || j > n) {
        printf("节点编号超出范围\n");
        return -1;
    }

    // 从 i 和 j 开始向上查找，直到找到公共祖先
    while (i != j) {
        // 如果 i 节点的编号大于 j 节点的编号，i 向上移动到父节点
        if (i > j) {
            i = i / 2;  // i 的父节点
        }
        // 如果 j 节点的编号大于 i 节点的编号，j 向上移动到父节点
        else {
            j = j / 2;  // j 的父节点
        }
    }

    return i;  // 找到的 i 和 j 相同即为最近公共祖先
}

int add(int A[],int i,int j){
    while(i!=j){
        if(i>j){
            i = i / 2;
        }else{
            j = j / 2;
        }
    }
    return i;
}

int main() {
    int tree[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  // 顺序存储的二叉树 (1-12)
    int n = 12;  // 二叉树的节点数
    
    int i = 8;   // 节点 i
    int j = 9;   // 节点 j

    int lca = findLCA(tree, n, i, j);  // 查找 i 和 j 的最近公共祖先
    printf("节点 %d 和 节点 %d 的最近公共祖先是: %d\n", i, j, lca);
    int ca = add(tree, i, j);  // 查找 i 和 j 的最近公共祖先
    printf("节点 %d 和 节点 %d 的最近公共祖先是: %d\n", i, j, ca);
    return 0;
}
