#include <stdio.h>
#include <limits.h> // �ṩ INT_MAX�����������

#define MAX 100      // ��󶥵���
#define INF INT_MAX  // ������������ڱ�ʾ���ɴ�

// Dijkstra �㷨����
// graph���ڽӾ��󣨱�Ȩ��
// n��������
// start������ţ���0��ʼ��
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];      // dist[i]����㵽���� i ����̾���
    int visited[MAX];   // visited[i]���Ƿ���ȷ�����·��
    int i, j;
    int minDist, u;

    // ��ʼ������㵽�����������Ϊͼ��ԭʼֵ��visited����Ϊ0
    for (i = 0; i < n; i++) {
        dist[i] = graph[start][i];  // ��ʼ������ֱ����ͨ�ı�Ȩֵ
        visited[i] = 0;             // ���е㶼δ������
    }

    dist[start] = 0;     // ��㵽�������Ϊ0
    visited[start] = 1;  // �����Ϊ�ѷ���

    // ��ѭ���������� n-1 �Σ�����ҳ����·���Ķ���
    for (i = 1; i < n; i++) {
        minDist = INF;
        u = -1;

        // �ҳ�δ������ dist ��С�Ķ��� u
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // ���û�пɷ��ʵĶ��㣨��ʣ�µ��ǲ��ɴ�ĵ㣩
        if (u == -1) break;

        visited[u] = 1;  // ��� u �ѷ���

        // ���� u ���ڽӵ�����·��
        for (j = 0; j < n; j++) {
            // �� j δ���ʣ��� u �� j �бߣ��Ҵ� start �� j �ľ������ͨ�� u ����
            if (!visited[j] && graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];  // �������·��
            }
        }
    }

    // ������
    printf("��� %d �����������̾��룺\n", start);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("�� ���� %d�����ɴ�\n", i);
        else
            printf("�� ���� %d������ %d\n", i, dist[i]);
    }
}

// ������������ Dijkstra �㷨
int main() {
    int n = 5; // �������

    // �ڽӾ����ʾͼ��graph[i][j] �� i �� j ��Ȩ�أ�
    // ���ޱ����ӣ�����Ϊ INF
    int graph[MAX][MAX] = {
        {0,   INF,  1, INF,  10},
        {INF, 0,   INF,  1, 5},
        {INF, 1, 0,   INF, 7},
        {INF, INF, INF,  0,   1},
        {INF, INF, INF, INF, 0}
    };

    int start = 0; // �������Ϊ0�Ŷ���

    dijkstra(graph, n, start);

    return 0;
}
