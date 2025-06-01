#include <stdio.h>
#include <stdlib.h> // 为了 exit()
#define Maxsize 10

typedef struct List{
    int *data;
    int leng;
} List;

void printfList(List *L) {
    for(int i = 0; i < L->leng; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

void csList(List *L,int arr[],int leng){
    L->data = (int *)malloc(leng * sizeof(int));
    for(int i=0;i<leng;i++){
        L->data[i] = arr[i];
    }
    L->leng = leng;
    printfList(L);
    printf("%d\n",L->leng);
}

void hbList(List *L_1,List *L_2){
    for(int i = 0;i<L_2->leng;i++){
        for(int j = 0;j<L_1->leng;j++){
            if(L_1->data[j]>L_2->data[i]){
                L_1->leng++;
                L_1->data = (int *)realloc(L_1->data,L_1->leng * sizeof(int));
                for(int z = L_1->leng-1;z>j;z--){
                    L_1->data[z] = L_1->data[z-1];
                }
                L_1->data[j] = L_2->data[i];
                break;
            }
        }
    }
    printfList(L_1);
}

int main(){
    int arr_1[] = {-5,4,9,133};
    int arr_2[] = {-1,0,8,9,100};
    List L_1 ,L_2;
    csList(&L_1,arr_1,sizeof(arr_1) / sizeof(int));
    csList(&L_2,arr_2,sizeof(arr_2) / sizeof(int));
    hbList(&L_1,&L_2);
}