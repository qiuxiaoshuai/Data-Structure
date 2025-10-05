#include <stdio.h>

void fun_tree(int x, int depth, int is_last) {
    // 打印缩进和分支符号
    for(int i = 0; i < depth - 1; i++) {
        printf("│   ");
    }
    if(depth > 0) {
        if(is_last)
            printf("└──");
        else
            printf("├──");
    }

    // 打印当前节点
    printf("fun(%d)\n", x);

    if(x == 0 || x == 1) {
        for(int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("return 1\n");
    } else {
        // 递归调用
        fun_tree(x - 1, depth + 1, 1);
        for(int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("return %d * fun(%d) = %d\n", x, x - 1, x * 1); // 最终返回值可以再用变量存，暂时显示计算公式
    }
}

int f(int x) {
    static int depth = 0;  // 用静态变量追踪递归深度
    for (int i = 0; i < depth; i++) {
        printf("│   ");  // 打印每一层的缩进
    }
    printf("fun(%d)\n", x);

    // 基本情况
    if (x > 0) {
        depth++;  // 递归前增加深度
        int result = x * f(x - 1);  // 递归调用
        depth--;  // 返回时减少深度
        for (int i = 0; i < depth; i++) {
            printf("│   ");  // 打印每一层的缩进
        }
        printf("return %d * fun(%d) = %d\n", x, x - 1, result);  // 打印返回值
        return result;
    } else {
        // 基础情况
        for (int i = 0; i < depth; i++) {
            printf("│   ");  // 打印每一层的缩进
        }
        printf("return 2\n");  // 基础返回值
        return 2;
    }
}


int main() {
    int n = 4;
    fun_tree(n, 0, 1);
    printf("%d",f(f(1)));
}
