#include <stdio.h>
#include <stdlib.h>

#define MAXN 20

int n;
int input[MAXN];      // 入栈顺序
int stack[MAXN];      // 模拟栈
int top = -1;
int output[MAXN];     // 当前出栈序列
int count = 0;        // 统计方案数

// 回溯函数
void dfs(int inIndex, int outIndex) {
    // 如果所有元素都入栈过，且栈为空
    if (inIndex == n && top == -1) {
        count++;
        printf("方案 %d: ", count);
        for (int i = 0; i < n; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    // 选择：入栈（如果还有元素未入栈）
    if (inIndex < n) {
        stack[++top] = input[inIndex];     // 入栈
        dfs(inIndex + 1, outIndex);
        top--;                             // 回溯（撤销入栈）
    }

    // 选择：出栈（如果栈不为空）
    if (top >= 0) {
        int temp = stack[top--];          // 出栈
        output[outIndex] = temp;
        dfs(inIndex, outIndex + 1);
        stack[++top] = temp;              // 回溯（撤销出栈）
    }
}
int main() {
    printf("请输入元素个数 n: ");
    scanf("%d", &n);

    printf("请输入 %d 个元素的入栈顺序:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    dfs(0, 0);

    printf("总共有 %d 种出栈顺序。\n", count);
    return 0;
}
