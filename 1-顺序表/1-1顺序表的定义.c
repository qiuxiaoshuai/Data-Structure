#include<stdio.h>
#define MaxSize 10

// typedef 是 C 语言中的一个关键字
// 它的作用是：为已有的数据类型（例如结构体）起一个简单的别名
// 使用 typedef 后可以直接写 sqList 来定义该结构体类型，而不需要每次都写 struct {...}

// struct 定义的是一个结构体
typedef struct{
    int Data[MaxSize];
    int leng;
}sqList;

void InitList(sqList *L){
    for(int i = 0; i < MaxSize; i++){
        L->Data[i] = i;
    }
    L->leng = 0;
}

// InitList 函数的参数是 sqList *L，即指向结构体的指针。
// 在 main 函数中，L 是一个普通结构体变量，我们传地址进去。
// 所以，访问结构体成员的方式就会不同：
// 类型           访问方式      示例
// 普通结构体变量   用 .        L.Data[i]
// 结构体指针       用 ->       L->Data[i]

// sqList L;    // 普通变量
// sqList *p;   // 指针

// p = &L;      // p 指向 L

// p->Data[0] 与 (*p).Data[0] 是一样的，-> 是对 (*p).成员 的简写
int main(){
    sqList L;
    InitList(&L);
    for(int i = 0; i < MaxSize; i++){
        printf("%d", L.Data[i]);
    }
    printf("\n长度为: %d", L.leng);
}
