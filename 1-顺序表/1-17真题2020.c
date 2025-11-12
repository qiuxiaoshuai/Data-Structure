#include <stdio.h>
#include <stdlib.h>

/*
 * bll: 计算三元组 (a,b,c) 的“跨度”度量，这里定义为 2*(max - min)
 * 返回值：非负整数
 * 说明：直接用一次比较找出最大值与最小值，避免逻辑错误。
 */
int bll(int a, int b, int c) {
    // 先假设 a 是最大值和最小值，然后逐步修正
    int max = a;
    int min = a;

    // 更新 max
    if (b > max) max = b;
    if (c > max) max = c;

    // 更新 min
    if (b < min) min = b;
    if (c < min) min = c;

    return 2 * (max - min);
}

/*
 * all: 在三个已排序的数组 S1(n1), S2(n2), S3(n3) 中寻找三元组 (x,y,z)
 *      使得 bll(x,y,z) 最小（即最小的 2*(max-min)）。
 *
 * 思路（经典三指针法）：
 *   - 初始化 q=w=e=0 指向每个数组的起点
 *   - 每次计算当前三元组的跨度 cd = bll(S1[q], S2[w], S3[e])
 *   - 若 cd 更小则更新全局最优解
 *   - 找到当前三元组中的最小元素（基于 S1[q],S2[w],S3[e]），将对应指针向右移动，
 *     因为移动最小元素可能会减小 max-min 的范围（或有机会找到更接近的三元组）
 *   - 循环直到任一指针越界
 *
 * 注意：调用此函数前应保证 S1,S2,S3 已按非降序排序。
 */
void all(int S1[], int n1, int S2[], int n2, int S3[], int n3) {
    int q = 0, w = 0, e = 0; // 三个指针
    // 初始化最优三元组为数组首元素
    int best_a = S1[0], best_b = S2[0], best_c = S3[0];
    int bestD = bll(best_a, best_b, best_c);

    // 主循环：任一数组到末尾就没有完整三元组了
    while (q < n1 && w < n2 && e < n3) {
        int a = S1[q];
        int b = S2[w];
        int c = S3[e];

        // 计算当前三元组的跨度
        int cd = bll(a, b, c);

        // 若更优则更新记录
        if (cd < bestD) {
            bestD = cd;
            best_a = a;
            best_b = b;
            best_c = c;
        }

        // 决定移动哪个指针：移动当前三元组中的最小元素对应的指针
        // 这一步非常关键：应使用当前 (a,b,c) 而不是用“历史最佳”值
        if (a <= b && a <= c) {
            q++; // S1 的当前元素是最小的，向右移动 q
        } else if (b <= a && b <= c) {
            w++; // S2 的当前元素是最小的，向右移动 w
        } else {
            e++; // S3 的当前元素是最小的，向右移动 e
        }
    }

    // 输出结果（加上换行符更友好）
    printf("最短距离为: %d, 相对应的三元组为 (%d, %d, %d)\n", bestD, best_a, best_b, best_c);
}

int main() {
    int S1[] = {-1, 0, 9};
    int S2[] = {-25, -10, 10, 11};
    int S3[] = {2, 9, 17, 30, 41};

    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int n3 = sizeof(S3) / sizeof(S3[0]);

    // 调用并打印结果
    all(S1, n1, S2, n2, S3, n3);

    return 0;
}
