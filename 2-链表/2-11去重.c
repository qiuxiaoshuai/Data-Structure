#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkNode;

void printf_List(LinkNode L){
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    }
    printf("\n");
}

void NextList(LinkNode *L,int a[],int len){
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
    LinkNode tail = (*L);
    for(int i=0;i<len;i++){
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    printf_List((*L)->next);//这里要从头节点的尾指针开始打印
}

void QucList(LinkNode *L){
    LinkNode head = (*L),p = (*L)->next;
    while(p != NULL){
        if(head->data == p->data){
            p = p->next;
        }else{
            head->next = p;
            head = p;
            p = p->next;
        }
    }
    printf_List((*L)->next);
}

int main(){
    LinkNode L;
    int a[] = {7,10,10,21,30,42,42,42,51,70};
    int len = sizeof(a) / sizeof(a[0]);
    NextList(&L,a,len);
    QucList(&L);
}