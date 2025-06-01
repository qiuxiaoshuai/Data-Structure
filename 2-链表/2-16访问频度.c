#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data,freq;
    struct Node *next,*pre;
}Node,*LinkList;

void PrintfList(LinkList L){
    while(L != NULL){
        printf("--|data:%d|freq:%d|--",L->data,L->freq);
        L = L->next;
    }
    printf("\n");
}

void InitList(LinkList *L,int add[],int len){
    LinkList head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->pre = NULL;
    *L = head;
    LinkList tail = head;
    for(int i=0;i<len;i++){
        LinkList s = (Node *)malloc(sizeof(Node));
        s->data = add[i];
        s->freq = 0;
        s->next = NULL;
        s->pre = tail;
        tail->next = s;
        tail = s;
    }
    PrintfList(head->next);
}

int Locate(LinkList L,int x){
    //增加freq
    LinkList p = L;
    while(p != NULL){
        if(p->data == x){
            p->freq += 1;
            break;
        }
        p = p->next;
    }
    if(p == NULL) return 0;
    //根据freq的大小冒泡排序
    while (p->pre != L && p->freq > p->pre->freq) {
    LinkList q = p->pre;

    // 从链表中断开 p
    q->next = p->next;
    if (p->next != NULL)
        p->next->pre = q;

    // 插入到 q 前面
    p->pre = q->pre;
    if (q->pre != NULL)
        q->pre->next = p;

    p->next = q;
    q->pre = p;
    }
    PrintfList(L->next);
}

 int main(){
    LinkList L;
    int a[] = {1,2,3,4};
    int len_a = sizeof(a) / sizeof(a[0]);
    InitList(&L,a,len_a);
    Locate(L,4);
    Locate(L,3);
    Locate(L,4);
 }