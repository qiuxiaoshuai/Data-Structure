#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prior ,*next;
    //定义头尾节点
}Node,*Linkdata;

void printList(Linkdata List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}

int InitList(Linkdata *L,int arr[],int len_arr){
    //创建头节点
    Linkdata head = (Node *)malloc(sizeof(Node));
    head->prior = NULL;
    head->next = NULL;
    *L = head;//让L指向头节点
    Linkdata tali = head;//用于记录尾部
    Linkdata p = (Node *)malloc(sizeof(Node));
    for(int i=0;i<len_arr;i++){
        Linkdata s = (Node *)malloc(sizeof(Node));
        s->data = arr[i];
        s->next = NULL;
        s->prior = tali;
        tali->next = s;
        tali = s;
    }
    printList(head->next);
};

 int main(){
    Linkdata L;
    int a[] = {9,8,7,6,5,4,3,2,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    InitList(&L,a,len_a);
 }