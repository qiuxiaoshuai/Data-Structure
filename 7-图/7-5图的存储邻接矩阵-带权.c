#include <stdio.h>
#define MAXV 100
#define INF  32767  // 无穷大表示无边

// 带权图结构定义
typedef struct {
    char vexs[MAXV];        // 顶点表
    int arcs[MAXV][MAXV];   // 邻接矩阵（存权值）
    int vexnum, arcnum;     // 顶点数和边数
} MGraph;

// 创建带权图
void CreateWeightedGraph(MGraph *G) {
    int i, j, k, w;
    char v1, v2;

    printf("请输入顶点数和边数(空格分隔): ");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    // 输入顶点信息
    printf("请输入各顶点名称(单字符): ");
    for (i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vexs[i]);
    }

    // 初始化邻接矩阵
    for (i = 0; i < G->vexnum; i++) {
        for (j = 0; j < G->vexnum; j++) {
            if (i == j)
                G->arcs[i][j] = 0;
            else
                G->arcs[i][j] = INF;
        }
    }

    // 输入边信息
    printf("请输入各边(格式: 顶点1 顶点2 权值)\n");
    for (k = 0; k < G->arcnum; k++) {
        scanf(" %c %c %d", &v1, &v2, &w);

        int p1 = -1, p2 = -1;
        for (i = 0; i < G->vexnum; i++) {
            if (G->vexs[i] == v1) p1 = i;
            if (G->vexs[i] == v2) p2 = i;
        }
        if (p1 != -1 && p2 != -1) {
            G->arcs[p1][p2] = w;
            // 若为无向图则加上：
            // G->arcs[p2][p1] = w;
        }
    }
}

// 输出带权图邻接矩阵
void DisplayWeightedGraph(MGraph G) {
    int i, j;
    printf("\n带权图的邻接矩阵如下：\n    ");
    for (i = 0; i < G.vexnum; i++)
        printf("%c ", G.vexs[i]);
    printf("\n");

    for (i = 0; i < G.vexnum; i++) {
        printf("%c: ", G.vexs[i]);
        for (j = 0; j < G.vexnum; j++) {
            if (G.arcs[i][j] == INF)
                printf("∞ ");
            else
                printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph G;
    CreateWeightedGraph(&G);
    DisplayWeightedGraph(G);
    return 0;
}
// 请输入顶点数和边数(空格分隔): 4 4
// 请输入各顶点名称(单字符): A B C D
// 请输入各边(格式: 顶点1 顶点2 权值)
// A B 5
// A C 2
// B D 3
// C D 7

// 带权图的邻接矩阵如下：
//     A B C D
// A: 0 5 2 ∞
// B: ∞ 0 ∞ 3
// C: ∞ ∞ 0 7
// D: ∞ ∞ ∞ 0
