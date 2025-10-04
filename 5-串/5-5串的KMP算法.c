#include <stdio.h>
#include <string.h>

typedef struct {
    char data[255];
    int lenght;
} SString;

// 打印字符串
void PrintfString(SString str) {
    for (int i = 0; i < str.lenght; i++) {
        printf("%c", str.data[i]);
    }
    printf("\n");
}

// 构造 next 数组
void Next(SString pattern, int next[]) {
    int i = 0;       // 当前计算next的模式串位置
    int k = -1;      // 代表当前最长相等真前缀和真后缀长度的下标（-1代表无）
    next[0] = -1;    // 约定起始

    while (i < pattern.lenght - 1) {
        // 如果k==-1，表示还没找到合适的前缀，或者pattern[i] == pattern[k]，可以扩展最长公共前后缀
        if (k == -1 || pattern.data[i] == pattern.data[k]) {
            i++;   // 计算下一个位置的next
            k++;   // 扩展匹配的最长公共前后缀长度
            next[i] = k;
        } else {
            // 不匹配时，k回退到上一个最长公共前后缀的位置
            k = next[k];
        }
    }
}


// KMP 主函数，返回匹配到的位置(从0开始)，找不到返回-1
int KMP(SString text, SString pattern) {
    int i = 0; // text索引
    int j = 0; // pattern索引

    int next[255];
    Next(pattern, next);

    while (i < text.lenght && j < pattern.lenght) {
        if (j == -1 || text.data[i] == pattern.data[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == pattern.lenght) {
        return i - j; // 返回匹配的起始下标
    } else {
        return -1; // 未匹配成功
    }
}

int main() {
    SString text = { .data = "Hadoop Java C++", .lenght = (int)strlen("Hadoop Java C++") };
    SString pattern = { .data = "Java", .lenght = (int)strlen("Java") };

    printf("文本串: ");
    PrintfString(text);
    printf("模式串: ");
    PrintfString(pattern);

    int pos = KMP(text, pattern);
    if (pos != -1) {
        printf("匹配成功，位置: %d\n", pos);
    } else {
        printf("未找到匹配\n");
    }

    return 0;
}
