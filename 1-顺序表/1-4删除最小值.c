#include<stdio.h>
#include <stdlib.h> // 为了 exit
#define Maxsize 10

typedef struct{
    int data[Maxsize];
    int leng;
}List;

void printfList(List *L){
    for(int i = 0;i<L->leng;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int delList(List *L){
    if(L->leng == 0){
        printf("List为空表");
        return 1;
    }
    int Min = L->data[0];
    int Min_index = 0;
    for(int i = 1;i<L->leng;i++){
        if(Min>L->data[i]){
            Min = L->data[i];
            Min_index = i;
        }
    }
    L->data[Min_index] = L->data[L->leng-1];
    printfList(L);
    return 0;
}

int main(){
    List L = {{-9,6,1,0,9},5};
    delList(&L);
}