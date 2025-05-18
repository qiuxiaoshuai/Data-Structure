#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    //定义头尾节点
}Node,*Linkdata;

void printList(Linkdata List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}

int delNode(Linkdata *L,int a[],int lenth_a){
    *L = NULL;
    for(int i =0;i<lenth_a;i++){
        //每次创建一个Node标记当前数组a[i]的值
        Linkdata s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        //s的下一个位置指向当前链表的位置
        s->next = *L;
        //更新链表
        *L = s;
    }
    printf("原链表：");
    printList(*L);
    Linkdata p = *L,pre = NULL;//创建两个指针，一个为当前位置的指针，一个为当前位置的上一个的指针
    // [1] --> [2] --> [3] --> [4]
    //      ↑       ↑
    //    prev      p
    int min = p->data;
    while(p->next!=NULL){
       if(min > p->next->data){
        min = p->next->data;
        pre = p;
       }
       p = p->next;
    }
    if(pre == NULL){//判断是否为头节点的情况
        Linkdata temp = *L;//储存头节点
        *L = (*L)->next;
        free(temp);
    }else{
        pre->next = pre->next->next;
    }

    printf("删除最小值%d后的链表：", min);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}