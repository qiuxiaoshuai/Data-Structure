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

// 计算树的高度
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// 在指定的层次上打印节点
void printLevel(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%c ", root->data);  // 打印当前层的节点
    } else if (level > 1) {
        printLevel(root->left, level - 1);  // 递归打印左子树
        printLevel(root->right, level - 1); // 递归打印右子树
    }
}

// 层序遍历
void levelOrder(TreeNode* root) {
    int height = treeHeight(root);  // 获取树的高度
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);  // 打印每一层的节点
        printf("\n");
    }
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

// 主函数：构建一棵简单的树并遍历
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

    printf("层序遍历: \n");
    levelOrder(root);

    return 0;
}
