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
    int min = p->data;
    while(p->next!=NULL){
       if(min > p->next->data){
        min = p->next->data;
        pre = p;
       }
       p = p->next;
    }
    if(pre == NULL){//�ж��Ƿ�Ϊͷ�ڵ�����
        Linkdata temp = *L;//����ͷ�ڵ�
        *L = (*L)->next;
        free(temp);
    }else{
        pre->next = pre->next->next;
    }

    printf("ɾ����Сֵ%d�������", min);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}