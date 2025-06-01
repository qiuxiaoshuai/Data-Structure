#include<stdio.h>

void add(int x){
    x = 1024;
    printf("add形参的值:%d\n",x);
}
void app(int *x){
    *x = 1024;
    printf("app形参的值:%d\n",*x);
}

int main(){
    int x = 1;
    printf("调用add前：x=%d\n",x);
    add(x);
    printf("调用add后：x=%d\n",x);
    app(&x);
    // 传入的是地址，直接修改地址的值
    printf("调用add后：x=%d\n",x);
}