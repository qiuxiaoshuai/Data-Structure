#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树结点结构体
typedef struct nodef {
    char data[10];      // 存储操作数或操作符
    struct nodef *left; // 左子树
    struct nodef *right;// 右子树
} BTree;

// 创建新结点
BTree* createNode(char* data) {
    BTree* newNode = (BTree*)malloc(sizeof(BTree));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 判断是否是操作符（+、-、*、/等）
int isOperator(char* c) {
    return (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || 
            strcmp(c, "*") == 0 || strcmp(c, "/") == 0);
}

// 递归函数，将表达式树转换为带括号的中缀表达式
void EToe(BTree *root, int deep) {
    if (root == NULL) return;

    // 叶子结点直接输出
    if (root->left == NULL && root->right == NULL) {
        printf("%s", root->data);
    } else {
        // 如果当前节点不是最外层的节点，加上括号
        if (deep > 1) printf("(");

        // 递归处理左子树
        EToe(root->left, deep + 1);

        // 输出当前节点的操作符
        printf("%s", root->data);

        // 递归处理右子树
        EToe(root->right, deep + 1);

        // 如果当前节点不是最外层的节点，加上右括号
        if (deep > 1) printf(")");
    }
}

// 外部接口函数，简化调用
void Toe(BTree *root) {
    EToe(root, 1); // 从深度1开始调用
}

// 测试代码
int main() {
    // 构建示例树：表达式 (a + b) * (c * (-d))
    BTree* node1 = createNode("a");
    BTree* node2 = createNode("b");
    BTree* node3 = createNode("+");
    node3->left = node1;
    node3->right = node2;

    BTree* node4 = createNode("c");
    BTree* node5 = createNode("d");

    BTree* node6 = createNode("-");
    node6->left = NULL;
    node6->right = node5;

    BTree* node7 = createNode("*");  // Root
    node7->left = node3;             // Left child (a + b)
    
    // Right child is another '*', with left 'c' and right '(-d)'
    BTree* node8 = createNode("*");
    node8->left = node4;             // Left child 'c'
    node8->right = node6;            // Right child '(-d)'
    node7->right = node8;            // Attach right child to root node

    printf("中缀表达式为：");
    Toe(node7); // 输出中缀表达式
    printf("\n");

    return 0;
}
