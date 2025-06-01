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

void qcList(List *L){
    for(int i = 0;i<L->leng;i++){
        //这里的j不动,因为顺序表的删除，是从后面移位到前面，当出现以下的情况时，可能就会出现漏删除的情况
        // [5, 5, 5, 6]
        //  ↑  ↑
        //  i  j
//         删除 L->data[1]
// 数组变为： [5, 5, 6]
//            ↑     ↑
//            i     j=2 (自动++了)
        for(int j = i+1;j<L->leng;){
            if (L->data[i] == L->data[j]){
                for(int g = j;g<L->leng;g++){
                    L->data[g] = L->data[g+1];
                }
                L->leng--;
            }
            else{
                j++;
            }
        }
    }
    printfList(L);
}

int main(){
    List L = {{-3, 5, 1, 5, 5, 6}, 6};
    qcList(&L);
}