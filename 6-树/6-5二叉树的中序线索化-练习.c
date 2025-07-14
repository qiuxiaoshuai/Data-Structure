#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    int weight;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����½��
TreeNode* CreateNode(int weight) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// ��������Ĵ�Ȩ·�����ȣ�WPL��
int GetWPL(TreeNode *root, int depth) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->weight * depth;

    return GetWPL(root->left, depth + 1) + GetWPL(root->right, depth + 1);
}

int main() {
    /*
       �����������ṹ��
               -
             /   \
           -      -
          / \    / \
        5   3  2   4

        ��Ҷ�ӽ�㣨5,3,2,4����·������ = 2
        WPL = 5��2 + 3��2 + 2��2 + 4��2 = 28
    */

    TreeNode *root = CreateNode(0);  // ��Ҷ�ڵ�Ȩ��Ϊ0
    root->left = CreateNode(0);
    root->right = CreateNode(0);

    root->left->left = CreateNode(5);
    root->left->right = CreateNode(3);
    root->right->left = CreateNode(2);
    root->right->right = CreateNode(4);

    int wpl = GetWPL(root, 0);  // �����Ϊ0

    printf("�ö�������WPL = %d\n", wpl);

    return 0;
}
