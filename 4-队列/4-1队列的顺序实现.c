#include<stdio.h>
#include<stdbool.h>
#define Maxsize 10

typedef struct SqQueue{
    int data[Maxsize];
    int front,rear;
}SqQueue;

bool Init(SqQueue *Q,int x){
    //判断队尾是否溢出
    if(Q->rear != Maxsize -1){
        Q->data[Q->rear++] = x;
        return true;
    }else{
        return false;
    }
}

bool del(SqQueue *Q,int *x){
    //判断队伍是否为空
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
            printf("入队成功: %d\n", i);
        }
    }
    int number;
    while(del(&Q,&number)){
        printf("出队成功:%d\n",number);
    }
}