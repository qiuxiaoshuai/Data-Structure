#include <stdio.h>
#include <stdlib.h>    // �����׼��ͷ�ļ������� malloc �� free ����
int add(int A[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    int *b = (int *)malloc(sizeof(int) * max);
    for(int i=0;i<max;i++){
        b[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(A[i] > 0 && A[i]<=max){
            b[A[i]-1] = 1;
        }
    }
    
    int foun = 0;
    for(int i=0;i<max;i++){
        if(b[i] == 0){
            printf("δ������С����Ϊ��%d",i+1);
            foun = 1;
            break;
        }
    }
    if(!foun){
        printf("δ������С����Ϊ��%d",max+1);
    }
}
int main(){
    int A[] = {-5,2,3};
    int n = sizeof(A) / sizeof(A[0]);
    add(A, n);
    return 0;
}