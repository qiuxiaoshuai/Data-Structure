#include <stdio.h>
#include <stdlib.h> // 为了 exit()
#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int leng;
} List;

int all(List *S1,List *S2,int leng){
    int a=0,b=0;
    for(int i = 0;i<leng-1;i++){
        if(S1->data[a]>S2->data[b]){
            b++;
        }else{
            a++;
        }
    }
    printf("中位数为:%d",S1->data[a] > S2->data[b] ? S2->data[b] : S1->data[a]);
}

int main(){
    List S1 = {{11, 13, 15, 17}, 4};
    List S2 = {{2, 4, 6, 8}, 4};
    all(&S1,&S2,4);
}