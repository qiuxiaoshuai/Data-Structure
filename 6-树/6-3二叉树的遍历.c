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

// �������ĸ߶�
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// ��ָ���Ĳ���ϴ�ӡ�ڵ�
void printLevel(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%c ", root->data);  // ��ӡ��ǰ��Ľڵ�
    } else if (level > 1) {
        printLevel(root->left, level - 1);  // �ݹ��ӡ������
        printLevel(root->right, level - 1); // �ݹ��ӡ������
    }
}

// �������
void levelOrder(TreeNode* root) {
    int height = treeHeight(root);  // ��ȡ���ĸ߶�
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);  // ��ӡÿһ��Ľڵ�
        printf("\n");
    }
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

// ������������һ�ü򵥵���������
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

    printf("�������: \n");
    levelOrder(root);

    return 0;
}
