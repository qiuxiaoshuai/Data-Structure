#include<stdio.h>
#include<stdbool.h>//��Ҫ���ͷ�ļ�����ִ�в���ֵ
#define Maxsize 10

typedef struct{
    int data[Maxsize];
    int leng;
}List;

int carList(List *L,int number,int index){
    //�жϳ����Ƿ��Ѿ������߽�
    if(L->leng>=Maxsize){
        return 1;
    }
    //�ж�index��λ�ã��Ƿ�淶С��1�����Ŀǰ˳���ĳ��ȣ��Ƿ���Խ��������
    if(index<1||index>L->leng+1){
        // return 1;
    }
    //��i�����滻���±�ʱ������i���±궼��ǰ��
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
    //����Խ���������ִ�д���
    carList(&L,4,6);
    printfList(&L);
    //����δԽ��
    carList(&L,4,5);
    printfList(&L);
    delList(&L,3,1);
    printfList(&L);
}