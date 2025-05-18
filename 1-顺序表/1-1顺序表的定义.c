#include<stdio.h>
#define MaxSize 10

// typedef 是C语言里的类型重命名关键字
// 它的作用是：给复杂的类型（比如结构体）起一个简单的别名
// 这样你以后可以直接写 sqList 来声明这种结构体类型，而不需要每次都写 struct {...}

// struct定义了一个结构体
typedef struct{
    int Data[MaxSize];
    int leng;
}sqList;

void InitList(sqList *L){
    for(int i = 0;i<MaxSize;i++){
        L->Data[i]=i;
    }
    L->leng=0;
}

// InitList 函数的参数是 sqList *L —— 这是指向结构体的指针。
// main 函数中，L 是一个普通结构体变量，不是指针。
// 所以，访问结构体成员的方式不同：
// 情况	           访问方式	      示例
// 普通结构体变量	用 .	L.Data[i]
// 结构体指针	用 ->	L->Data[i]

// sqList L;    // 普通变量
// sqList *p;   // 指针

// p = &L;      // p指向L

// p->Data[0] 和 (*p).Data[0] 是一回事，-> 是对 (*p).成员 的简写
int main(){
    sqList L;
    InitList(&L);
    for(int i = 0;i<MaxSize;i++){
        printf("%d",L.Data[i]);
    }
    printf("\n长度为:%d",L.leng);
}