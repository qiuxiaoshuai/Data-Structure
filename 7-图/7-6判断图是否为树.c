#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#define IN_MAX 10

typedef struct{
    int abj[IN_MAX][IN_MAX];
    int n, m;//n是顶点m是边
    bool vist[IN_MAX]; //访问标记
}GE;

void DFS(GE *G, int v){
    // 1?? 标记当前顶点 v 已经被访问过
    G->vist[v] = true;

    // 2?? 遍历当前顶点 v 的所有可能邻接顶点
    for(int i = 0; i < G->n; i++) {

        // 3?? 判断条件：
        // a) abj[v][i] == 1  → 顶点 v 与顶点 i 有边相连
        // b) vist[i] == false → 顶点 i 还没有被访问过
        if(G->abj[v][i] && G->vist[i] == false) {

            // 4?? 递归调用 DFS 对邻接顶点 i 进行访问
            // 这一步会沿着 i 的路径继续深度遍历，直到访问到所有可达顶点
            DFS(G, i);
        }
    }

    // 5?? 当 for 循环结束时，说明 v 的所有邻接顶点都已经访问过
    // DFS 自动返回到上一个递归调用，继续访问其他未访问顶点
}

bool add(GE *G){
    if(G->m != G->n-1) return false; //判断边长是否为顶点数减一

    for(int i=0;i<G->n;i++) G->vist[i] = false;  //初始化标记位

    DFS(G,0); // 重0结点开始深度遍历

    for(int i=0;i<G->n;i++) if(G->vist[i] == false) return false;
    
    return true;
}

int main() {
    GE G;
    G.n = 5; // 顶点数：0~4
    G.m = 4; // 边数

    // 初始化邻接矩阵
    for (int i = 0; i < G.n; i++)
        for (int j = 0; j < G.n; j++)
            G.abj[i][j] = 0;

    // 根据图结构添加边
    G.abj[3][1] = G.abj[1][3] = 1;
    G.abj[1][0] = G.abj[0][1] = 1;
    G.abj[1][4] = G.abj[4][1] = 1;
    G.abj[0][2] = G.abj[2][0] = 1;
    //     3
    //     |
    //     1
    //    / \
    //   0   4
    //    \
    //     2

    // 打印邻接关系
    printf("图的邻接关系如下：\n");
    for (int i = 0; i < G.n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < G.n; j++) {
            if (G.abj[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }

    // 判断是否为树
    if (add(&G))
        printf("\n? 该无向图是一棵树。\n");
    else
        printf("\n? 该无向图不是一棵树。\n");

    return 0;
}
