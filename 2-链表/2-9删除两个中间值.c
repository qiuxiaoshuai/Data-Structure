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

int delNode(Linkdata *L,int a[],int x,int y,int lenth_a){
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
    Linkdata p = *L,pre = NULL;
    while(p->next != NULL){
        if(p->data>= x && p->data <= y){
            if(pre == NULL){//判断是否为头节点
                *L = p->next;
                p = *L;
            }else{
                pre->next = p->next;//上一个节点的下一个指向当前的节点的下一个值
                p = pre->next;//让当前节点回到p的下一个值
            }
        }else{
            pre = p;
            p = p->next;
        }
    }
    printf("删除%d~%d之间值的链表：",x,y);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,1,3,len_a);
}