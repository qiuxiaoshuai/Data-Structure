#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构，用于栈的实现
typedef struct LinkNode {
    char data;           // 栈中存储的元素
    struct LinkNode *next; // 指向下一个栈元素的指针
} LinkNode, *LinkSrack;   // LinkSrack 是栈的指针类型，指向 LinkNode 结构体

// 初始化栈，栈顶指针置为空
void Init(LinkSrack *top) {
    *top = NULL;  // 初始化栈顶指针为 NULL
}

// 向栈中压入一个元素
void Push(LinkSrack *top, char x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));  // 创建新的栈节点
    s->data = x;          // 将元素赋值给栈节点
    s->next = *top;       // 新节点的 next 指向当前栈顶
    *top = s;             // 更新栈顶指针指向新节点
}

// 从栈中弹出一个元素
int Pop(LinkSrack *top, char *x) {
    if (*top == NULL) {  // 判断栈是否为空
        printf("栈为空\n"); // 如果为空，打印提示信息
        return 0; // 返回失败
    }
    LinkNode *temp = *top;    // 临时保存栈顶元素
    *x = temp->data;          // 将栈顶元素的值赋给 x
    *top = temp->next;        // 更新栈顶指针，指向下一个元素
    free(temp);               // 释放原栈顶节点的内存
    return 1;                 // 返回成功
}

// 检查给定字符串中的括号是否匹配
// add[] 是括号字符数组，leng 是数组长度
int IFStack(char add[], int leng) {
    LinkSrack s;
    Init(&s);  // 初始化栈

    // 遍历字符串中的每个字符
    for (int i = 0; i < leng; i++) {
        // 如果是开括号，则将其压入栈中
        if (add[i] == '(' || add[i] == '{' || add[i] == '[') {
            Push(&s, add[i]);
        } else { // 如果是闭括号
            // 如果栈为空，说明没有对应的开括号，返回 0 表示匹配失败
            if (s == NULL) {
                return 0;
            }
            char topElem; // 用于存储栈顶元素
            Pop(&s, &topElem); // 弹出栈顶元素
            // 检查当前的闭括号是否与栈顶元素的开括号匹配
            if ((add[i] == ')' && topElem != '(') ||
                (add[i] == ']' && topElem != '[') ||
                (add[i] == '}' && topElem != '{')) {
                return 0; // 如果不匹配，返回 0
            }
        }
    }

    // 如果栈为空，表示所有括号都已匹配
    return 1;
}

int main() {
    char arr[] = {'{', '(', '(', ')', ')', '[', ']', '}'}; // 测试的括号数组
    // 调用 IFStack 函数，检查括号是否匹配
    printf("%d", IFStack(arr, sizeof(arr) / sizeof(arr[0])));  // 输出匹配结果：1 表示匹配，0 表示不匹配
}
