#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// ������
int BST_Insert(BSTree *T, int key) {
    if (*T == NULL) {  // �����ǰλ��Ϊ�գ��½����
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->key = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return 1;
    }
    if (key == (*T)->key) {
        return 0; // �����Ѵ�����ͬ�ؼ��֣�������
    } else if (key < (*T)->key) {
        return BST_Insert(&((*T)->lchild), key); // ���뵽������
    } else {
        return BST_Insert(&((*T)->rchild), key); // ���뵽������
    }
}

// ���ҽ��
BSTNode* BST_Search(BSTree T, int key) {
    if (T == NULL || T->key == key) {
        return T;
    }
    if (key < T->key) {
        return BST_Search(T->lchild, key);
    } else {
        return BST_Search(T->rchild, key);
    }
}

// ɾ�����
BSTNode* BST_Delete(BSTree T, int key) {
    if (T == NULL) return NULL;

    if (key < T->key) {
        T->lchild = BST_Delete(T->lchild, key);
    } else if (key > T->key) {
        T->rchild = BST_Delete(T->rchild, key);
    } else { // �ҵ����
        if (T->lchild == NULL) { // ֻ����������������
            BSTNode* temp = T->rchild;
            free(T);
            return temp;
        } else if (T->rchild == NULL) { // ֻ��������
            BSTNode* temp = T->lchild;
            free(T);
            return temp;
        } else { // ������������
            BSTNode* temp = T->rchild;
            while (temp->lchild != NULL) { // ����������С���
                temp = temp->lchild;
            }
            T->key = temp->key; // �øý��ֵ���
            T->rchild = BST_Delete(T->rchild, temp->key); // ɾ���ý��
        }
    }
    return T;
}

// ������������Ϊ����
void InOrder(BSTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%d ", T->key);
        InOrder(T->rchild);
    }
}

// ����һ��BST
BSTree BST_Create(int arr[], int n) {
    BSTree T = NULL;
    for (int i = 0; i < n; i++) {
        BST_Insert(&T, arr[i]);
    }
    return T;
}

int main() {
    int arr[] = {45, 24, 53, 12, 37, 93, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    // ����
    BSTree T = BST_Create(arr, n);

    printf("����������: ");
    InOrder(T);
    printf("\n");

    // ����
    int key = 37;
    BSTNode* found = BST_Search(T, key);
    if (found) {
        printf("�ҵ��ؼ��� %d\n", found->key);
    } else {
        printf("δ�ҵ��ؼ��� %d\n", key);
    }

    // ɾ��
    T = BST_Delete(T, 45);
    printf("ɾ��45����������: ");
    InOrder(T);
    printf("\n");

    return 0;
}
