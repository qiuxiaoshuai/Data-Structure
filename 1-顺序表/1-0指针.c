#include<stdio.h>

void add(int x){
    x = 1024;
    printf("add�βε�ֵ:%d\n",x);
}
void app(int *x){
    *x = 1024;
    printf("app�βε�ֵ:%d\n",*x);
}

int main(){
    int x = 1;
    printf("����addǰ��x=%d\n",x);
    add(x);
    printf("����add��x=%d\n",x);
    app(&x);
    // ������ǵ�ַ��ֱ���޸ĵ�ַ��ֵ
    printf("����add��x=%d\n",x);
}