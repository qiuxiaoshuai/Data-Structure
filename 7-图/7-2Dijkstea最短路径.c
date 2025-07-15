#include <stdio.h>
#include <limits.h> // 提供 INT_MAX，代表无穷大

#define MAX 100      // 最大顶点数
#define INF INT_MAX  // 定义无穷大，用于表示不可达

// Dijkstra 算法函数
// graph：邻接矩阵（边权）
// n：顶点数
// start：起点编号（从0开始）
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];      // dist[i]：起点到顶点 i 的最短距离
    int visited[MAX];   // visited[i]：是否已确定最短路径
    int i, j;
    int minDist, u;

    // 初始化：起点到各点距离设置为图中原始值，visited都设为0
    for (i = 0; i < n; i++) {
        dist[i] = graph[start][i];  // 初始距离是直接连通的边权值
        visited[i] = 0;             // 所有点都未被访问
    }

    dist[start] = 0;     // 起点到自身距离为0
    visited[start] = 1;  // 起点标记为已访问

    // 主循环，共进行 n-1 次，逐个找出最短路径的顶点
    for (i = 1; i < n; i++) {
        minDist = INF;
        u = -1;

        // 找出未访问中 dist 最小的顶点 u
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // 如果没有可访问的顶点（即剩下的是不可达的点）
        if (u == -1) break;

        visited[u] = 1;  // 标记 u 已访问

        // 更新 u 的邻接点的最短路径
        for (j = 0; j < n; j++) {
            // 若 j 未访问，且 u 到 j 有边，且从 start 到 j 的距离可以通过 u 更短
            if (!visited[j] && graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];  // 更新最短路径
            }
        }
    }

    // 输出结果
    printf("起点 %d 到各顶点的最短距离：\n", start);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("→ 顶点 %d：不可达\n", i);
        else
            printf("→ 顶点 %d：距离 %d\n", i, dist[i]);
    }
}

// 主函数：测试 Dijkstra 算法
int main() {
    int n = 5; // 顶点个数

    // 邻接矩阵表示图（graph[i][j] 是 i 到 j 的权重）
    // 若无边连接，则设为 INF
    int graph[MAX][MAX] = {
        {0,   INF,  1, INF,  10},
        {INF, 0,   INF,  1, 5},
        {INF, 1, 0,   INF, 7},
        {INF, INF, INF,  0,   1},
        {INF, INF, INF, INF, 0}
    };

    int start = 0; // 起点设置为0号顶点

    dijkstra(graph, n, start);

    return 0;
}
