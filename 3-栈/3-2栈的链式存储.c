#include<stdio.h>
#include<stdlib.h>
typedef struct Linknode{
    int data;
    struct Linknode *next;  
} Linknode, *LinkStack;

// ��ʼ��ջ������Ϊ��ջ��
void InitStack(LinkStack *top) {
    *top = NULL;
}

//��ջ
void Push(LinkStack *top,int x){
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    if(!p){
        printf("�ڴ����ʧ��!\n");
    }
    p->data = x;
    p->next = *top;
    *top = p;
}

//��ջ
int Pop(LinkStack *top,int *x){
    if(*top == NULL){
        printf("ջΪ��\n");
    }
    Linknode *tamp = *top;
    *x = tamp->data;//��ȡ��ǰ��ջ��Ԫ��
    *top = tamp->next;//��ջ��ָ��ָ����һ���ڵ㣨��ջ��
    free(tamp);
}

//���ջԪ��!!! ���ﴫ���topֻ�Ǹ������ı�ԭָ��
void printfStack(LinkStack top){
    printf("\n");
    printf("��ǰջ����ջ��\n");
    while(top){
        printf("%d\n",top->data);
        top = top->next;
    }
}

int main(){
    LinkStack s;
    InitStack(&s);
    int arr[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0;i<sizeof(arr) / sizeof(arr[0]);i++){
        Push(&s,arr[i]);
    }
    printfStack(s);
}