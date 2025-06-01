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
    *L = (Node*)malloc(sizeof(Node));
    (*L)->next = NULL;
    Linkdata A = (Node*)malloc(sizeof(Node));//初始化链表
    Linkdata B = (Node*)malloc(sizeof(Node));
    A->next = NULL;
    B->next = NULL;
    Linkdata tail = *L;
    for(int i =0;i<lenth_a;i++){
        Linkdata s = (Node*)malloc(sizeof(Node));
        s->data = a[i];
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    printf("原链表：");
    printList((*L)->next);
    Linkdata p = (*L)->next;//创建三个指针，一个为当前位置的指针，一个为当前位置的上一个的指针，一个为当前位置的下一个指针
    int number = 1;//分辨是奇数还是偶数
    Linkdata tailA = A,tailB = B;
    while(p != NULL){
        Linkdata s = (Node *)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        if(number % 2 == 1){
            tailA->next = s;
            tailA = s;
        }else{
            tailB->next = s;
            tailB = s;
        }
        p = p->next;
        number++;
    }
    printf("奇数位链表 A：");
    printList(A->next);
    printf("奇数位链表 B：");
    printList(B->next);
}

//测试git
int main(){
    Linkdata L;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}
