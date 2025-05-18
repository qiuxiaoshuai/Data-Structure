#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int Miss(int a[],int n){
    int i,*B;
    B = (int *)malloc(sizeof(int)*n);
    memset(B,0,sizeof(int)*n);
    for(i=0;i<n;i++){
        if(a[i]>0&&a[i]<=n){
            B[a[i]-1]=1;
        }
    }
    for(i = 0;i<n;i++){
        if (B[i]==0) break;
    }
    return i+1;
}
int main(){
    int a[]={-5,3,2,3,1,4,410};
    printf("%d",Miss(a,sizeof(a)/sizeof(a[0])));
}