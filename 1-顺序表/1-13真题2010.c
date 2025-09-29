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

void dig(List *L,int a,int b){
    int temp;
    for(int i=0;i<(b-a+1)/2;i++){
        temp = L->data[i+a];
        L->data[i+a] = L->data[b-i];
        L->data[b-i] = temp;
    }
}

void fg(List *L,int n,int p){
    dig(L,0,p-1);
    dig(L,p,n-1);
    dig(L,0,n-1);
    printfList(L);
}

int main(){
    List L = {{1, 2, 3, 4, 5, 6}, 6};
    // qcList(&L);
    fg(&L,6,3);
}