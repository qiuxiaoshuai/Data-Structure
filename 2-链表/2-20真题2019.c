#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

// 打印链表
void printList(NODE *List) {
    while (List != NULL) {
        printf("%d ", List->data);
        List = List->next;
    }
    printf("\n");
}

// 创建链表（尾插法）
void csh(NODE **L, int A[], int leng) {
    *L = (NODE *)malloc(sizeof(NODE)); // 建立头结点
    (*L)->next = NULL;
    NODE *list = *L; // 尾指针

    for (int i = 0; i < leng; i++) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = A[i];
        p->next = NULL;
        list->next = p; // 插入到尾部
        list = p;       // 更新尾指针
    }

    printList((*L)->next); // 打印链表（跳过头结点）
}

// 重排函数：L' = (a1, an, a2, an-1, ...)
void reorder(NODE **L) {
    // Step 1: 使用快慢指针找到链表中点
    // slow 每次走一步，fast 每次走两步
    NODE *slow = (*L)->next, *fast = (*L)->next;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;        // 慢指针走一步
        fast = fast->next->next;  // 快指针走两步
    }
    // 此时 slow 指向前半段的最后一个结点

    // Step 2: 断开链表并反转后半部分
    NODE *second = slow->next; // 后半部分的起点
    slow->next = NULL;         // 断开前后两部分
    
    NODE *prev = NULL, *cur = second;
    while (cur != NULL) {      // 常规链表反转
        NODE *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    NODE *p2 = prev;           // 反转后的后半部分头指针

    // Step 3: 合并两个链表（前半部分和反转后的后半部分）
    NODE *p1 = (*L)->next;     // 前半部分的头指针
    while (p1 != NULL && p2 != NULL) {
        // 暂存下一步要处理的节点
        NODE *t1 = p1->next;
        NODE *t2 = p2->next;

        // 将 p2 插入到 p1 之后
        p1->next = p2;
        p2->next = t1;

        // 两个指针向前移动
        p1 = t1;
        p2 = t2;
    }

    printList((*L)->next);
}


int main() {
    NODE *L;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    csh(&L, arr, n);
    reorder(&L);
    return 0;
}
