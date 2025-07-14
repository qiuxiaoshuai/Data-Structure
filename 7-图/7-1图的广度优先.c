#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 100

// �߱�ڵ�
typedef struct EdgeNode {
    int adjvex;                // �ڽӵ��ڶ��������е��±�
    struct EdgeNode* next;
} EdgeNode;

// ����ڵ�
typedef struct VNode {
    char data;                 // ������Ϣ
    EdgeNode* first;           // ָ��߱��ָ��
} VNode;

// ͼ�ṹ��
typedef struct {
    VNode adjList[MAX_VERTEX_NUM];
    int vexnum, arcnum;        // ������������
} Graph;

// ���нṹ���� BFS
typedef struct {
    int data[MAX_VERTEX_NUM];
    int front, rear;
} Queue;

// ��ʼ������
void InitQueue(Queue* q) {
    q->front = q->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// ���
void EnQueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

// ����
int DeQueue(Queue* q) {
    return q->data[q->front++];
}

// ��ȡ�����±�
int GetIndex(Graph* g, char ch) {
    for (int i = 0; i < g->vexnum; i++) {
        if (g->adjList[i].data == ch)
            return i;
    }
    return -1;
}

// ��������ͼ���ڽӱ�
void CreateGraph(Graph* g) {
    printf("���붥������ͱ�����");
    scanf("%d %d", &g->vexnum, &g->arcnum);

    printf("���붥����Ϣ��\n");
    for (int i = 0; i < g->vexnum; i++) {
        scanf(" %c", &g->adjList[i].data);
        g->adjList[i].first = NULL;
    }

    printf("����ÿ���ߣ���ʽ�� A B ��ʾA-B����\n");
    for (int k = 0; k < g->arcnum; k++) {
        char v1, v2;
        scanf(" %c %c", &v1, &v2);
        int i = GetIndex(g, v1);
        int j = GetIndex(g, v2);

        // ���� v1 -> v2 �ı�
        EdgeNode* e1 = (EdgeNode*)malloc(sizeof(EdgeNode));
        e1->adjvex = j;
        e1->next = g->adjList[i].first;
        g->adjList[i].first = e1;

        // ���� v2 -> v1 �ıߣ�����ͼ��
        EdgeNode* e2 = (EdgeNode*)malloc(sizeof(EdgeNode));
        e2->adjvex = i;
        e2->next = g->adjList[j].first;
        g->adjList[j].first = e2;
    }
}

// ������ȱ��� BFS
void BFS(Graph* g, int start) {
    bool visited[MAX_VERTEX_NUM] = {false};
    Queue q;
    InitQueue(&q);

    printf("BFS ����˳��");
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

// ����������
int main() {
    Graph g;
    CreateGraph(&g);

    char startVertex;
    printf("������ʼ���㣺");
    scanf(" %c", &startVertex);

    int startIndex = GetIndex(&g, startVertex);
    if (startIndex != -1)
        BFS(&g, startIndex);
    else
        printf("��ʼ���㲻���ڣ�\n");

    return 0;
}
