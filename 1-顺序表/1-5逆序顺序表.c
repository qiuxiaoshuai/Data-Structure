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

//{1,2,3,4,5,6}6
void nixuList(List *L){
    int right = L->leng-1;
    for(int letf = 0;letf<L->leng/2;letf++){
        int tmp = L->data[letf];
        L->data[letf] = L->data[right];
        L->data[right] = tmp;
        right--;
    }
    printfList(L);
}

void all(List *L){
    int temp;
    for(int i=0;i<L->leng/2;i++){
        temp = L->data[i];
        L->data[i] = L->data[L->leng-i];
        L->data[L->leng-i] = temp;
    }
}
int main(){
    List L = {{1,2,3,4,5,6},6};
    nixuList(&L);
    List L1 = {{1,2,3,4,5},5};
    nixuList(&L1);
}