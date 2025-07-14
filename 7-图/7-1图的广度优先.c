#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 100

// 边表节点
typedef struct EdgeNode {
    int adjvex;                // 邻接点在顶点数组中的下标
    struct EdgeNode* next;
} EdgeNode;

// 顶点节点
typedef struct VNode {
    char data;                 // 顶点信息
    EdgeNode* first;           // 指向边表的指针
} VNode;

// 图结构体
typedef struct {
    VNode adjList[MAX_VERTEX_NUM];
    int vexnum, arcnum;        // 顶点数，边数
} Graph;

// 队列结构用于 BFS
typedef struct {
    int data[MAX_VERTEX_NUM];
    int front, rear;
} Queue;

// 初始化队列
void InitQueue(Queue* q) {
    q->front = q->rear = 0;
}

// 判断队列是否为空
bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// 入队
void EnQueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

// 出队
int DeQueue(Queue* q) {
    return q->data[q->front++];
}

// 获取顶点下标
int GetIndex(Graph* g, char ch) {
    for (int i = 0; i < g->vexnum; i++) {
        if (g->adjList[i].data == ch)
            return i;
    }
    return -1;
}

// 创建无向图（邻接表）
void CreateGraph(Graph* g) {
    printf("输入顶点个数和边数：");
    scanf("%d %d", &g->vexnum, &g->arcnum);

    printf("输入顶点信息：\n");
    for (int i = 0; i < g->vexnum; i++) {
        scanf(" %c", &g->adjList[i].data);
        g->adjList[i].first = NULL;
    }

    printf("输入每条边（格式如 A B 表示A-B）：\n");
    for (int k = 0; k < g->arcnum; k++) {
        char v1, v2;
        scanf(" %c %c", &v1, &v2);
        int i = GetIndex(g, v1);
        int j = GetIndex(g, v2);

        // 建立 v1 -> v2 的边
        EdgeNode* e1 = (EdgeNode*)malloc(sizeof(EdgeNode));
        e1->adjvex = j;
        e1->next = g->adjList[i].first;
        g->adjList[i].first = e1;

        // 建立 v2 -> v1 的边（无向图）
        EdgeNode* e2 = (EdgeNode*)malloc(sizeof(EdgeNode));
        e2->adjvex = i;
        e2->next = g->adjList[j].first;
        g->adjList[j].first = e2;
    }
}

// 广度优先遍历 BFS
void BFS(Graph* g, int start) {
    bool visited[MAX_VERTEX_NUM] = {false};
    Queue q;
    InitQueue(&q);

    printf("BFS 遍历顺序：");
    visited[start] = true;
    printf("%c ", g->adjList[start].data);
    EnQueue(&q, start);

    while (!isEmpty(&q)) {
        int v = DeQueue(&q);
        EdgeNode* p = g->adjList[v].first;
        while (p != NULL) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = true;
                printf("%c ", g->adjList[w].data);
                EnQueue(&q, w);
            }
            p = p->next;
        }
    }
    printf("\n");
}

// 主函数测试
int main() {
    Graph g;
    CreateGraph(&g);

    char startVertex;
    printf("输入起始顶点：");
    scanf(" %c", &startVertex);

    int startIndex = GetIndex(&g, startVertex);
    if (startIndex != -1)
        BFS(&g, startIndex);
    else
        printf("起始顶点不存在！\n");

    return 0;
}
