#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>    // 引入 INT_MIN 和 INT_MAX
#include <stdbool.h>   // 引入 bool 类型

#define MAX_SIZE 100   // 顺序存储二叉树的最大节点数
#define true 1
#define false 0

// 顺序存储二叉树结构体
typedef struct {
    int SqBiTNode[MAX_SIZE];  // 存储二叉树节点的数组
    int ElemNum;              // 当前二叉树中实际节点数
} SqBiTree;

// 判断以 index 为根的子树是否是二叉搜索树
// 参数：
// a     - 二叉树结构
// index - 当前节点下标
// min   - 当前节点允许的最小值
// max   - 当前节点允许的最大值
bool id(SqBiTree a, int index, int min, int max) {
    // 1. 递归终止条件：节点为空（-1）或下标越界
    if (a.SqBiTNode[index] == -1 || index >= a.ElemNum) {
        return true; // 空节点默认满足 BST 条件
    }

    int val = a.SqBiTNode[index];  // 当前节点的值

    // 2. 检查当前节点值是否在允许范围内
    if (val <= min || val >= max) {
        return false; // 不满足 BST 条件，返回 false
    }

    // 3. 递归判断左子树和右子树
    // 左子树允许范围为 (min, val)
    // 右子树允许范围为 (val, max)
    return id(a, 2*index + 1, min, val) && id(a, 2*index + 2, val, max);
}

int main() {
    // 示例二叉树 a（顺序存储，-1 表示空节点）
    SqBiTree a = {{40, 25, 60, -1, 30, -1, 80, -1, -1, 27}, 10};
    // 示例二叉树 b
    SqBiTree b = {{40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35}, 11};

    // 打印二叉树 a 的节点值
    for (int i = 0; i < a.ElemNum; i++) {
        printf("%d ", a.SqBiTNode[i]);
    }
    printf("\n");

    // 判断二叉树 a 是否为 BST，并打印结果（1 表示 true，0 表示 false）
    printf("%d\n", id(a, 0, INT_MIN, INT_MAX));
    // 判断二叉树 b 是否为 BST，并打印结果
    printf("%d", id(b, 0, INT_MIN, INT_MAX));

    return 0;
}
