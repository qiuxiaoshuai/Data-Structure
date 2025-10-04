#include<stdio.h>
#include<string.h>
typedef struct {
    char data[255];
    int lenght;
}SString;

void PrintfString(SString str){
    for(int i=0;i<str.lenght;i++){
        printf("%c",str.data[i]);
    }
    printf("\n");
}

int Algorithm(SString a,SString b){
    for(int i=0;i<=a.lenght-b.lenght;i++){
        int j = 0;//设定子串的头指针，每次查找失败时返回头部
        for(;j<b.lenght;j++){
            if(a.data[i+j] != b.data[j]){
                break;
            }
        }
        if(j==b.lenght){
            return i; //找到匹配
        }
    }
    return -1; //未找到匹配
}

int main(){
    SString s = { .data = "Hadoop Java C++", .lenght = strlen("Hadoop Java C++") };
    PrintfString(s);
    SString b = { .data = "Java", .lenght = strlen("Java") };
    PrintfString(b);
    printf("%d",Algorithm(s,b));
}