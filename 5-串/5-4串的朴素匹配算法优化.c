#include<stdio.h>
#include<string.h>

typedef struct {
    char data[255];
    int lenght;
} SString;

void PrintfString(SString str) {
    for (int i = 0; i < str.lenght; i++) {
        printf("%c", str.data[i]);
    }
    printf("\n");
}

// 计算坏字符表，表中记录每个字符最后一次出现在模式串中的位置
void BuildBadCharTable(SString pattern, int badCharTable[256]) {
    for (int i = 0; i < 256; i++) {
        badCharTable[i] = -1; // 初始化为-1，表示字符不在模式串中
    }
    for (int i = 0; i < pattern.lenght; i++) {
        badCharTable[(unsigned char)pattern.data[i]] = i; // 记录字符最后出现的位置
    }
}

// 朴素算法的坏字符优化
int OptimizedAlgorithm(SString a, SString b) {
    int badCharTable[256]; // 坏字符表
    BuildBadCharTable(b, badCharTable); // 构建坏字符表

    int i = 0; // 主串的扫描指针
    while (i <= a.lenght - b.lenght) {
        int j = b.lenght - 1; // 模式串的扫描指针，开始从后往前比较

        // 比较主串的当前位置和模式串的字符
        while (j >= 0 && a.data[i + j] == b.data[j]) {
            j--;
        }

        if (j < 0) {
            // 找到匹配，返回匹配的位置
            return i;
        } else {
            // 根据坏字符规则跳过不必要的比较
            char badChar = a.data[i + j];
            int badCharIndex = badCharTable[(unsigned char)badChar];

            // 根据坏字符的位置计算跳过的距离
            int shift = j - badCharIndex;
            if (shift < 0) {
                shift = 1; // 如果坏字符在模式串中找不到，则移动一个字符
            }

            i += shift; // 更新主串的扫描位置
        }
    }

    return -1; // 如果没有匹配，返回-1
}

int main() {
    SString s = { .data = "Hadoop Java C++", .lenght = strlen("Hadoop Java C++") };
    PrintfString(s);

    SString b = { .data = "Java", .lenght = strlen("Java") };
    PrintfString(b);

    printf("%d", OptimizedAlgorithm(s, b)); // 输出匹配的位置
}
