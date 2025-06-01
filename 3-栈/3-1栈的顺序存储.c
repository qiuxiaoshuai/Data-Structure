#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack *S) {
    S->top = -1;
}

// 判断栈是否为空
bool IsEmpty(SqStack *S) {
    return S->top == -1;
}

// 判断栈是否已满
bool IsFull(SqStack *S) {
    return S->top == MaxSize - 1;
}

// 入栈（一个元素）
bool Push(SqStack *S, int x) {
    if (IsFull(S)) return false;
    S->data[++(S->top)] = x;
    return true;
}

// 出栈（一个元素）
bool Pop(SqStack *S, int *x) {
    if (IsEmpty(S)) return false;
    *x = S->data[(S->top)--];
    return true;
}

// 获取栈顶元素（不出栈）
bool GetTop(SqStack *S, int *x) {
    if (IsEmpty(S)) return false;
    *x = S->data[S->top];
    return true;
}

// 遍历栈（不破坏）
void TraverseStack(SqStack *S) {
    if (IsEmpty(S)) {
        printf("栈为空\n");
        return;
    }
    printf("栈内容从栈顶到栈底为：");
    for (int i = S->top; i >= 0; i--) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}

// 清空栈
void ClearStack(SqStack *S) {
    S->top = -1;
}

int main() {
    SqStack S;
    InitStack(&S);

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);

    // 批量入栈
    for (int i = 0; i < len; i++) {
        if (!Push(&S, arr[i])) {
            printf("栈已满，无法压入元素 %d\n", arr[i]);
        }
    }

    TraverseStack(&S);

    int x;
    while (Pop(&S, &x)) {
        printf("出栈元素：%d\n", x);
    }

    if (IsEmpty(&S)) {
        printf("栈已空\n");
    }

    return 0;
}
