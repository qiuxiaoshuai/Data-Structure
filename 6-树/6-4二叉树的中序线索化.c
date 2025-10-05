#include <stdio.h>
#include <stdlib.h>

// 定义线程二叉树的节点结构体
typedef struct ThreadNode {
    char data;                         // 存储节点的数据
    struct ThreadNode *left, *right;   // 左右子节点指针
    int ltag, rtag;                    // 左右标志：0表示普通指针，1表示线索指针
} ThreadNode;

// 全局变量：前驱节点指针，在线索化过程中使用
ThreadNode *pre = NULL;

// 创建一个新的节点并初始化
ThreadNode* CreateNode(char data) {
    ThreadNode *node = (ThreadNode*)malloc(sizeof(ThreadNode)); // 动态分配内存
    node->data = data;           // 设置节点的数据
    node->left = node->right = NULL;  // 初始化左右子指针为空
    node->ltag = node->rtag = 0;     // 初始为普通指针（非线索）
    return node;
}

// 中序线索化的递归函数
void InThreading(ThreadNode *p) {
    if (p != NULL) {
        // 递归处理左子树
        InThreading(p->left);

        // 如果当前节点的左子指针为空，则设置为前驱节点
        if (p->left == NULL) {
            p->ltag = 1;      // 标记为线索
            p->left = pre;    // 当前节点的左指针指向前驱节点
        }

        // 如果前驱节点的右指针为空，则设置为当前节点
        if (pre != NULL && pre->right == NULL) {
            pre->rtag = 1;    // 标记为线索
            pre->right = p;   // 前驱节点的右指针指向当前节点
        }

        // 更新前驱节点为当前节点
        pre = p;

        // 递归处理右子树
        InThreading(p->right);
    }
}

// 创建中序线索化二叉树的函数
void CreateInThread(ThreadNode *root) {
    pre = NULL;             // 初始化前驱节点为空
    InThreading(root);      // 从根节点开始进行中序线索化

    // 处理最后一个节点的右指针，设为NULL
    if (pre != NULL) {
        pre->rtag = 1;
        pre->right = NULL;
    }
}

// 中序遍历线索化后的二叉树
void InOrder(ThreadNode *T) {
    ThreadNode *p = T;

    while (p != NULL) {
        // 1. 找到最左节点
        while (p->ltag == 0)  // 如果左指针不是线索，则继续向左走
            p = p->left;

        // 2. 访问当前节点
        printf("%c ", p->data);

        // 3. 如果右指针是线索，跳转到后继节点
        while (p->rtag == 1 && p->right != NULL) {
            p = p->right;    // 跳到后继节点
            printf("%c ", p->data);
        }

        // 4. 向右子树移动
        p = p->right;
    }
}

// 主函数，构造二叉树并进行线索化和遍历
int main() {
    /*
        构造如下的二叉树：
        
               A
             /   \
            B     C
           / \     \
          D   E     F

        中序遍历应该为：D B E A C F
    */

    // 手动创建节点
    ThreadNode *A = CreateNode('A');
    ThreadNode *B = CreateNode('B');
    ThreadNode *C = CreateNode('C');
    ThreadNode *D = CreateNode('D');
    ThreadNode *E = CreateNode('E');
    ThreadNode *F = CreateNode('F');

    // 构造二叉树结构
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    // 创建中序线索化二叉树
    CreateInThread(A);

    // 中序遍历线索化后的二叉树
    printf("中序线索化遍历结果：");
    InOrder(A);
    printf("\n");

    return 0;
}
