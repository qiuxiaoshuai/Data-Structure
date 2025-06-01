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

//head->[1]->NULL
// head->[1]->[2]->NULL
// head->[1]->[2]->[3]->NULL

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


int main(){
    LinkNode L;
    int a[] = {9,8,7,6,5,4,3,2,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    csrList(&L,a,len_a);
}