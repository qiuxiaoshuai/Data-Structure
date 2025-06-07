#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkNode;


void printList(LinkNode List){
    while(List != NULL){
        printf("%c ",List->data);
        List = List->next;
    }
    printf("\n");
}

void Init(LinkNode *L,char arr[],int len){
    *L = NULL;
    LinkNode p = NULL;
    for(int i=0;i<len;i++){
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = arr[i];
        s->next = NULL;
        if (*L == NULL) {
            *L = s;       // 第一个结点赋值给头指针
            p = s;
        } else {
            p->next = s;
            p = s;
        }
    }
    printList(*L);
}

int ifList(LinkNode L,int len){
    LinkNode p = L;
    for(int i = 0;i<len/2;i++){
        LinkNode q = L;
        for(int j = 0;j<len - i - 1;j++){
            q = q->next;
        }
        if (p->data != q->data){
            return 0;
        }
        p = p->next;
    }
    return 1;
}

int main(){
    char a[] = {'x','y','y','x'};
    LinkNode L;
    int lenth_a = sizeof(a) / sizeof(a[0]);
    Init(&L,a,lenth_a);
    printf("%d",ifList(L,lenth_a));
}