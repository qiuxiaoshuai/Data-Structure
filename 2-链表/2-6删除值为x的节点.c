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

int delNode(Linkdata *L,int a[],int number,int lenth_a){
    *L = NULL;
    for(int i =0;i<lenth_a;i++){
        //ÿ�δ���һ��Node��ǵ�ǰ����a[i]��ֵ
        Linkdata s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        //s����һ��λ��ָ��ǰ�����λ��
        s->next = *L;
        //��������
        *L = s;
    }
    printf("ԭ����");
    printList(*L);
    Linkdata p = *L,pre = NULL;//��������ָ�룬һ��Ϊ��ǰλ�õ�ָ�룬һ��Ϊ��ǰλ�õ���һ����ָ��
    // [1] --> [2] --> [3] --> [4]
    //      ��       ��
    //    prev      p

    while(p->next!=NULL){
        if(p->data == number){
            if(pre == NULL){ //�ж�����ɾ�����Ƿ�Ϊͷ�ڵ�
                *L = p->next;
                free(p);
                p = *L;
            }else{//ɾ�������м�ڵ��β�ڵ�
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
    printf("ɾ��%d�������", number);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,1,len_a);
}