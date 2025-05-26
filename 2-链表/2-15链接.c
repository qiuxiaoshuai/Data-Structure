#include<stdio.h>
#include<stdlib.h>
//½«h2Á´½Óµ½h1
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkNode;

void printList(LinkNode L) {
    if (L == NULL) return;
    LinkNode p = L;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != L);
    printf("\n");
}

void IjList(LinkNode *h1,LinkNode *h2){
    LinkNode tali_h1 = (*h1),tali_h2 = (*h2);
    while(tali_h1->next != (*h1)){
        tali_h1 = tali_h1->next;
    }
    tali_h1->next = tali_h2;
    while(tali_h2->next != (*h2)){
        tali_h2 = tali_h2->next;
    }
    tali_h2->next = (*h1);
    printList((*h1));
}

void InitList(LinkNode *L,int arr[],int len){
    (*L) = (Node *)malloc(sizeof(Node));
    (*L)->data = arr[0];
    (*L)->next = NULL;
    LinkNode tali = (*L);
    for(int i = 1;i<len;i++){
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = arr[i];
        s->next = NULL;
        tali->next = s;
        tali = s;
    }
    tali->next = (*L);
    printList(*L);
}

int main(){
    LinkNode h1,h2;
    int a[] = {1,2,1};
    int len_a = sizeof(a) / sizeof(a[0]);
    int b[] = {11,22,11};
    int len_b = sizeof(b) / sizeof(b[0]);
    InitList(&h1,a,len_a);
    InitList(&h2,b,len_b);
    IjList(&h1,&h2);
}
