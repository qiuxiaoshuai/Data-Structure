#include <stdio.h>
#include <stdlib.h> // 为了 exit()

int main(){
    int a[9] = {0,5,5,3,5,1,5,5,7};
    int cont = 0;
    int num;
    for(int i=0;i<9;i++){
        if(cont == 0){
            num = a[i];
        }
        if(num == a[i]){
            cont++;
        }else{
            cont--;
        }
    }
    if(cont <= 0){
        printf("无主元素:%d",cont);
    }else{
        printf("主元素为：%d",num);
    }

}