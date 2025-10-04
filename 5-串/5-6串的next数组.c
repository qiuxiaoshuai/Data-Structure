#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // 包含 malloc 和 free 函数

// 求模式串的 next 数组
void computeNext(char *pattern, int *next) {
    int m = strlen(pattern);
    next[0] = 0; // next[0] = 0, 因为没有前缀和后缀

    int j = 0; // 前缀长度
    for (int i = 1; i < m; i++) {
        // 处理模式串的下一个字符
        while (j > 0 && pattern[i] != pattern[j]) {
            // 如果不匹配，则回溯
            j = next[j - 1];
        }
        
        if (pattern[i] == pattern[j]) {
            // 匹配成功，前缀长度加 1
            j++;
        }
        
        next[i] = j; // 设置 next 数组的值
    }
}

void printNext(int *next, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");
}

int main() {
    char pattern[255];
    printf("请输入模式串: ");
    scanf("%s", pattern);

    int m = strlen(pattern);
    int *next = (int *)malloc(m * sizeof(int)); // 动态分配内存
    if (next == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    computeNext(pattern, next);

    printf("Next 数组为：\n");
    printNext(next, m);

    free(next); // 释放内存
    return 0;
}
