#include <stdio.h>
#include <stdlib.h>

// �����̶߳������Ľڵ�ṹ��
typedef struct ThreadNode {
    char data;                         // �洢�ڵ������
    struct ThreadNode *left, *right;   // �����ӽڵ�ָ��
    int ltag, rtag;                    // ���ұ�־��0��ʾ��ָͨ�룬1��ʾ����ָ��
} ThreadNode;

// ȫ�ֱ�����ǰ���ڵ�ָ�룬��������������ʹ��
ThreadNode *pre = NULL;

// ����һ���µĽڵ㲢��ʼ��
ThreadNode* CreateNode(char data) {
    ThreadNode *node = (ThreadNode*)malloc(sizeof(ThreadNode)); // ��̬�����ڴ�
    node->data = data;           // ���ýڵ������
    node->left = node->right = NULL;  // ��ʼ��������ָ��Ϊ��
    node->ltag = node->rtag = 0;     // ��ʼΪ��ָͨ�루��������
    return node;
}

// �����������ĵݹ麯��
void InThreading(ThreadNode *p) {
    if (p != NULL) {
        // �ݹ鴦��������
        InThreading(p->left);

        // �����ǰ�ڵ������ָ��Ϊ�գ�������Ϊǰ���ڵ�
        if (p->left == NULL) {
            p->ltag = 1;      // ���Ϊ����
            p->left = pre;    // ��ǰ�ڵ����ָ��ָ��ǰ���ڵ�
        }

        // ���ǰ���ڵ����ָ��Ϊ�գ�������Ϊ��ǰ�ڵ�
        if (pre != NULL && pre->right == NULL) {
            pre->rtag = 1;    // ���Ϊ����
            pre->right = p;   // ǰ���ڵ����ָ��ָ��ǰ�ڵ�
        }

        // ����ǰ���ڵ�Ϊ��ǰ�ڵ�
        pre = p;

        // �ݹ鴦��������
        InThreading(p->right);
    }
}

// ���������������������ĺ���
void CreateInThread(ThreadNode *root) {
    pre = NULL;             // ��ʼ��ǰ���ڵ�Ϊ��
    InThreading(root);      // �Ӹ��ڵ㿪ʼ��������������

    // �������һ���ڵ����ָ�룬��ΪNULL
    if (pre != NULL) {
        pre->rtag = 1;
        pre->right = NULL;
    }
}

// ���������������Ķ�����
void InOrder(ThreadNode *T) {
    ThreadNode *p = T;

    while (p != NULL) {
        // 1. �ҵ�����ڵ�
        while (p->ltag == 0)  // �����ָ�벻�������������������
            p = p->left;

        // 2. ���ʵ�ǰ�ڵ�
        printf("%c ", p->data);

        // 3. �����ָ������������ת����̽ڵ�
        while (p->rtag == 1 && p->right != NULL) {
            p = p->right;    // ������̽ڵ�
            printf("%c ", p->data);
        }

        // 4. ���������ƶ�
        p = p->right;
    }
}

// ������������������������������ͱ���
int main() {
    /*
        �������µĶ�������
        
               A
             /   \
            B     C
           / \     \
          D   E     F

        �������Ӧ��Ϊ��D B E A C F
    */

    // �ֶ������ڵ�
    ThreadNode *A = CreateNode('A');
    ThreadNode *B = CreateNode('B');
    ThreadNode *C = CreateNode('C');
    ThreadNode *D = CreateNode('D');
    ThreadNode *E = CreateNode('E');
    ThreadNode *F = CreateNode('F');

    // ����������ṹ
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    // ��������������������
    CreateInThread(A);

    // ���������������Ķ�����
    printf("�������������������");
    InOrder(A);
    printf("\n");

    return 0;
}
