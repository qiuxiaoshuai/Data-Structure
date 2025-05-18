#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prior ,*next;
    //����ͷβ�ڵ�
}Node,*Linkdata;

void printList(Linkdata List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}

int InitList(Linkdata *L,int arr[],int len_arr){
    //����ͷ�ڵ�
    Linkdata head = (Node *)malloc(sizeof(Node));
    head->prior = NULL;
    head->next = NULL;
    *L = head;//��Lָ��ͷ�ڵ�
    Linkdata tali = head;//���ڼ�¼β��
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
//����
int carList(Linkdata *L,int number,int index){
    Linkdata p = *L;
    for(int i=0;i<index;i++){
        p = p->next; //һֱ���µ���Ҫ����ڵ��λ��
    }
    Linkdata s = (Node *)malloc(sizeof(Node));
    s->data = number;
    s->next = p->next;//���½ڵ� s �ĺ��ָ��ԭ�� p �ĺ��
    s->prior = p;//���½ڵ� s ��ǰ��ָ�� p
    if(p->next!=NULL){
        //�ж��Ƿ�Ϊ��
        p->next->prior = s; //�ؼ��� B ֪����ǰ�滻����
    }
    p->next = s;//�� p �ĺ��ָ���½ڵ� s
    printList((*L)->next);
}
//ɾ��
void delList(Linkdata *L,int index){
    Linkdata p = *L;
    for(int i=0;i<index;i++){
        p = p->next;//�ѵ�ǰ�ڵ���µ�Ҫɾ����λ��
    }
    if(p == NULL || p->next == NULL){
        printf("λ�÷Ƿ�orԽ��\n");
        return;
    }
    Linkdata q = p->next; //Ҫɾ���Ľڵ�
    if(q->next != NULL){
        q->next->prior = p;//�ؼ��� q ֪����ǰ�滻����
    }
    p->next = q->next;
    free(q);//�ͷű�ɾ���ڵ���ڴ�
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