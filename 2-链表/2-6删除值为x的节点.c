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

int delNode(Linkdata *L,int a[],int number,int lenth_a){
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

    while(p->next!=NULL){
        if(p->data == number){
            if(pre == NULL){ //判断这里删除的是否为头节点
                *L = p->next;
                free(p);
                p = *L;
            }else{//删除的是中间节点或尾节点
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    printf("删除%d后的链表：", number);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,1,len_a);
}