#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建一个新节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 先序遍历（根->左->右）
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 中序遍历（左->根->右）
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// 后序遍历（左->右->根）
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// 主函数：构建一个简单的树并遍历
int main() {
    /*
        构造一棵简单的树：
              A
             / \
            B   C
           / \
          D   E
    */

    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');

    printf("先序遍历: ");
    preorder(root);
    printf("\n");

    printf("中序遍历: ");
    inorder(root);
    printf("\n");

    printf("后序遍历: ");
    postorder(root);
    printf("\n");

    return 0;
}
