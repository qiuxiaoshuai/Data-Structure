#include<stdio.h>
#include<stdbool.h>
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

//[1]->NULL
//[2]->[1]->NULL
//[3]->[2]->[1]->NULL
// 最终链表顺序是：3 → 2 → 1

void carList(LinkNode *List,int a[],int lenth_a){
    *List = NULL;
    for(int i =0;i<lenth_a;i++){
        //每次创建一个Node标记当前数组a[i]的值
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        //s的下一个位置指向当前链表的位置
        s->next = *List;
        //更新链表
        *List = s;
    }
    printList(*List);
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    LinkNode L;
    int lenth_a = sizeof(a) / sizeof(a[0]);
    carList(&L,a,lenth_a);
    int *p = &a[1];
    printf("值：%d地址:%d",*p,p);
}