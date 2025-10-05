#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct Node {  
    int data;  
    struct Node *left, *right;  
    int leftThread, rightThread;  // 用来标识是否为线索  
} Node;  
Node* createNode(int data) {  
    Node *newNode = (Node *)malloc(sizeof(Node));  
    newNode->data = data;  
    newNode->left = newNode->right = NULL;  
    newNode->leftThread = newNode->rightThread = 0; // 初始不为线索  
    return newNode;  
}  
Node *preThread = NULL;  // 全局变量，用来存储前一个访问的节点  
  
// 先序线索化函数  
void preThreadedTraversal(Node *root) {  
    if (root == NULL) return;  
  
    // 处理当前节点的左指针  
    if (root->left == NULL) {  
        root->left = preThread;  
        root->leftThread = 1;  // 标记为线索  
    }  
  
    // 处理当前节点的右指针  
    if (preThread != NULL && preThread->right == NULL) {  
        preThread->right = root;  
        preThread->rightThread = 1;  // 标记为线索  
    }  
  
    // 更新前一个节点  
    preThread = root;  
  
    // 如果没有线索，递归先序遍历  
    if (root->leftThread == 0) preThreadedTraversal(root->left);  
    if (root->rightThread == 0) preThreadedTraversal(root->right);  
}  
// 先序遍历线索化二叉树  
void traverseThreadedTree(Node *root) {  
    Node *curr = root;  
    while (curr != NULL) {  
        // 输出当前节点  
        printf("%d ", curr->data);  
  
        // 如果左指针是线索，则跳到前驱节点  
        if (curr->leftThread == 1)  
            curr = curr->left;  
        else  
            curr = curr->right;  
    }  
}  
int main() {  
    // 创建一个简单的二叉树  
    Node *root = createNode(1);  
    root->left = createNode(2);  
    root->right = createNode(3);  
    root->left->left = createNode(4);  
    root->left->right = createNode(5);  
    root->right->left = createNode(6);  
  
    // 先序线索化  
    preThreadedTraversal(root);  
  
    // 先序遍历线索化二叉树  
    printf("Threaded Preorder Traversal: ");  
    traverseThreadedTree(root);  
    printf("\n");  
  
    return 0;  
}