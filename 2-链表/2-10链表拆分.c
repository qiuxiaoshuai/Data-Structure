#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    //����ͷβ�ڵ�
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
    Linkdata A = (Node*)malloc(sizeof(Node));//��ʼ������
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
    printf("ԭ����");
    printList((*L)->next);
    Linkdata p = (*L)->next;//��������ָ�룬һ��Ϊ��ǰλ�õ�ָ�룬һ��Ϊ��ǰλ�õ���һ����ָ�룬һ��Ϊ��ǰλ�õ���һ��ָ��
    int number = 1;//�ֱ�����������ż��
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
    printf("����λ���� A��");
    printList(A->next);
    printf("����λ���� B��");
    printList(B->next);
}

//����git
int main(){
    Linkdata L;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}
