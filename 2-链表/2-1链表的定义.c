#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// typedef struct Node 定义结构体类型 struct Node：这就告诉编译器，“有一个叫 struct Node 的结构体，它有两个成员。”
// 结构体成员声明开始，也就是 { ... } 的部分。

typedef struct Node{
    int data;
    struct Node *next;
// 这是自引用。
// 结构体中定义了一个指针 next，它指向另一个 struct Node 类型的结构体，也就是下一个链表结点。
}Node,*LinkList;
// 把 struct Node 起一个新名字：Node
// 把 struct Node* 起一个新名字：LinkList
// Node 是结构体类型，表示的是一个链表节点本身；
// LinkLinst 是指针类型，表示的是一个“指向链表的头节点的指针”；
bool csrList(LinkList L){
    L = (Node *)malloc(sizeof(Node));
    L->data=0;
    //这里初始化的数据类型为int只能有整型表示
    L->next=NULL;
}               

int main(){
    Node L;
    csrList(&L);
}