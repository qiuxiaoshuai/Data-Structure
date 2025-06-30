#include<stdio.h>

int fun(int x){
    if(x == 0 || x == 1){
        return 1;
    }else{
        // printf("%d\n");
        return x * fun(x-1);
    }
}
int main(){
    printf("%d",fun(4));
}