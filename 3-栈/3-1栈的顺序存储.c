#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

// ��ʼ��ջ
void InitStack(SqStack *S) {
    S->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool IsEmpty(SqStack *S) {
    return S->top == -1;
}

// �ж�ջ�Ƿ�����
bool IsFull(SqStack *S) {
    return S->top == MaxSize - 1;
}

// ��ջ��һ��Ԫ�أ�
bool Push(SqStack *S, int x) {
    if (IsFull(S)) return false;
    S->data[++(S->top)] = x;
    return true;
}

// ��ջ��һ��Ԫ�أ�
bool Pop(SqStack *S, int *x) {
    if (IsEmpty(S)) return false;
    *x = S->data[(S->top)--];
    return true;
}

// ��ȡջ��Ԫ�أ�����ջ��
bool GetTop(SqStack *S, int *x) {
    if (IsEmpty(S)) return false;
    *x = S->data[S->top];
    return true;
}

// ����ջ�����ƻ���
void TraverseStack(SqStack *S) {
    if (IsEmpty(S)) {
        printf("ջΪ��\n");
        return;
    }
    printf("ջ���ݴ�ջ����ջ��Ϊ��");
    for (int i = S->top; i >= 0; i--) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}

// ���ջ
void ClearStack(SqStack *S) {
    S->top = -1;
}

int main() {
    SqStack S;
    InitStack(&S);

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);

    // ������ջ
    for (int i = 0; i < len; i++) {
        if (!Push(&S, arr[i])) {
            printf("ջ�������޷�ѹ��Ԫ�� %d\n", arr[i]);
        }
    }

    TraverseStack(&S);

    int x;
    while (Pop(&S, &x)) {
        printf("��ջԪ�أ�%d\n", x);
    }

    if (IsEmpty(&S)) {
        printf("ջ�ѿ�\n");
    }

    return 0;
}
