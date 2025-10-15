#include<stdio.h>
#define MAXV 10

typedef struct{
    int numVertices,numEdges; //顶点数和有向边数
    char VerticesList[MAXV]; //顶点表 
    int Edge[MAXV][MAXV]; //邻接矩阵
}MGraph;

int add(MGraph G,int ruindex[]){
    for(int i=0;i<G.numVertices;i++){
        ruindex[i] = 0;
    }
    for(int i=0;i<G.numVertices;i++){
        for(int j=0;j<G.numVertices;j++){
            if(G.Edge[j][i] != 0) ruindex[i] ++;
        }
    }
}

int app(MGraph G){
    int ruindex[MAXV];
    add(G,ruindex);
    while(1){
        int count = 0;
        int jl = -1;
        for(int i=0;i<G.numVertices;i++)if(ruindex[i] == 0)count++,jl=i;
        if(count>1)return 0;
        if(count==0)break;
        for(int i=0;i<G.numVertices;i++)if(G.Edge[jl][i] == 1)ruindex[i]--;
        ruindex[jl] = -1;
    }
    return 1;
}

// int calculateInDegree(MGraph G,int inDgeru[]){
//     for(int i=0;i<G.numVertices;i++){
//         inDgeru[i] = 0;
//     }
//     for(int i=0;i<G.numVertices;i++){
//         for(int j=0;j<G.numVertices;j++){
//             if(G.Edge[j][i] != 0) inDgeru[i]++;
//         }
//     }
// }

// // 判断图是否有唯一的拓扑排序
// int uniquely(MGraph G) {
//     int inDegree[MAXV];
//     calculateInDegree(G, inDegree);  // 计算入度

//     int count = 0;  // 记录入度为 0 的顶点数量

//     while (1) {
//         count = 0;  // 记录当前入度为 0 的顶点数
//         int zeroInDegreeVertex = -1;

//         // 找出所有入度为 0 的顶点
//         for (int i = 0; i < G.numVertices; i++) {
//             if (inDegree[i] == 0) {
//                 count++;
//                 zeroInDegreeVertex = i;  // 记录最后一个入度为 0 的顶点
//             }
//         }

//         // 如果有多个顶点入度为 0，则说明拓扑排序不是唯一的
//         if (count > 1) {
//             return 0;
//         }

//         // 如果所有顶点都被处理完了，退出
//         if (count == 0) {
//             break;
//         }

//         // 选择一个入度为 0 的顶点并移除它
//         for (int j = 0; j < G.numVertices; j++) {
//             if (G.Edge[zeroInDegreeVertex][j] == 1) {
//                 inDegree[j]--;  // 删除该顶点后，更新相邻顶点的入度
//             }
//         }

//         // 将该顶点的入度设为负值，表示它已被处理
//         inDegree[zeroInDegreeVertex] = -1;
//     }

//     return 1;  // 如果每次只有一个顶点入度为 0，拓扑排序唯一
// }

int main() {
    MGraph G;
    G.numVertices = 4;
    G.numEdges = 4;

    G.VerticesList[0] = 'A';
    G.VerticesList[1] = 'B';
    G.VerticesList[2] = 'C';
    G.VerticesList[3] = 'D';

    // 邻接矩阵（示例：A->B, A->C, C->D）
    G.Edge[0][1] = 1;
    G.Edge[0][2] = 1;
    G.Edge[2][3] = 1;

    if (app(G)) {
        printf("该图有唯一的拓扑排序\n");
    } else {
        printf("该图没有唯一的拓扑排序\n");
    }

    return 0;
}