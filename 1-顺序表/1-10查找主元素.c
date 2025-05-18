#include<stdio.h>

int zuys(int arr[],int n){
    int count = 0;
    int number;
    for(int i=0;i<n;i++){
        if(count == 0){
            number = arr[i];
            count = 1;
        }else if (number != arr[i])
        {
            count--;
        }else{
            count++;
        }
    }
    count = 0;
    for(int i=0;i<n;i++){
        if (number == arr[i])
        {
            count++;
        }
    }
    if(count > n/2){
        return number;
    }else{
        return -1;
    }
}

int main(){
    int arr[] = {0,5,5,3,5,7,5,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\nn=%d",zuys(arr,n),n);
}