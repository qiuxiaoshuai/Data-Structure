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

int delNode(Linkdata *L,int a[],int x,int y,int lenth_a){
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
    Linkdata p = *L,pre = NULL;
    while(p->next != NULL){
        if(p->data>= x && p->data <= y){
            if(pre == NULL){//�ж��Ƿ�Ϊͷ�ڵ�
                *L = p->next;
                p = *L;
            }else{
                pre->next = p->next;//��һ���ڵ����һ��ָ��ǰ�Ľڵ����һ��ֵ
                p = pre->next;//�õ�ǰ�ڵ�ص�p����һ��ֵ
            }
        }else{
            pre = p;
            p = p->next;
        }
    }
    printf("ɾ��%d~%d֮��ֵ������",x,y);
    printList(*L);    
}

int main(){
    Linkdata L;
    int a[] = {9,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,1,3,len_a);
}