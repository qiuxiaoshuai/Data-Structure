#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkNode;

void printList(LinkNode L) {
    if (L == NULL) return;
    LinkNode p = L;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != L);
    printf("\n");
}


void csrList(LinkNode *L, int a[], int len) {
    *L = (LinkNode)malloc(sizeof(Node)); // 创建头结点
    (*L)->next = *L; // 指向自身形成空循环
    LinkNode tail = *L; // 初始化尾指针为头结点

    for (int i = 0; i < len; i++) {
        LinkNode s = (LinkNode)malloc(sizeof(Node));
        s->data = a[i];
        s->next = *L;      // 新节点指向头结点
        tail->next = s;    // 尾节点指向新节点
        tail = s;          // 更新尾节点
    }

    // 从第一个数据节点开始打印
    printList((*L)->next);
}


int linkLinst(LinkNode *h1,LinkNode *h2){
    LinkNode head_a = (*h1),//保留头节点
    head_b = (*h2);
    while(head_a->next != (*h1)){
        head_a = head_a->next;
    }
    while(head_b->next != (*h2)){
        head_b = head_b->next;
    }
    head_a->next = (*h2)->next;
    head_b->next = (*h1);
    printList((*h1)->next);
}
int main(){
    LinkNode h1,h2;
    int a[] = {1,2,1};
    int len_a = sizeof(a) / sizeof(a[0]);
    int b[] = {11,22,11};
    int len_b = sizeof(b) / sizeof(b[0]);
    csrList(&h1,a,len_a);
    csrList(&h2,b,len_b);
    linkLinst(&h1,&h2);
}
