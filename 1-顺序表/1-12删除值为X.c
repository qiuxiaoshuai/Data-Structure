#include <stdio.h>
#include <stdlib.h> // 为了 exit()
#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int leng;
} List;

void printfList(List *L) {
    for(int i = 0; i < L->leng; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int del(List *L,int x){
    int k=0;
    for(int i=0;i<L->leng;i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->leng = k;
}


int main() {
    List L = {{-3, 0, 1, 2, 5, 6}, 6};

    del(&L,1);

    printfList(&L);
}
