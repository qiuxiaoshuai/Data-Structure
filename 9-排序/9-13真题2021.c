#include<stdio.h>
#include<stdlib.h>

void cmp(int a[],int b[],int n){
    int i,j,*count;
    count = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++) count[i]=0;
    for(i=0;i<n-1;i++){
        for(j = i+1;j<n;j++){
            if(a[i]<a[j]) count[j]++;
            else count[i]++;
        }
    }
    for(i=0;i<n;i++) b[count[i]] = a[i];
    for(i=0;i<n;i++) printf("%d ",b[i]);
}

int main(){
    int a[] = {25,-10,25,10,11,19},b[6];
    cmp(a,b,6);
}