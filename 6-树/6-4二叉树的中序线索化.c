#include <stdio.h>
#include <stdlib.h>

// 定义线索二叉树节点结构
typedef struct ThreadNode {
    char data;                         // 节点数据
    struct ThreadNode *left, *right;  // 左右指针
    int ltag, rtag;                    // 左右线索标志：0=孩子指针，1=线索
} ThreadNode;

// 全局变量：前驱指针，在线索化时使用
ThreadNode *pre = NULL;

// 创建新节点的函数
ThreadNode* CreateNode(char data) {
    ThreadNode *node = (ThreadNode*)malloc(sizeof(ThreadNode));
    node->data = data;
    node->left = node->right = NULL;
    node->ltag = node->rtag = 0;  // 初始都为孩子指针
    return node;
}

// 对树进行中序线索化的递归函数
void InThreading(ThreadNode *p) {
    if (p != NULL) {
        // 递归左子树
        InThreading(p->left);

        // 如果左孩子为空，建立前驱线索
        if (p->left == NULL) {
            p->ltag = 1;      // 设置左线索标志
            p->left = pre;    // 指向前驱
        }

        // 如果前驱节点右孩子为空，建立后继线索
        if (pre != NULL && pre->right == NULL) {
            pre->rtag = 1;    // 设置右线索标志
            pre->right = p;   // 前驱的后继指向当前节点
        }

        // 更新前驱为当前节点
        pre = p;

        // 递归右子树
        InThreading(p->right);
    }
}

// 创建中序线索二叉树：调用递归函数，并处理最后一个节点
void CreateInThread(ThreadNode *root) {
    pre = NULL;             // 初始化前驱为空
    InThreading(root);      // 开始中序线索化

    // 最后一个节点的后继线索处理
    if (pre != NULL) {
        pre->rtag = 1;
        pre->right = NULL;
    }
}

// 中序遍历线索二叉树（非递归，利用线索）
void InOrder(ThreadNode *T) {
    ThreadNode *p = T;

    while (p != NULL) {
        // 1. 向左走到最左边的节点
        while (p->ltag == 0)
            p = p->left;

        // 2. 访问该节点
        printf("%c ", p->data);

        // 3. 如果是线索，则通过后继线索一路访问下去
        while (p->rtag == 1 && p->right != NULL) {
            p = p->right;
            printf("%c ", p->data);
        }

        // 4. 移动到右孩子，继续循环
        p = p->right;
    }
}

// 主函数：构造一棵二叉树并进行中序线索化 + 遍历
int main() {
    /*
        构造如下的二叉树：
        
               A
             /   \
            B     C
           / \     \
          D   E     F

        中序遍历应为：D B E A C F
    */

    // 手动构造节点
    ThreadNode *A = CreateNode('A');
    ThreadNode *B = CreateNode('B');
    ThreadNode *C = CreateNode('C');
    ThreadNode *D = CreateNode('D');
    ThreadNode *E = CreateNode('E');
    ThreadNode *F = CreateNode('F');

    // 建立节点之间的连接关系
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    // 中序线索化
    CreateInThread(A);

    // 中序遍历线索二叉树
    printf("中序遍历线索二叉树的结果：\n");
    InOrder(A);
    printf("\n");

    return 0;
}
