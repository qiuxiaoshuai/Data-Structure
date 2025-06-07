#include<stdio.h>
#include<stdbool.h>
#define Maxsize 10

typedef struct SqQueue{
    int data[Maxsize];
    int front,rear;
}SqQueue;

bool Init(SqQueue *Q,int x){
   if((Q->rear +1 ) % Maxsize != Q->front){
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear+1) % Maxsize;
        return true;
   }else{
        return false;
   }
}

bool del(SqQueue *Q,int *x){
    if(Q->front != Q->rear){
        *x = Q->data[Q->front];
        Q->front = (Q->front+1) % Maxsize;
        return true;
    }else
    {
        return false;
    }
    
}

int main(){
    SqQueue Q;
    Q.front = Q.rear = 0;
    for(int i = 0;i<6;i++){
        if(Init(&Q,i)){
            printf("入队成功: %d\n", i);
        }
    }
    int number;
    while(del(&Q,&number)){
        printf("出队成功:%d\n",number);
    }
}