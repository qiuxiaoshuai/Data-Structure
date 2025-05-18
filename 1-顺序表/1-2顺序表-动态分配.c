#include <stdio.h>     // 引入标准输入输出头文件
#include <stdlib.h>    // 引入标准库头文件，包含 malloc 和 free 函数

#define InitSize 10    // 定义初始顺序表的容量为10

// 定义顺序表结构体
typedef struct {
    int *data;         // 指向动态分配内存的指针，用于存储数据元素
    int MaxSize;       // 当前顺序表的最大容量
    int length;        // 当前顺序表中已有元素的个数
} List;

// 初始化顺序表
void InitList(List *L) {
    L->data = (int *)malloc(InitSize * sizeof(int));  // 动态分配内存，大小为InitSize个int
// 1. malloc(...) 是做什么的？
// malloc 是 C 语言中用于动态内存分配的函数，来自 <stdlib.h>。
// 它的作用是：在堆内存中开辟一块指定大小的内存空间。
// 语法为：void *malloc(size_t size);
// 意思是：申请 size 字节的内存，返回一个 void*（通用指针）。
// 2. InitSize * sizeof(int)
// 这是计算需要分配多少字节的内存。
// InitSize 是你自己定义的宏，这里是 10。
// sizeof(int) 表示一个 int 类型变量所占的字节数，通常是 4 字节（但这取决于系统）。
// 所以 InitSize * sizeof(int) 就是：申请 10 个 int 类型的空间，也就是 10 * 4 = 40 字节。
// 3. (int *) 是什么意思？
// malloc 返回的是 void* 类型的指针，但我们需要的是 int* 类型（因为 data 是 int*），所以要进行强制类型转换。
// 也就是说：把返回的 void* 转成 int*，赋值给 L->data。
    L->length = 0;                                     // 初始化时顺序表长度为0
    L->MaxSize = InitSize;                             // 设置顺序表的最大容量
}

// 扩容顺序表容量
void IncreaseSize(List *L, int len) {
    int *p = L->data;                                        // 保存原始内存地址
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int)); // 重新分配更大容量的内存
    for (int i = 0; i < L->length; i++) {                    // 将原数组中的数据复制到新数组中
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;                          // 更新最大容量
    free(p);                                                // 释放原来的内存，避免内存泄漏
}

int main() {
    List L;               // 定义一个顺序表变量L
    InitList(&L);         // 初始化顺序表
    IncreaseSize(&L, 5);  // 将顺序表容量扩展5个单位

    free(L.data);         // 程序结束前释放动态分配的内存
    return 0;             // 正常结束程序
}
