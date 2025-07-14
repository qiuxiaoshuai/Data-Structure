#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct TreeNode {
    int weight;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新结点
TreeNode* CreateNode(int weight) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// 求二叉树的带权路径长度（WPL）
int GetWPL(TreeNode *root, int depth) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->weight * depth;

    return GetWPL(root->left, depth + 1) + GetWPL(root->right, depth + 1);
}

int main() {
    /*
       构造如下树结构：
               -
             /   \
           -      -
          / \    / \
        5   3  2   4

        各叶子结点（5,3,2,4）的路径长度 = 2
        WPL = 5×2 + 3×2 + 2×2 + 4×2 = 28
    */

    TreeNode *root = CreateNode(0);  // 非叶节点权重为0
    root->left = CreateNode(0);
    root->right = CreateNode(0);

    root->left->left = CreateNode(5);
    root->left->right = CreateNode(3);
    root->right->left = CreateNode(2);
    root->right->right = CreateNode(4);

    int wpl = GetWPL(root, 0);  // 根深度为0

    printf("该二叉树的WPL = %d\n", wpl);

    return 0;
}
