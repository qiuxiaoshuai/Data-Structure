#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// typedef struct Node ����ṹ������ struct Node����͸��߱�����������һ���� struct Node �Ľṹ�壬����������Ա����
// �ṹ���Ա������ʼ��Ҳ���� { ... } �Ĳ��֡�

typedef struct Node{
    int data;
    struct Node *next;
// ���������á�
// �ṹ���ж�����һ��ָ�� next����ָ����һ�� struct Node ���͵Ľṹ�壬Ҳ������һ�������㡣
}Node,*LinkList;
// �� struct Node ��һ�������֣�Node
// �� struct Node* ��һ�������֣�LinkList
// Node �ǽṹ�����ͣ���ʾ����һ������ڵ㱾��
// LinkLinst ��ָ�����ͣ���ʾ����һ����ָ�������ͷ�ڵ��ָ�롱��
bool csrList(LinkList L){
    L = (Node *)malloc(sizeof(Node));
    L->data=0;
    //�����ʼ������������Ϊintֻ�������ͱ�ʾ
    L->next=NULL;
}               

int main(){
    Node L;
    csrList(&L);
}