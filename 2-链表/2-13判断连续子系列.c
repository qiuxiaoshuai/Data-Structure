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
    if(*B == NULL)return 1;//判断是否为空集，空集合是全部的子集合
    LinkNode tail_A = (*A),tail_B = (*B);
    while(*A){
        if(tail_A->data == tail_B->data){
            LinkNode tail_A = (*A),tail_B = (*B);
            while(tail_A && tail_B && tail_A == tail_B){
                tail_A = tail_A->next;
                tail_B = tail_B->next;
        }
        if(tail_B == NULL)return 1;
        }
        *A = (*A)->next;
    }
    return 0;   
}

int main(){
    LinkNode A,B;
    int a[] = {0,1,2,3,4,4,5,6},
    b[] = {3,4,4};
    int len_a = sizeof(a) / sizeof(a[0]),
    len_b = sizeof(b) / sizeof(b[0]);
    csrList(&A,a,len_a);
    csrList(&B,b,len_b);
    printf("%d",ContinuousList(&A,&B,len_a,len_b));
}
