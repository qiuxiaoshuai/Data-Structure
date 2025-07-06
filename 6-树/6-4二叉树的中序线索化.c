#include <stdio.h>
#include <stdlib.h>

// ���������������ڵ�ṹ
typedef struct ThreadNode {
    char data;                         // �ڵ�����
    struct ThreadNode *left, *right;  // ����ָ��
    int ltag, rtag;                    // ����������־��0=����ָ�룬1=����
} ThreadNode;

// ȫ�ֱ�����ǰ��ָ�룬��������ʱʹ��
ThreadNode *pre = NULL;

// �����½ڵ�ĺ���
ThreadNode* CreateNode(char data) {
    ThreadNode *node = (ThreadNode*)malloc(sizeof(ThreadNode));
    node->data = data;
    node->left = node->right = NULL;
    node->ltag = node->rtag = 0;  // ��ʼ��Ϊ����ָ��
    return node;
}

// �������������������ĵݹ麯��
void InThreading(ThreadNode *p) {
    if (p != NULL) {
        // �ݹ�������
        InThreading(p->left);

        // �������Ϊ�գ�����ǰ������
        if (p->left == NULL) {
            p->ltag = 1;      // ������������־
            p->left = pre;    // ָ��ǰ��
        }

        // ���ǰ���ڵ��Һ���Ϊ�գ������������
        if (pre != NULL && pre->right == NULL) {
            pre->rtag = 1;    // ������������־
            pre->right = p;   // ǰ���ĺ��ָ��ǰ�ڵ�
        }

        // ����ǰ��Ϊ��ǰ�ڵ�
        pre = p;

        // �ݹ�������
        InThreading(p->right);
    }
}

// �����������������������õݹ麯�������������һ���ڵ�
void CreateInThread(ThreadNode *root) {
    pre = NULL;             // ��ʼ��ǰ��Ϊ��
    InThreading(root);      // ��ʼ����������

    // ���һ���ڵ�ĺ����������
    if (pre != NULL) {
        pre->rtag = 1;
        pre->right = NULL;
    }
}

// ��������������������ǵݹ飬����������
void InOrder(ThreadNode *T) {
    ThreadNode *p = T;

    while (p != NULL) {
        // 1. �����ߵ�����ߵĽڵ�
        while (p->ltag == 0)
            p = p->left;

        // 2. ���ʸýڵ�
        printf("%c ", p->data);

        // 3. �������������ͨ���������һ·������ȥ
        while (p->rtag == 1 && p->right != NULL) {
            p = p->right;
            printf("%c ", p->data);
        }

        // 4. �ƶ����Һ��ӣ�����ѭ��
        p = p->right;
    }
}

// ������������һ�ö��������������������� + ����
int main() {
    /*
        �������µĶ�������
        
               A
             /   \
            B     C
           / \     \
          D   E     F

        �������ӦΪ��D B E A C F
    */

    // �ֶ�����ڵ�
    ThreadNode *A = CreateNode('A');
    ThreadNode *B = CreateNode('B');
    ThreadNode *C = CreateNode('C');
    ThreadNode *D = CreateNode('D');
    ThreadNode *E = CreateNode('E');
    ThreadNode *F = CreateNode('F');

    // �����ڵ�֮������ӹ�ϵ
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    // ����������
    CreateInThread(A);

    // �����������������
    printf("������������������Ľ����\n");
    InOrder(A);
    printf("\n");

    return 0;
}
