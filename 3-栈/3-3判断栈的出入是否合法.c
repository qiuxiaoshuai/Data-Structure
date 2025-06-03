#include<stdio.h>
#include<stdbool.h>
#include <string.h> 
bool pd(char add[],int len){
    int sum = 0;
    for(int i=0;i<len;i++){
        if(add[i] == 'I'){
            sum++;
        }else if (add[i] == 'O')
        {
            sum--;
            if(sum<0){
                return false; 
            }
        }else{
            return false;   
        }    
    }
    return true;
}

int main(){
    // char arr[] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    char arr[100];
    printf("请输入栈序列（只包含I和O）：");
    scanf("%s",arr);
    //注意这里我设置的长度，因此不能在使用sizeof判断长度
    int len = strlen(arr);
    printf("%d\n",len);
    printf("%d",pd(arr,len));
}