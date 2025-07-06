#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �������ڵ�ṹ�嶨��
typedef struct TreeNode {
    char data;                // �ڵ�洢���ַ�����
    struct TreeNode* left;    // ����ָ��
    struct TreeNode* right;   // �Һ���ָ��
} TreeNode;

char inputStr[1000];  // ����������������ַ��������У�
int pos = 0;          // ���ڱ����ַ�����ȫ������

// �����½ڵ㣬����ַ��� '#' ���ʾ�սڵ㣬���� NULL
TreeNode* createNode(char val) {
    if (val == '#') return NULL;   // �սڵ㣬���� NULL

    // Ϊ�½ڵ�����ڴ�
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {                   // ����ʧ�ܣ������˳�
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    node->data = val;              // ���ýڵ�����
    node->left = NULL;             // ��ʼ�����Һ���Ϊ��
    node->right = NULL;
    return node;
}

// ����ȫ�������ݹ鴴�������������˳����ַ�
TreeNode* createTree() {
    if (inputStr[pos] == '\0')      // �������ַ�����β�������ݹ�
        return NULL;

    char ch = inputStr[pos];        // ȡ��ǰ�ַ�
    pos++;                         // ָ�������һλ

    if (ch == '#')                  // �����սڵ��ǣ����� NULL
        return NULL;

    // ������ǰ�ڵ�
    TreeNode* root = createNode(ch);
    // �ݹ鴴��������
    root->left = createTree();
    // �ݹ鴴��������
    root->right = createTree();

    return root;
}

// ǰ�������ӡ
void preOrder(TreeNode* root) {
    if (!root) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// ���������ӡ
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

// ���������ӡ
void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// �ݹ��ͷŶ������ڴ棬��ֹ�ڴ�й©
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("��������������������У�'#'��ʾ�սڵ㣨���磺ABD##E##C#F##����\n");
    // ��ȡһ������������ַ����������սڵ���
    if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) {
        printf("��ȡ����ʧ��\n");
        return 1;
    }

    // ȥ���ַ���ĩβ�Ļ��з�
    size_t len = strlen(inputStr);
    if (len > 0 && inputStr[len - 1] == '\n') {
        inputStr[len - 1] = '\0';
    }

    pos = 0;                  // �ݹ鴴����ʱ��������0��ʼ
    TreeNode* root = createTree();  // ���������ַ�������������

    // ��ӡ�������
    printf("ǰ�������");
    preOrder(root);
    printf("\n");

    printf("���������");
    inOrder(root);
    printf("\n");

    printf("���������");
    postOrder(root);
    printf("\n");

    freeTree(root);   // �ͷ��ڴ�
    return 0;
}
