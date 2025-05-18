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
    Linkdata p = *L,pre = NULL,next = NULL;//创建三个指针，一个为当前位置的指针，一个为当前位置的上一个的指针，一个为当前位置的下一个指针
    // NULL <-- [1]    [2] --> [3] --> [4]
    //         ↑       ↑       ↑
    //         pre       p      next
    // NULL <-- [1] <-- [2]    [3] --> [4]
    //                 ↑       ↑
    //               pre       p
    //                         ↑
    //                       next
    // NULL <-- [1] <-- [2] <-- [3]    [4]
    //                          ↑     ↑
    //                        pre     p
    //                                ↑
    //                              next
    while(p != NULL){
        next = p->next;  // 先保存当前节点的下一个节点，防止断链
        p->next = pre;   // 反转指针，当前节点指向前一个节点
        pre = p;         // 把当前节点变成“前一个节点”，为下一轮准备
        p = next;        // 移动到之前保存的下一个节点，继续循环
    }
    *L = pre;  // 更新链表头指针，指向新头（逆序后的第一个节点）
    printf("逆序后的链表：");
    printList(*L);    
}
//测试git
int main(){
    Linkdata L;
    int a[] = {0,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}
