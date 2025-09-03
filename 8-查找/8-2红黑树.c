#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

// 红黑树结点
typedef struct RBNode {
    int key;
    Color color;
    struct RBNode *lchild, *rchild, *parent;
} RBNode, *RBTree;

/* ========== 基础函数 ========== */

RBNode* createNode(int key, Color color, RBNode* parent) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->color = color;
    node->lchild = node->rchild = NULL;
    node->parent = parent;
    return node;
}

void leftRotate(RBTree *root, RBNode *x) {
    RBNode *y = x->rchild;
    x->rchild = y->lchild;
    if (y->lchild) y->lchild->parent = x;

    y->parent = x->parent;
    if (!x->parent) *root = y;
    else if (x == x->parent->lchild) x->parent->lchild = y;
    else x->parent->rchild = y;

    y->lchild = x;
    x->parent = y;
}

void rightRotate(RBTree *root, RBNode *y) {
    RBNode *x = y->lchild;
    y->lchild = x->rchild;
    if (x->rchild) x->rchild->parent = y;

    x->parent = y->parent;
    if (!y->parent) *root = x;
    else if (y == y->parent->lchild) y->parent->lchild = x;
    else y->parent->rchild = x;

    x->rchild = y;
    y->parent = x;
}

/* ========== 插入相关 ========== */

void insertFixup(RBTree *root, RBNode *z) {
    while (z->parent && z->parent->color == RED) {
        RBNode *y;
        if (z->parent == z->parent->parent->lchild) {
            y = z->parent->parent->rchild;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->rchild) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            y = z->parent->parent->lchild;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->lchild) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void RB_Insert(RBTree *root, int key) {
    RBNode *y = NULL, *x = *root;
    while (x) {
        y = x;
        if (key < x->key) x = x->lchild;
        else if (key > x->key) x = x->rchild;
        else return;
    }
    RBNode *z = createNode(key, RED, y);
    if (!y) *root = z;
    else if (key < y->key) y->lchild = z;
    else y->rchild = z;

    insertFixup(root, z);
}

/* ========== 删除相关 ========== */

RBNode* treeMinimum(RBNode *x) {
    while (x->lchild) x = x->lchild;
    return x;
}

void deleteFixup(RBTree *root, RBNode *x, RBNode *xParent) {
    while ((x == NULL || x->color == BLACK) && x != *root) {
        RBNode *w;
        if (x == xParent->lchild) {
            w = xParent->rchild;
            if (w && w->color == RED) {
                w->color = BLACK;
                xParent->color = RED;
                leftRotate(root, xParent);
                w = xParent->rchild;
            }
            if ((w->lchild == NULL || w->lchild->color == BLACK) &&
                (w->rchild == NULL || w->rchild->color == BLACK)) {
                if(w) w->color = RED;
                x = xParent;
                xParent = xParent->parent;
            } else {
                if (w->rchild == NULL || w->rchild->color == BLACK) {
                    if(w->lchild) w->lchild->color = BLACK;
                    if(w) w->color = RED;
                    rightRotate(root, w);
                    w = xParent->rchild;
                }
                if(w) w->color = xParent->color;
                xParent->color = BLACK;
                if(w->rchild) w->rchild->color = BLACK;
                leftRotate(root, xParent);
                x = *root;
                break;
            }
        } else {
            w = xParent->lchild;
            if (w && w->color == RED) {
                w->color = BLACK;
                xParent->color = RED;
                rightRotate(root, xParent);
                w = xParent->lchild;
            }
            if ((w->rchild == NULL || w->rchild->color == BLACK) &&
                (w->lchild == NULL || w->lchild->color == BLACK)) {
                if(w) w->color = RED;
                x = xParent;
                xParent = xParent->parent;
            } else {
                if (w->lchild == NULL || w->lchild->color == BLACK) {
                    if(w->rchild) w->rchild->color = BLACK;
                    if(w) w->color = RED;
                    leftRotate(root, w);
                    w = xParent->lchild;
                }
                if(w) w->color = xParent->color;
                xParent->color = BLACK;
                if(w->lchild) w->lchild->color = BLACK;
                rightRotate(root, xParent);
                x = *root;
                break;
            }
        }
    }
    if (x) x->color = BLACK;
}

void RB_Delete(RBTree *root, int key) {
    RBNode *z = *root;
    while (z && z->key != key) {
        if (key < z->key) z = z->lchild;
        else z = z->rchild;
    }
    if (!z) return;

    RBNode *y = z;
    Color yOriginalColor = y->color;
    RBNode *x = NULL, *xParent = NULL;

    if (!z->lchild) {
        x = z->rchild;
        xParent = z->parent;
        if (!z->parent) *root = z->rchild;
        else if (z == z->parent->lchild) z->parent->lchild = z->rchild;
        else z->parent->rchild = z->rchild;
        if (z->rchild) z->rchild->parent = z->parent;
    } else if (!z->rchild) {
        x = z->lchild;
        xParent = z->parent;
        if (!z->parent) *root = z->lchild;
        else if (z == z->parent->lchild) z->parent->lchild = z->lchild;
        else z->parent->rchild = z->lchild;
        if (z->lchild) z->lchild->parent = z->parent;
    } else {
        y = treeMinimum(z->rchild);
        yOriginalColor = y->color;
        x = y->rchild;
        xParent = y->parent;
        if (y->parent != z) {
            if (y->parent->lchild == y) y->parent->lchild = x;
            else y->parent->rchild = x;
            if (x) x->parent = y->parent;
            y->rchild = z->rchild;
            if (y->rchild) y->rchild->parent = y;
        }
        if (!z->parent) *root = y;
        else if (z == z->parent->lchild) z->parent->lchild = y;
        else z->parent->rchild = y;
        y->parent = z->parent;
        y->lchild = z->lchild;
        if (y->lchild) y->lchild->parent = y;
        y->color = z->color;
    }
    free(z);

    if (yOriginalColor == BLACK) deleteFixup(root, x, xParent);
}

/* ========== 遍历与可视化 ========== */

void printTree(RBTree root, int space) {
    if (!root) return;
    space += 6;
    printTree(root->rchild, space);
    printf("\n");
    for (int i = 6; i < space; i++) printf(" ");
    printf("%d(%s)\n", root->key, root->color == RED ? "R" : "B");
    printTree(root->lchild, space);
}

void inOrder(RBTree root) {
    if (!root) return;
    inOrder(root->lchild);
    printf("%d ", root->key);
    inOrder(root->rchild);
}

void freeTree(RBTree root) {
    if (!root) return;
    freeTree(root->lchild);
    freeTree(root->rchild);
    free(root);
}

/* ========== 测试程序 ========== */
int main() {
    RBTree root = NULL;
    int arr[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0;i<n;i++) RB_Insert(&root, arr[i]);

    printf("初始红黑树：\n");
    printTree(root,0);
    printf("\n中序遍历：");
    inOrder(root);
    printf("\n----------------------\n");

    int delArr[] = {20,30,10};
    for(int i=0;i<3;i++){
        printf("删除 %d:\n", delArr[i]);
        RB_Delete(&root, delArr[i]);
        printTree(root,0);
        printf("\n中序遍历：");
        inOrder(root);
        printf("\n----------------------\n");
    }

    freeTree(root);
    return 0;
}
