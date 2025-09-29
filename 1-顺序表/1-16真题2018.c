#include <stdio.h>
#include <stdlib.h>    // 引入标准库头文件，包含 malloc 和 free 函数
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
            printf("未出现最小整数为：%d",i+1);
            foun = 1;
            break;
        }
    }
    if(!foun){
        printf("未出现最小整数为：%d",max+1);
    }
}
int main(){
    int A[] = {-5,2,3};
    int n = sizeof(A) / sizeof(A[0]);
    add(A, n);
    return 0;
}