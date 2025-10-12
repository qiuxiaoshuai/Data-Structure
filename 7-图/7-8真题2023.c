#include <stdio.h>
#define MAXV 4  // 最大顶点数

// 图的邻接矩阵存储结构
typedef struct {
    int numVertices, numEdges;        // 顶点数、边数
    char verticesList[MAXV];          // 顶点信息（如A、B、C、D）
    int Edge[MAXV][MAXV];             // 邻接矩阵
} MGraph;

/*
函数功能：
    输出所有出度大于入度的顶点（K顶点），并返回K顶点的个数
基本思想：
    对于每一个顶点i：
        - 统计出度（cunum）：在第i行中统计非0元素的个数
        - 统计入度（runum）：在第i列中统计非0元素的个数
        - 若出度 > 入度，则该顶点为K顶点，输出它并计数
时间复杂度：
    O(n^2)，因为需要两层循环遍历邻接矩阵。
空间复杂度：
    O(1)，仅使用常量级辅助变量（入度、出度、计数）。
*/
int printVertices(MGraph G) {
    int count = 0;  // 统计K顶点个数
    int runum, cunum;

    printf("K顶点为: ");
    for (int i = 0; i < G.numVertices; i++) {
        runum = cunum = 0;
        // 统计第i个顶点的出度与入度
        for (int j = 0; j < G.numVertices; j++) {
            if (G.Edge[i][j] != 0) cunum++; // 出度：第i行
            if (G.Edge[j][i] != 0) runum++; // 入度：第i列
        }
        if (cunum > runum) { // 若出度 > 入度，则为K顶点
            printf("%c ", G.verticesList[i]);
            count++;
        }
    }
    return count;
}

int main() {
    // 初始化一个有向图（邻接矩阵表示）
    MGraph G = {
        4, 4,
        {'A', 'B', 'C', 'D'},
        {
            {0, 1, 0, 1}, 
            {0, 0, 1, 1}, 
            {0, 0, 0, 1},
            {0, 0, 0, 0}
        }
    };

    int kCount = printVertices(G);
    printf("\nK顶点总数: %d\n", kCount);

    return 0;
}
