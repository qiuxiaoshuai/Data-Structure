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

// 前序遍历打印二叉树
void preOrder(TreeNode* root) {
    if (!root) return;  // 如果节点为空，返回
    printf("%c ", root->data);  // 打印当前节点
    preOrder(root->left);       // 遍历左子树
    preOrder(root->right);      // 遍历右子树
}

// 中序遍历打印二叉树
void inOrder(TreeNode* root) {
    if (!root) return;  // 如果节点为空，返回
    inOrder(root->left);   // 遍历左子树
    printf("%c ", root->data);  // 打印当前节点
    inOrder(root->right);  // 遍历右子树
}

// 后序遍历打印二叉树
void postOrder(TreeNode* root) {
    if (!root) return;  // 如果节点为空，返回
    postOrder(root->left);   // 遍历左子树
    postOrder(root->right);  // 遍历右子树
    printf("%c ", root->data);  // 打印当前节点
}

// 释放二叉树的内存
void freeTree(TreeNode* root) {
    if (!root) return;  // 如果节点为空，返回
    freeTree(root->left);  // 递归释放左子树
    freeTree(root->right); // 递归释放右子树
    free(root);  // 释放当前节点的内存
}

// 使用队列的非递归算法求二叉树高度
int getHeight(TreeNode* root) {
    if (!root) return 0;  // 空树高度为 0

    // 定义一个简单的队列（用数组实现）
    TreeNode* queue[1000];
    int front = 0;  //队列头指针
    int rear = 0;  // 队列尾指针
    int height = 0;

    queue[rear++] = root;  // 根节点入队

    for (int i = front; i < rear; i++) {
        printf("%c ", queue[i]->data);
    }
    printf("\n");

    while (front < rear) {
        int levelSize = rear - front;  // 当前层节点数
        // 遍历当前层
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue[front++];  // 出队
            // 左右孩子入队
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        height++;  // 一层处理完毕，层数+1
    }

    return height;
}

// 判断是否为完全二叉树
int isCompleteBinaryTree(TreeNode* root) {
    if (!root) return 1;  // 空树视为完全二叉树

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    int flag = 0;  // 标记是否出现过空节点

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];  // 出队

        if (node) {
            // 若之前出现过空节点，现在又遇到非空节点 → 不是完全二叉树
            if (flag)
                return 0;
            // 左右子节点入队
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            // 第一次遇到空节点，开启“空标志”
            flag = 1;
        }
    }

    return 1;  // 遍历完没冲突，就是完全二叉树
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

    // 打印前序遍历
    printf("前序遍历: ");
    preOrder(root);
    printf("\n");

    // 打印中序遍历
    printf("中序遍历: ");
    inOrder(root);
    printf("\n");

    // 打印后序遍历
    printf("后序遍历: ");
    postOrder(root);
    printf("\n");

    // 计算高度
    int height = getHeight(root);
    printf("二叉树高度（非递归）: %d\n", height);

    freeTree(root);   // 释放树的内存
    return 0;
}
