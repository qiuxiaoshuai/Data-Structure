#include<stdio.h>

int tow(int number){
    int n = 1;
    while((1 << n)<= number){
        n++;
    }
    return n;
}

int main(){
    int a;
    printf("请输入一个数，求2的几次方大于他：");
    scanf("%d",&a);
    printf("2的%d次方大于%d",tow(a),a);
}