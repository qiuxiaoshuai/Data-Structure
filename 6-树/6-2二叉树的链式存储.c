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

// ǰ�������ӡ������
void preOrder(TreeNode* root) {
    if (!root) return;  // ����ڵ�Ϊ�գ�����
    printf("%c ", root->data);  // ��ӡ��ǰ�ڵ�
    preOrder(root->left);       // ����������
    preOrder(root->right);      // ����������
}

// ���������ӡ������
void inOrder(TreeNode* root) {
    if (!root) return;  // ����ڵ�Ϊ�գ�����
    inOrder(root->left);   // ����������
    printf("%c ", root->data);  // ��ӡ��ǰ�ڵ�
    inOrder(root->right);  // ����������
}

// ���������ӡ������
void postOrder(TreeNode* root) {
    if (!root) return;  // ����ڵ�Ϊ�գ�����
    postOrder(root->left);   // ����������
    postOrder(root->right);  // ����������
    printf("%c ", root->data);  // ��ӡ��ǰ�ڵ�
}

// �ͷŶ��������ڴ�
void freeTree(TreeNode* root) {
    if (!root) return;  // ����ڵ�Ϊ�գ�����
    freeTree(root->left);  // �ݹ��ͷ�������
    freeTree(root->right); // �ݹ��ͷ�������
    free(root);  // �ͷŵ�ǰ�ڵ���ڴ�
}

// ʹ�ö��еķǵݹ��㷨��������߶�
int getHeight(TreeNode* root) {
    if (!root) return 0;  // �����߶�Ϊ 0

    // ����һ���򵥵Ķ��У�������ʵ�֣�
    TreeNode* queue[1000];
    int front = 0;  //����ͷָ��
    int rear = 0;  // ����βָ��
    int height = 0;

    queue[rear++] = root;  // ���ڵ����

    for (int i = front; i < rear; i++) {
        printf("%c ", queue[i]->data);
    }
    printf("\n");

    while (front < rear) {
        int levelSize = rear - front;  // ��ǰ��ڵ���
        // ������ǰ��
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue[front++];  // ����
            // ���Һ������
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        height++;  // һ�㴦����ϣ�����+1
    }

    return height;
}

// �ж��Ƿ�Ϊ��ȫ������
int isCompleteBinaryTree(TreeNode* root) {
    if (!root) return 1;  // ������Ϊ��ȫ������

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    int flag = 0;  // ����Ƿ���ֹ��սڵ�

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];  // ����

        if (node) {
            // ��֮ǰ���ֹ��սڵ㣬�����������ǿսڵ� �� ������ȫ������
            if (flag)
                return 0;
            // �����ӽڵ����
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            // ��һ�������սڵ㣬�������ձ�־��
            flag = 1;
        }
    }

    return 1;  // ������û��ͻ��������ȫ������
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

    // ��ӡǰ�����
    printf("ǰ�����: ");
    preOrder(root);
    printf("\n");

    // ��ӡ�������
    printf("�������: ");
    inOrder(root);
    printf("\n");

    // ��ӡ�������
    printf("�������: ");
    postOrder(root);
    printf("\n");

    // ����߶�
    int height = getHeight(root);
    printf("�������߶ȣ��ǵݹ飩: %d\n", height);

    freeTree(root);   // �ͷ������ڴ�
    return 0;
}
