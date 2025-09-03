#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 插入结点
int BST_Insert(BSTree *T, int key) {
    if (*T == NULL) {  // 如果当前位置为空，新建结点
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->key = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return 1;
    }
    if (key == (*T)->key) {
        return 0; // 树中已存在相同关键字，不插入
    } else if (key < (*T)->key) {
        return BST_Insert(&((*T)->lchild), key); // 插入到左子树
    } else {
        return BST_Insert(&((*T)->rchild), key); // 插入到右子树
    }
}

// 查找结点
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

// 删除结点
BSTNode* BST_Delete(BSTree T, int key) {
    if (T == NULL) return NULL;

    if (key < T->key) {
        T->lchild = BST_Delete(T->lchild, key);
    } else if (key > T->key) {
        T->rchild = BST_Delete(T->rchild, key);
    } else { // 找到结点
        if (T->lchild == NULL) { // 只有右子树或无子树
            BSTNode* temp = T->rchild;
            free(T);
            return temp;
        } else if (T->rchild == NULL) { // 只有左子树
            BSTNode* temp = T->lchild;
            free(T);
            return temp;
        } else { // 左右子树都有
            BSTNode* temp = T->rchild;
            while (temp->lchild != NULL) { // 找右子树最小结点
                temp = temp->lchild;
            }
            T->key = temp->key; // 用该结点值替代
            T->rchild = BST_Delete(T->rchild, temp->key); // 删除该结点
        }
    }
    return T;
}

// 中序遍历（结果为升序）
void InOrder(BSTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%d ", T->key);
        InOrder(T->rchild);
    }
}

// 构造一棵BST
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

    // 构造
    BSTree T = BST_Create(arr, n);

    printf("中序遍历结果: ");
    InOrder(T);
    printf("\n");

    // 查找
    int key = 37;
    BSTNode* found = BST_Search(T, key);
    if (found) {
        printf("找到关键字 %d\n", found->key);
    } else {
        printf("未找到关键字 %d\n", key);
    }

    // 删除
    T = BST_Delete(T, 45);
    printf("删除45后的中序遍历: ");
    InOrder(T);
    printf("\n");

    return 0;
}
