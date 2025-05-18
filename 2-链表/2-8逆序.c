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
    Linkdata p = *L,pre = NULL,next = NULL;//��������ָ�룬һ��Ϊ��ǰλ�õ�ָ�룬һ��Ϊ��ǰλ�õ���һ����ָ�룬һ��Ϊ��ǰλ�õ���һ��ָ��
    // NULL <-- [1]    [2] --> [3] --> [4]
    //         ��       ��       ��
    //         pre       p      next
    // NULL <-- [1] <-- [2]    [3] --> [4]
    //                 ��       ��
    //               pre       p
    //                         ��
    //                       next
    // NULL <-- [1] <-- [2] <-- [3]    [4]
    //                          ��     ��
    //                        pre     p
    //                                ��
    //                              next
    while(p != NULL){
        next = p->next;  // �ȱ��浱ǰ�ڵ����һ���ڵ㣬��ֹ����
        p->next = pre;   // ��תָ�룬��ǰ�ڵ�ָ��ǰһ���ڵ�
        pre = p;         // �ѵ�ǰ�ڵ��ɡ�ǰһ���ڵ㡱��Ϊ��һ��׼��
        p = next;        // �ƶ���֮ǰ�������һ���ڵ㣬����ѭ��
    }
    *L = pre;  // ��������ͷָ�룬ָ����ͷ�������ĵ�һ���ڵ㣩
    printf("����������");
    printList(*L);    
}
//����git
int main(){
    Linkdata L;
    int a[] = {0,1,7,6,5,4,3,1,1,0,-1,-2,-3};
    int len_a = sizeof(a) / sizeof(a[0]);
    delNode(&L,a,len_a);
}
