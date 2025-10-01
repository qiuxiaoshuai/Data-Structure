#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node,*LinkNode;

void printList(LinkNode List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->link;
    }
    printf("\n");
}
int csh(LinkNode *L,int A[],int leng){
    *L = (Node *)malloc(sizeof(Node));
    (*L)->link = NULL;
    LinkNode list = *L;
    for(int i=0;i<leng;i++){
        LinkNode p = (Node *)malloc(sizeof(Node));
        p->data = A[i];
        p->link = NULL;
        list->link = p;
        list = p; //更新链表
    }
    printList((*L)->link); 
}

int add(LinkNode L,int k){
    LinkNode p = L->link;
    int cont = 0;
    while(p != NULL){
        p = p->link;
        cont++;
    }
    if(k>cont || k < 0){
        return 0;
    }
    p = L->link;
    for(int i=0;i<cont-k;i++){
        p = p->link;
    }
    printf("倒数第%d的值为:%d",k,p->data);
    return 1;
}

int main(){
    LinkNode L;
    int a[] = {9,8,7,6,5,4,3,2,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    csh(&L,a,len_a);
    add(L,100);
}