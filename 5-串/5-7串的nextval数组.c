#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 求模式串的 nextval 数组
void computeNextval(char *pattern, int *nextval) {
    int m = strlen(pattern);
    nextval[0] = -1;  // nextval[0] = -1, 因为没有前缀和后缀

    int j = -1;  // j 是最长的前后缀的长度
    for (int i = 1; i < m; i++) {
        // 处理模式串的下一个字符
        while (j >= 0 && pattern[i] != pattern[j + 1]) {
            j = nextval[j];  // 如果不匹配，则回溯
        }
        
        if (pattern[i] == pattern[j + 1]) {
            j++;  // 匹配成功，前缀长度加 1
        }
        
        // 如果当前字符匹配，但下一个字符仍然重复，避免重复计算
        if (pattern[i] == pattern[j + 1]) {
            nextval[i] = nextval[j];
        } else {
            nextval[i] = j;
        }
    }
}

// 打印 nextval 数组
void printNextval(int *nextval, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nextval[i]);
    }
    printf("\n");
}

// 计算滑动距离
int calculateSlideDistance(int *nextval, int j) {
    if (nextval[j] == -1) {
        return 1;  // 如果 nextval[j] == -1，则滑动1个位置
    } else {
        return j - nextval[j] + 1;  // 否则，滑动的距离是 j - nextval[j] + 1
    }
}

int main() {
    char pattern[255];
    printf("请输入模式串: ");
    scanf("%s", pattern);

    int m = strlen(pattern);
    int *nextval = (int *)malloc(m * sizeof(int));  // 动态分配内存
    if (nextval == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    computeNextval(pattern, nextval);

    printf("Nextval 数组为：\n");
    printNextval(nextval, m);

    // 自动计算每个位置的滑动距离
    printf("模式串每个位置的滑动距离为：\n");
    for (int j = 0; j < m; j++) {
        int slideDistance = calculateSlideDistance(nextval, j);
        printf("当前位置 %d 时，滑动的距离是：%d\n", j, slideDistance);
    }

    free(nextval);  // 释放内存
    return 0;
}
