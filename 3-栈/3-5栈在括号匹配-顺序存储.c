#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char data[100];
    int top;
} SqStack;

void Init(SqStack *s){
    s->top = -1;
}

int Push(SqStack *s,char x){
    if(s->top == 100 - 1) return -1;
    s->data[++s->top] = x;
    return 1;
}

int Pop(SqStack *s,char *x){
    if(s->top == -1) return -1;
    *x = s->data[s->top--];
}

int IFStack(char add[],int len){
    SqStack s;
    Init(&s);
    for(int i=0;i<len;i++){
        if(add[i] == '(' || add[i] == '{' || add[i] == '['){
            Push(&s,add[i]);
        }else{
            if(s.top == -1){
                return -1;
            }
            char topElem;
            Pop(&s,&topElem);
            if ((add[i] == ')' && topElem != '(') ||
            (add[i] == ']' && topElem != '[') ||
            (add[i] == '}' && topElem != '{')) {
            return -1; // 如果不匹配，返回 0
    }    }
    }
    // 如果栈为空，表示所有括号都已匹配
    return 1;
}

int main() {
    char arr[] = {'{', '(', '(', ')', ')', '[', ']', '}'}; // 测试的括号数组
    // 调用 IFStack 函数，检查括号是否匹配
    printf("%d", IFStack(arr, sizeof(arr) / sizeof(arr[0])));  // 输出匹配结果：1 表示匹配，0 表示不匹配
}

