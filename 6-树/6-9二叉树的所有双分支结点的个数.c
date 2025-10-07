#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
    char data;                // 存储节点的数据
    struct TreeNode* left;    // 左子节点
    struct TreeNode* right;   // 右子节点
} TreeNode;
char inputStr[1000];  // 用于存储输入的二叉树字符串
int pos = 0;          // 当前正在处理的字符位置
// 创建一个新的二叉树节点，若字符是 '#' 则返回 NULL 表示该节点为空
TreeNode* createNode(char val) {
    if (val == '#') return NULL;   // 如果字符为 '#'，表示该节点为空

    // 分配内存并初始化节点
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {                   // 如果内存分配失败
        printf("内存分配失败\n");
        exit(1);
    }
    node->data = val;              // 设置节点的数据
    node->left = NULL;             // 初始化左子节点为空
    node->right = NULL;            // 初始化右子节点为空
    return node;
}

// 根据前序遍历的输入字符串构建二叉树
TreeNode* createTree() {
    // 如果已经读取到字符串末尾，返回 NULL
    if (inputStr[pos] == '\0')      
        return NULL;

    char ch = inputStr[pos];        // 获取当前字符
    pos++;                         // 移动到下一个字符

    // 如果字符为 '#'，表示该节点为空
    if (ch == '#')                  
        return NULL;

    // 创建当前节点
    TreeNode* root = createNode(ch);
    // 递归创建左子树
    root->left = createTree();
    // 递归创建右子树
    root->right = createTree();

    return root;
}

int ecnode(TreeNode *root){
    if(root == NULL) return 0;
    int cont = (root->left && root->right) ? 1 : 0;
    cont += ecnode(root->left);
    cont += ecnode(root->right);
    return cont;
}


int main() {
    printf("请输入二叉树的前序遍历字符串（使用 '#' 表示空节点）：\n");
    // 读取用户输入的二叉树字符串
    if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) {
        printf("输入错误\n");
        return 1;
    }

    // 移除输入字符串末尾的换行符
    size_t len = strlen(inputStr);
    if (len > 0 && inputStr[len - 1] == '\n') {
        inputStr[len - 1] = '\0';
    }

    pos = 0;                  // 初始化处理位置为 0
    TreeNode* root = createTree();  // 根据输入字符串构建二叉树
    printf("树的所有二分叉结点的个数为：%d",ecnode(root));
    return 0;
}
