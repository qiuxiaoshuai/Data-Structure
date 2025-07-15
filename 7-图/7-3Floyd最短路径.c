#include <stdio.h>
#include <limits.h>

#define MAX 100          // 最大顶点数量
#define INF INT_MAX      // 定义无穷大，用于表示两个点不可达

// Floyd 算法：求任意两点间最短路径
void floyd(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];   // dist[i][j] 表示 i 到 j 的最短路径长度
    int path[MAX][MAX];   // path[i][j] 表示 i 到 j 最短路径上 j 的前一个顶点

    // ===== 初始化 dist 和 path =====
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];       // 初始化为图中给出的权值
            if (i == j || graph[i][j] == INF)
                path[i][j] = -1;            // 自己到自己，或不可达，设为 -1
            else
                path[i][j] = i;             // 初始路径：从 i 到 j，前驱设为 i
        }
    }

    // ===== 三重循环核心：以 k 为中间点，更新所有 i 到 j 的路径 =====
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 只有 i→k 和 k→j 可达，才有资格更新 i→j
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // 如果通过 k 中转，路径更短，更新
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[k][j];  // 更新 j 的前驱为 k 路径上的前驱
                    }
                }
            }
        }
    }

    // ===== 输出最短路径长度矩阵 =====
    printf("任意两点最短路径长度矩阵：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    // ===== 示例：输出从顶点 0 到其他点的路径 =====
    printf("\n从顶点 0 到其他点的路径：\n");
    for (int j = 0; j < n; j++) {
        if (j == 0) continue;  // 不输出自己到自己
        if (dist[0][j] == INF) {
            printf("0 到 %d：不可达\n", j);
            continue;
        }

        // 回溯路径：从 j 逆着 path 回溯到 0
        int stack[MAX], top = 0;
        int current = j;
        while (current != 0) {
            stack[top++] = current;
            current = path[0][current];
        }

        // 打印路径
        printf("0");
        while (top > 0) {
            printf(" → %d", stack[--top]);
        }
        printf("（路径长度：%d）\n", dist[0][j]);
    }
}

// ===== 主函数：示例测试 =====
int main() {
    int n = 4; // 顶点数

    // 邻接矩阵初始化
    // graph[i][j] 表示 i 到 j 的边权；无边用 INF 表示
    int graph[MAX][MAX] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floyd(graph, n);

    return 0;
}
