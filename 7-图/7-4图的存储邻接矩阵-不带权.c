#include <stdio.h>
#define MAXV 100  // 最大顶点数

// 图的结构定义
typedef struct {
    char vexs[MAXV];        // 顶点表
    int arcs[MAXV][MAXV];   // 邻接矩阵
    int vexnum, arcnum;     // 顶点数和边数
} MGraph;

// 创建无权图（邻接矩阵法）
void CreateGraph(MGraph *G) {
    int i, j, k;
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
            G->arcs[i][j] = 0;
        }
    }

    // 输入边信息
    printf("请输入各边(格式: 顶点1 顶点2)\n");
    for (k = 0; k < G->arcnum; k++) {
        scanf(" %c %c", &v1, &v2);

        int p1 = -1, p2 = -1;
        for (i = 0; i < G->vexnum; i++) {
            if (G->vexs[i] == v1) p1 = i;
            if (G->vexs[i] == v2) p2 = i;
        }
        if (p1 != -1 && p2 != -1) {
            G->arcs[p1][p2] = 1;
            G->arcs[p2][p1] = 1; // 无向图对称
        }
    }
}

// 输出邻接矩阵
void DisplayGraph(MGraph G) {
    int i, j;
    printf("\n无权图的邻接矩阵如下：\n    ");
    for (i = 0; i < G.vexnum; i++)
        printf("%c ", G.vexs[i]);
    printf("\n");

    for (i = 0; i < G.vexnum; i++) {
        printf("%c: ", G.vexs[i]);
        for (j = 0; j < G.vexnum; j++) {
            printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph G;
    CreateGraph(&G);
    DisplayGraph(G);
    return 0;
}
// 请输入顶点数和边数(空格分隔): 4 4
// 请输入各顶点名称(单字符): A B C D
// 请输入各边(格式: 顶点1 顶点2)
// A B
// A C
// B D
// C D

// 无权图的邻接矩阵如下：
//     A B C D
// A: 0 1 1 0
// B: 1 0 0 1
// C: 1 0 0 1
// D: 0 1 1 0
