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
    printf("������һ��������2�ļ��η���������");
    scanf("%d",&a);
    printf("2��%d�η�����%d",tow(a),a);
}