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
//插入
int carList(Linkdata *L,int number,int index){
    Linkdata p = *L;
    for(int i=0;i<index;i++){
        p = p->next; //一直更新到需要插入节点的位置
    }
    Linkdata s = (Node *)malloc(sizeof(Node));
    s->data = number;
    s->next = p->next;//让新节点 s 的后继指向原来 p 的后继
    s->prior = p;//让新节点 s 的前驱指向 p
    if(p->next!=NULL){
        //判断是否为空
        p->next->prior = s; //关键让 B 知道它前面换人了
    }
    p->next = s;//让 p 的后继指向新节点 s
    printList((*L)->next);
}
//删除
void delList(Linkdata *L,int index){
    Linkdata p = *L;
    for(int i=0;i<index;i++){
        p = p->next;//把当前节点更新到要删除的位置
    }
    if(p == NULL || p->next == NULL){
        printf("位置非法or越界\n");
        return;
    }
    Linkdata q = p->next; //要删除的节点
    if(q->next != NULL){
        q->next->prior = p;//关键让 q 知道它前面换人了
    }
    p->next = q->next;
    free(q);//释放被删除节点的内存
    printList((*L)->next);
}
 int main(){
    Linkdata L;
    int a[] = {9,8,7,6,5,4,3,2,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    InitList(&L,a,len_a);
    carList(&L,100,2);
    delList(&L,1);
 }