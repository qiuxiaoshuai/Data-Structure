#include<stdio.h>
#include<stdbool.h>
#define Maxsize 10

typedef struct SqQueue{
    int data[Maxsize];
    int front,rear;
}SqQueue;

bool Init(SqQueue *Q,int x){
    //�ж϶�β�Ƿ����
    if(Q->rear != Maxsize -1){
        Q->data[Q->rear++] = x;
        return true;
    }else{
        return false;
    }
}

bool del(SqQueue *Q,int *x){
    //�ж϶����Ƿ�Ϊ��
    if(Q->front != Q->rear){
        *x = Q->data[Q->front++] ;
        return x;
    }else{
        return false;
    }
}

int main(){
    SqQueue Q;
    Q.front = Q.rear = 0;
    for(int i = 0;i<6;i++){
        if(Init(&Q,i)){
            printf("��ӳɹ�: %d\n", i);
        }
    }
    int number;
    while(del(&Q,&number)){
        printf("���ӳɹ�:%d\n",number);
    }
}