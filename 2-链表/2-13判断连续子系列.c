#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkNode;

void printList(LinkNode List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}

int csrList(LinkNode *L,int a[],int len_a){
    *L = (Node *)malloc(sizeof(Node)); // 创建头结点（不存数据）
    (*L)->next = NULL;
    LinkNode tail = *L; // 尾指针初始化为头结点

    for (int i = 0; i < len_a; i++) {
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    printList((*L)->next); 
}

int ContinuousList(LinkNode *A,LinkNode *B,int len_A,int len_B){
    LinkNode tail_A = (*A)->next,tail_B = (*B)->next;
    while(tail_A == NULL && tail_B == NULL){
        if(tail_A->data != tail_B->data){
            len_A--;
            tail_A =tail_A->next;
        }
    }
}