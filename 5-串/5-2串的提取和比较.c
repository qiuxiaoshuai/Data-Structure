#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 顺序串结构定义
typedef struct {
    char ch[100]; // 字符数组，不使用 \0，手动管理长度
    int length;   // 实际字符串长度
} SString;

// 打印字符串内容
void PrintSString(SString s) {
    for (int i = 0; i < s.length; i++) {
        putchar(s.ch[i]);
    }
    printf("\n");
}

// 子串提取函数：从 S 中第 pos 个位置（0 开始）起提取 len 个字符到 str
int Substring(SString *str, SString S, int pos, int len) {
    if (pos < 0 || pos + len > S.length) {
        return 0; // 越界检查
    }

    for (int i = 0; i < len; i++) {
        str->ch[i] = S.ch[pos + i];
    }
    str->length = len;
    return 1;
}

// 字符串比较：返回第一个不相等字符的差值，或长度差
int strbi(SString a, SString b) {
    int minLen = (a.length < b.length) ? a.length : b.length;
    for (int i = 0; i < minLen; i++) {
        if (a.ch[i] != b.ch[i]) {
            return a.ch[i] - b.ch[i];
        }
    }
    return a.length - b.length;
}

// 字符串定位：在 S 中查找子串 b，返回 b 在 S 中第一次出现的位置（从 0 开始）
// 若未找到，返回 -1
int Index(SString S, SString b) {
    int n = S.length;
    int m = b.length;
    SString sub;

    for (int i = 0; i <= n - m; i++) {
        if (Substring(&sub, S, i, m)) {
            if (strbi(sub, b) == 0) {
                return i; // 找到，返回位置
            }
        }
    }
    return -1; // 未找到
}

int main() {
    SString s = { .ch = "HelloWorld", .length = 10 };
    SString sub;
    SString b = { .ch = "ll", .length = 2 };

    // 子串提取演示
    if (Substring(&sub, s, 2, 4)) {  // 应输出 lloW
        printf("提取的子串为：");
        PrintSString(sub);
    } else {
        printf("子串提取失败（越界）\n");
    }

    // 字符串比较演示
    printf("字符串比较结果：%d\n", strbi(s, b));  // s 与 b 的差值

    // 字符串定位演示
    int pos = Index(s, b);
    if (pos != -1) {
        printf("子串 \"%.*s\" 在主串中第一次出现的位置是：%d\n", b.length, b.ch, pos);
    } else {
        printf("未找到该子串。\n");
    }

    return 0;
}
