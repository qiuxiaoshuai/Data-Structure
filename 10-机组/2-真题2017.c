#include<stdio.h>

int f1(unsigned n){
    int sum=1,power=1;
    for(unsigned i=0;i<=n-1;i++){
        power *= 2;
        sum +=power;
    }
    return sum;
}
float f2(unsigned n){
    float sum=1,power=1;
    for(unsigned i=0;i<=n-1;i++){
        power *= 2;
        sum +=power;
    }
    return sum;
}
int main(void){
    unsigned n;
    printf("请输入机器数的位数 n: ");
    scanf("%u", &n);

    int result = f1(n);
    printf("生成的机器数为: 0x%X\n", result);
    int result1 = f2(n);
    printf("生成的机器数为: 0x%X\n", result1);
    return 0;
}2