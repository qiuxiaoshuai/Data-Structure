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
//创建链表
int csh(LinkNode *L,int A[],int leng){
    *L = (Node *)malloc(sizeof(Node));
    (*L)->link = NULL;
    LinkNode list = *L;
    for(int i=0;i<leng;i++){
        LinkNode p = (Node *)malloc(sizeof(Node));
        p->data = A[i];
        p->link = NULL;
        list->link = p;
        list = p; 
    }
    printList((*L)->link); 
}

int add(LinkNode *L){
    int max = 0;
    LinkNode p = (*L)->link;
    while(p != NULL){
        if(max<abs(p->data)){
            max = abs(p->data);
        }
        p = p->link;
    }
    int *kj = (int *)malloc(sizeof(int) * max);

    for(int i =0;i<max;i++){
        kj[i] = 0;
    }
    // 第一次遍历统计次数
    p = (*L)->link;
    LinkNode q = (*L);
    while(p!=NULL){
        int idx = abs(p->data)-1;//确定绝对值数组的下标
        if(kj[idx] == 0){
            kj[idx] = 1;
            q = p;//跟新指针结点
            p = p->link;
        }else{
            LinkNode s = p;
            p = p->link;
            q->link = p;
            free(s);
        }
    }
    printList((*L)->link);
}

int main(){
    LinkNode L;
    int a[] = {21,-15,-15,-7,15};
    int len_a = sizeof(a) / sizeof(a[0]);
    csh(&L,a,len_a);
    add(&L);
}