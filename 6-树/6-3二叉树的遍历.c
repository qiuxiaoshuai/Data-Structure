#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ����һ���½ڵ�
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �����������->��->�ң�
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// �����������->��->�ң�
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// �����������->��->����
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// ������������һ���򵥵���������
int main() {
    /*
        ����һ�ü򵥵�����
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

    printf("�������: ");
    preorder(root);
    printf("\n");

    printf("�������: ");
    inorder(root);
    printf("\n");

    printf("�������: ");
    postorder(root);
    printf("\n");

    return 0;
}
