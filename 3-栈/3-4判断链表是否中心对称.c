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

int pd(LinkNode *L){
    LinkNode p=(*L),q=(*L);
    while(q!=NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    //找到中间节点
    LinkNode head = p;
    q = p->next;
    head->next = NULL;
    while(q!=NULL){
        LinkNode s = q->next;
        q->next = head->next;
        head->next = q;
        q = s;
    }
    LinkNode left = (*L),right = head->next;
    while(right != NULL){
        if(left->data != right->data){
            return -1;
        }
        left = left->next;
        right = right->next;
    }
    return 1;
}
int main(){
    char a[] = {'x','y','y','x'};
    LinkNode L;
    int lenth_a = sizeof(a) / sizeof(a[0]);
    Init(&L,a,lenth_a);
    printf("%d\n",ifList(L,lenth_a));
    printf("%d",pd(&L));
    
}