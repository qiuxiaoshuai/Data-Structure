#include <stdio.h>
#include <stdlib.h> 
#define Maxsize 10

typedef struct {
    int data[10];
    int leng;
} List;

void printfList(List *L) {
    for(int i = 0; i < L->leng; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
int carList(List *L,int m,int n){
    int tmpList[Maxsize];
    int index = 0;
    //把第一个线性表存放在数组中
    for(int i = 0;i<m;i++){
        tmpList[i] = L->data[i];
    }
    //在第一个顺序表中交换第二个顺序表的值
    for(int i = 0;i<n;i++){
        L->data[i] = L->data[i+m];
    }
    for(int i = n;i<L->leng;i++){
        L->data[i] = tmpList[index];
        index++;
    }
    printfList(L);
}

int main(){
    List L = {{1,4,9,-1,-1,-1,-1},7};
    carList(&L,3,4);
}