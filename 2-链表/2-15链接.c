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

void csrList(LinkNode *L,int a[],int len){
    (*L) = (Node*)malloc(sizeof(Node));
    (*L)->next = (*L);
    LinkNode head = (*L);
    for(int i =0;i<len;i++){
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->next = NULL;
        head->next = s;
        head = s;
    } 
    // printList((*L)->next);
}

int linkLinst(LinkNode *h1,LinkNode *h2){
    
}
int main(){
    LinkNode L;
    int a[] = {1,2,1};
    int len_a = sizeof(a) / sizeof(a[0]);
    csrList(&L,a,len_a);
}
