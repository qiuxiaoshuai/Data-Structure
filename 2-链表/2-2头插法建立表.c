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
// ��������˳���ǣ�3 �� 2 �� 1

void carList(LinkNode *List,int a[],int lenth_a){
    *List = NULL;
    for(int i =0;i<lenth_a;i++){
        //ÿ�δ���һ��Node��ǵ�ǰ����a[i]��ֵ
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        //s����һ��λ��ָ��ǰ�����λ��
        s->next = *List;
        //��������
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
    printf("ֵ��%d��ַ:%d",*p,p);
}