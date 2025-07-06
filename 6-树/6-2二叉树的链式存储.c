#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点结构体定义
typedef struct TreeNode {
    char data;                // 节点存储的字符数据
    struct TreeNode* left;    // 左孩子指针
    struct TreeNode* right;   // 右孩子指针
} TreeNode;

char inputStr[1000];  // 存放输入的先序遍历字符串（整行）
int pos = 0;          // 用于遍历字符串的全局索引

// 创建新节点，如果字符是 '#' 则表示空节点，返回 NULL
TreeNode* createNode(char val) {
    if (val == '#') return NULL;   // 空节点，返回 NULL

    // 为新节点分配内存
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {                   // 分配失败，程序退出
        printf("内存分配失败\n");
        exit(1);
    }
    node->data = val;              // 设置节点数据
    node->left = NULL;             // 初始化左右孩子为空
    node->right = NULL;
    return node;
}

// 根据全局索引递归创建树，先序遍历顺序读字符
TreeNode* createTree() {
    if (inputStr[pos] == '\0')      // 遍历到字符串结尾，结束递归
        return NULL;

    char ch = inputStr[pos];        // 取当前字符
    pos++;                         // 指针向后移一位

    if (ch == '#')                  // 遇到空节点标记，返回 NULL
        return NULL;

    // 创建当前节点
    TreeNode* root = createNode(ch);
    // 递归创建左子树
    root->left = createTree();
    // 递归创建右子树
    root->right = createTree();

    return root;
}

// 前序遍历打印
void preOrder(TreeNode* root) {
    if (!root) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历打印
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

// 后序遍历打印
void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// 递归释放二叉树内存，防止内存泄漏
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("请输入二叉树的先序序列，'#'表示空节点（例如：ABD##E##C#F##）：\n");
    // 读取一整行先序遍历字符串，包含空节点标记
    if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) {
        printf("读取输入失败\n");
        return 1;
    }

    // 去掉字符串末尾的换行符
    size_t len = strlen(inputStr);
    if (len > 0 && inputStr[len - 1] == '\n') {
        inputStr[len - 1] = '\0';
    }

    pos = 0;                  // 递归创建树时，索引从0开始
    TreeNode* root = createTree();  // 根据输入字符串创建二叉树

    // 打印遍历结果
    printf("前序遍历：");
    preOrder(root);
    printf("\n");

    printf("中序遍历：");
    inOrder(root);
    printf("\n");

    printf("后序遍历：");
    postOrder(root);
    printf("\n");

    freeTree(root);   // 释放内存
    return 0;
}
