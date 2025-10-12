#include <stdio.h>
#define MAXV 4   // 最大顶点数，可根据题目修改

// -----------------------------
// 图的邻接矩阵结构定义
// -----------------------------
typedef struct {
    int numVertices, numEdges;         // 图的顶点数与边数
    char VerticesList[MAXV];           // 顶点信息（未使用）
    int Edge[MAXV][MAXV];              // 邻接矩阵表示的边信息
} MGraph;

// -----------------------------
// 函数：判断图是否存在 EL（欧拉）路径
// 功能：统计奇数度顶点数，判断是否为 0 或 2
// -----------------------------
int add(MGraph G) {
    int deg = 0;      // 当前顶点的度
    int count = 0;    // 奇数度顶点计数

    // 遍历每个顶点
    for (int i = 0; i < G.numVertices; i++) {
        deg = 0;  // 每个顶点度数从0开始计数

        // 统计第 i 个顶点的度数
        for (int j = 0; j < G.numVertices; j++) {
            if (G.Edge[i][j] != 0)     // 若存在边 (i,j)
                deg++;                  // 度数加1
        }

        // 若该顶点度为奇数，则计数器加1
        if (deg % 2 == 1)
            count++;
    }

    // 根据奇数度顶点个数判断是否存在欧拉路径
    if (count == 2 || count == 0)
        return 1;   // 存在 EL 路径（欧拉路径或欧拉回路）
    else
        return 0;   // 不存在 EL 路径
}
