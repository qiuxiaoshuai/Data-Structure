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

int main() {
    int n = 4;
    fun_tree(n, 0, 1);
    return 0;
}
