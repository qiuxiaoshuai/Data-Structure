#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct ThreadNode {
    char data;              // 存储节点的值
    struct ThreadNode *left, *right; // 左右子节点指针
    int leftThread, rightThread;  // 标识是否为线索
} ThreadNode;

// 创建节点函数
ThreadNode* CreateNode(char data) {
    ThreadNode *newNode = (ThreadNode *)malloc(sizeof(ThreadNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = newNode->rightThread = 0;  // 初始不为线索
    return newNode;
}

ThreadNode *postThread = NULL;  // 全局变量，用来存储后一个访问的节点

// 后序线索化二叉树
void postThreadedTraversal(ThreadNode *root) {
    if (root == NULL) return;

    // 递归线索化左子树和右子树
    postThreadedTraversal(root->left);
    postThreadedTraversal(root->right);

    // 处理当前节点的左指针
    if (root->left == NULL) {
        root->left = postThread;
        root->leftThread = 1;  // 标记为线索
    }

    // 处理当前节点的右指针
    if (postThread != NULL && postThread->right == NULL) {
        postThread->right = root;
        postThread->rightThread = 1;  // 标记为线索
    }

    // 更新后一个节点
    postThread = root;
}

// 后序遍历线索化二叉树
void traverseThreadedTree(ThreadNode *root) {
    ThreadNode *curr = root;
    while (curr != NULL) {
        printf("%c ", curr->data); // 输出当前节点

        // 如果右指针是线索，则跳到后继节点
        if (curr->rightThread == 1)
            curr = curr->right;
        else
            curr = curr->left;
    }
}

// 主函数，构造二叉树并进行线索化和遍历
int main() {
    // 手动构造节点
    ThreadNode *A = CreateNode('A');
    ThreadNode *B = CreateNode('B');
    ThreadNode *C = CreateNode('C');
    ThreadNode *D = CreateNode('D');
    ThreadNode *E = CreateNode('E');
    ThreadNode *F = CreateNode('F');

    // 构造二叉树结构
    A->left = B; A->right = C;
    B->left = D; B->right = E;
    C->right = F;

    // 后序线索化二叉树
    postThreadedTraversal(A);

    // 后序遍历线索化二叉树
    printf("Threaded Postorder Traversal: ");
    traverseThreadedTree(A);
    printf("\n");

    return 0;
}
