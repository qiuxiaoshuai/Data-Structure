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

void ShareList(LinkNode *A,LinkNode *B,LinkNode *C){
    *C = (Node *)malloc(sizeof(Node));
    (*C)->next = NULL;
    LinkNode tail_A = (*A)->next,tail_B = (*B)->next,tail_C = *C;
    while(tail_A != NULL && tail_B != NULL){
        if(tail_A->data>tail_B->data){
            tail_B = tail_B->next;
        }else if (tail_A->data == tail_B->data)
        {
            LinkNode s = (Node *)malloc(sizeof(Node));
            s->data = tail_A->data;
            s->next = NULL;
            tail_C->next = s;
            tail_C = s;
            if(tail_A->next !=NULL && tail_A->next->data == tail_B->data){
                tail_A = tail_A->next;
            }else if (tail_B->next != NULL && tail_B->next->data == tail_A->data)
            {
                tail_B = tail_B->next;
            }else{
                tail_A = tail_A->next;
                tail_B = tail_B->next;
            }
        }else{
            tail_A = tail_A->next;
        }
    }
    printList((*C)->next);
}

int main(){
    LinkNode A,B,C;
    int a[] = {0,1,2,3,4,4,5,6},
    b[] = {3,4,5,6,7,8,9};
    int len_a = sizeof(a) / sizeof(a[0]),
    len_b = sizeof(b) / sizeof(b[0]);
    csrList(&A,a,len_a);
    csrList(&B,b,len_b);
    ShareList(&A,&B,&C);
}