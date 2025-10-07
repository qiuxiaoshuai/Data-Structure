#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
    char data;                // �洢�ڵ������
    struct TreeNode* left;    // ���ӽڵ�
    struct TreeNode* right;   // ���ӽڵ�
} TreeNode;
char inputStr[1000];  // ���ڴ洢����Ķ������ַ���
int pos = 0;          // ��ǰ���ڴ�����ַ�λ��
// ����һ���µĶ������ڵ㣬���ַ��� '#' �򷵻� NULL ��ʾ�ýڵ�Ϊ��
TreeNode* createNode(char val) {
    if (val == '#') return NULL;   // ����ַ�Ϊ '#'����ʾ�ýڵ�Ϊ��

    // �����ڴ沢��ʼ���ڵ�
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {                   // ����ڴ����ʧ��
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    node->data = val;              // ���ýڵ������
    node->left = NULL;             // ��ʼ�����ӽڵ�Ϊ��
    node->right = NULL;            // ��ʼ�����ӽڵ�Ϊ��
    return node;
}

// ����ǰ������������ַ�������������
TreeNode* createTree() {
    // ����Ѿ���ȡ���ַ���ĩβ������ NULL
    if (inputStr[pos] == '\0')      
        return NULL;

    char ch = inputStr[pos];        // ��ȡ��ǰ�ַ�
    pos++;                         // �ƶ�����һ���ַ�

    // ����ַ�Ϊ '#'����ʾ�ýڵ�Ϊ��
    if (ch == '#')                  
        return NULL;

    // ������ǰ�ڵ�
    TreeNode* root = createNode(ch);
    // �ݹ鴴��������
    root->left = createTree();
    // �ݹ鴴��������
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
    printf("�������������ǰ������ַ�����ʹ�� '#' ��ʾ�սڵ㣩��\n");
    // ��ȡ�û�����Ķ������ַ���
    if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) {
        printf("�������\n");
        return 1;
    }

    // �Ƴ������ַ���ĩβ�Ļ��з�
    size_t len = strlen(inputStr);
    if (len > 0 && inputStr[len - 1] == '\n') {
        inputStr[len - 1] = '\0';
    }

    pos = 0;                  // ��ʼ������λ��Ϊ 0
    TreeNode* root = createTree();  // ���������ַ�������������
    printf("�������ж��ֲ���ĸ���Ϊ��%d",ecnode(root));
    return 0;
}
