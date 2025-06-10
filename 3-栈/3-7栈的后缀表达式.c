#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000  // 定义最大数组长度

// 返回运算符的优先级
int precedence(char op) {
    if(op == '+' || op == '-') return 1;  // 加减优先级低
    if(op == '*' || op == '/') return 2;  // 乘除优先级高
    return 0;
}

// 判断是否是运算符
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 将中缀表达式转换为后缀表达式（逆波兰表达式）
// 参数：infix 为输入的中缀表达式，postfix 为输出的后缀表达式
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];  // 栈用于存放运算符
    int top = -1;     // 栈顶指针
    int j = 0;        // 后缀表达式下标

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // 如果是数字，处理多位数
        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];  // 复制数字字符
            }
            postfix[j++] = ' ';  // 数字后加空格分隔
            i--;  // 回退一个字符，因为循环多加了1
        } 
        else if (c == '(') {
            stack[++top] = c;  // 左括号压栈
        } 
        else if (c == ')') {
            // 遇到右括号，弹出直到遇到左括号
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') top--;  // 弹出左括号
        } 
        else if (isOperator(c)) {
            // 遇到运算符，弹出优先级不低于它的运算符
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = c;  // 当前运算符入栈
        }
    }

    // 弹出剩余栈中运算符
    while (top >= 0) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';  // 字符串结束符
}

// 计算后缀表达式的值
// 参数：postfix 为输入的后缀表达式
// 返回：计算结果（int）
int evaluatePostfix(char* postfix) {
    int stack[MAX];  // 用数组实现栈
    int top = -1;    // 栈顶指针
    int i = 0;

    while (postfix[i] != '\0') {
        // 如果是数字，读取完整数字并入栈
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');  // 字符转数字
            }
            stack[++top] = num;
            printf("入栈: %d\t当前栈: ", num);
            for (int k = 0; k <= top; k++) printf("%d ", stack[k]);
            printf("\n");
        } 
        // 如果是运算符，弹出两个操作数，计算后入栈
        else if (isOperator(postfix[i])) {
            int b = stack[top--];  // 右操作数
            int a = stack[top--];  // 左操作数
            int res = 0;
            switch (postfix[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            stack[++top] = res;
            printf("运算: %d %c %d = %d\t当前栈: ", a, postfix[i], b, res);
            for (int k = 0; k <= top; k++) printf("%d ", stack[k]);
            printf("\n");
            i++;  // 移动到下一个字符
        } 
        else if (postfix[i] == ' ') {
            i++;  // 空格跳过
        } 
        else {
            i++;  // 忽略其他字符
        }
    }

    return stack[top];  // 最终结果在栈顶
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("请输入中缀表达式（如 (12+3)*2 ）：");
    fgets(infix, sizeof(infix), stdin);           // 读取用户输入
    infix[strcspn(infix, "\n")] = '\0';           // 移除换行符

    infixToPostfix(infix, postfix);               // 中缀转后缀
    printf("后缀表达式：%s\n", postfix);          // 输出后缀表达式

    int result = evaluatePostfix(postfix);        // 计算后缀表达式
    printf("最终结果：%d\n", result);             // 输出结果

    return 0;
}
