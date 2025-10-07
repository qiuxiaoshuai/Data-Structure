#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������������ṹ��
typedef struct nodef {
    char data[10];      // �洢�������������
    struct nodef *left; // ������
    struct nodef *right;// ������
} BTree;

// �����½��
BTree* createNode(char* data) {
    BTree* newNode = (BTree*)malloc(sizeof(BTree));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// �ж��Ƿ��ǲ�������+��-��*��/�ȣ�
int isOperator(char* c) {
    return (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || 
            strcmp(c, "*") == 0 || strcmp(c, "/") == 0);
}

// �ݹ麯���������ʽ��ת��Ϊ�����ŵ���׺���ʽ
void EToe(BTree *root, int deep) {
    if (root == NULL) return;

    // Ҷ�ӽ��ֱ�����
    if (root->left == NULL && root->right == NULL) {
        printf("%s", root->data);
    } else {
        // �����ǰ�ڵ㲻�������Ľڵ㣬��������
        if (deep > 1) printf("(");

        // �ݹ鴦��������
        EToe(root->left, deep + 1);

        // �����ǰ�ڵ�Ĳ�����
        printf("%s", root->data);

        // �ݹ鴦��������
        EToe(root->right, deep + 1);

        // �����ǰ�ڵ㲻�������Ľڵ㣬����������
        if (deep > 1) printf(")");
    }
}

// �ⲿ�ӿں������򻯵���
void Toe(BTree *root) {
    EToe(root, 1); // �����1��ʼ����
}

// ���Դ���
int main() {
    // ����ʾ���������ʽ (a + b) * (c * (-d))
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

    printf("��׺���ʽΪ��");
    Toe(node7); // �����׺���ʽ
    printf("\n");

    return 0;
}
