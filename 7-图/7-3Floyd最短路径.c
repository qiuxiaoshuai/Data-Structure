#include <stdio.h>
#include <limits.h>

#define MAX 100          // ��󶥵�����
#define INF INT_MAX      // ������������ڱ�ʾ�����㲻�ɴ�

// Floyd �㷨����������������·��
void floyd(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];   // dist[i][j] ��ʾ i �� j �����·������
    int path[MAX][MAX];   // path[i][j] ��ʾ i �� j ���·���� j ��ǰһ������

    // ===== ��ʼ�� dist �� path =====
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];       // ��ʼ��Ϊͼ�и�����Ȩֵ
            if (i == j || graph[i][j] == INF)
                path[i][j] = -1;            // �Լ����Լ����򲻿ɴ��Ϊ -1
            else
                path[i][j] = i;             // ��ʼ·������ i �� j��ǰ����Ϊ i
        }
    }

    // ===== ����ѭ�����ģ��� k Ϊ�м�㣬�������� i �� j ��·�� =====
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // ֻ�� i��k �� k��j �ɴ�����ʸ���� i��j
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // ���ͨ�� k ��ת��·�����̣�����
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[k][j];  // ���� j ��ǰ��Ϊ k ·���ϵ�ǰ��
                    }
                }
            }
        }
    }

    // ===== ������·�����Ⱦ��� =====
    printf("�����������·�����Ⱦ���\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    // ===== ʾ��������Ӷ��� 0 ���������·�� =====
    printf("\n�Ӷ��� 0 ���������·����\n");
    for (int j = 0; j < n; j++) {
        if (j == 0) continue;  // ������Լ����Լ�
        if (dist[0][j] == INF) {
            printf("0 �� %d�����ɴ�\n", j);
            continue;
        }

        // ����·������ j ���� path ���ݵ� 0
        int stack[MAX], top = 0;
        int current = j;
        while (current != 0) {
            stack[top++] = current;
            current = path[0][current];
        }

        // ��ӡ·��
        printf("0");
        while (top > 0) {
            printf(" �� %d", stack[--top]);
        }
        printf("��·�����ȣ�%d��\n", dist[0][j]);
    }
}

// ===== ��������ʾ������ =====
int main() {
    int n = 4; // ������

    // �ڽӾ����ʼ��
    // graph[i][j] ��ʾ i �� j �ı�Ȩ���ޱ��� INF ��ʾ
    int graph[MAX][MAX] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floyd(graph, n);

    return 0;
}
