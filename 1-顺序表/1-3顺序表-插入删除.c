#include<stdio.h>
#include<stdbool.h>//需要这个头文件才能执行布尔值
#define Maxsize 10

typedef struct{
    int data[Maxsize];
    int leng;
}List;

int carList(List *L,int number,int index){
    //判断长度是否已经超过边界
    if(L->leng>=Maxsize){
        return 1;
    }
    //判断index的位置，是否规范小于1或大于目前顺序表的长度（是否有越界的情况）
    if(index<1||index>L->leng+1){
        // return 1;
    }
    //当i大于替换的下标时，大于i的下标都往前移
    for(int i=L->leng;i>index;i--){
        L->data[i] = L->data[i-1];
    }
    L->data[index] = number;
    L->leng++;
    return 0;
}
int delList(List *L,int number,int index){
    if(index<1||index>L->leng){
        return 1;
    }
    for(int i=index;i<L->leng;i++){
        L->data[i]=L->data[i+1];
    }
    L->leng--;
    return 0;
}
void printfList(List *L){
    for(int i = 0;i<L->leng;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
int main(){
    List L = {{-10,3,5,6,8},5};
    //函数越界情况，不执行代码
    carList(&L,4,6);
    printfList(&L);
    //函数未越界
    carList(&L,4,5);
    printfList(&L);
    delList(&L,3,1);
    printfList(&L);
}