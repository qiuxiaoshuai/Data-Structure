#include <stdio.h>
#define MAXV 100
#define INF  32767  // ������ʾ�ޱ�

// ��Ȩͼ�ṹ����
typedef struct {
    char vexs[MAXV];        // �����
    int arcs[MAXV][MAXV];   // �ڽӾ��󣨴�Ȩֵ��
    int vexnum, arcnum;     // �������ͱ���
} MGraph;

// ������Ȩͼ
void CreateWeightedGraph(MGraph *G) {
    int i, j, k, w;
    char v1, v2;

    printf("�����붥�����ͱ���(�ո�ָ�): ");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    // ���붥����Ϣ
    printf("���������������(���ַ�): ");
    for (i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vexs[i]);
    }

    // ��ʼ���ڽӾ���
    for (i = 0; i < G->vexnum; i++) {
        for (j = 0; j < G->vexnum; j++) {
            if (i == j)
                G->arcs[i][j] = 0;
            else
                G->arcs[i][j] = INF;
        }
    }

    // �������Ϣ
    printf("���������(��ʽ: ����1 ����2 Ȩֵ)\n");
    for (k = 0; k < G->arcnum; k++) {
        scanf(" %c %c %d", &v1, &v2, &w);

        int p1 = -1, p2 = -1;
        for (i = 0; i < G->vexnum; i++) {
            if (G->vexs[i] == v1) p1 = i;
            if (G->vexs[i] == v2) p2 = i;
        }
        if (p1 != -1 && p2 != -1) {
            G->arcs[p1][p2] = w;
            // ��Ϊ����ͼ����ϣ�
            // G->arcs[p2][p1] = w;
        }
    }
}

// �����Ȩͼ�ڽӾ���
void DisplayWeightedGraph(MGraph G) {
    int i, j;
    printf("\n��Ȩͼ���ڽӾ������£�\n    ");
    for (i = 0; i < G.vexnum; i++)
        printf("%c ", G.vexs[i]);
    printf("\n");

    for (i = 0; i < G.vexnum; i++) {
        printf("%c: ", G.vexs[i]);
        for (j = 0; j < G.vexnum; j++) {
            if (G.arcs[i][j] == INF)
                printf("�� ");
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
// �����붥�����ͱ���(�ո�ָ�): 4 4
// ���������������(���ַ�): A B C D
// ���������(��ʽ: ����1 ����2 Ȩֵ)
// A B 5
// A C 2
// B D 3
// C D 7

// ��Ȩͼ���ڽӾ������£�
//     A B C D
// A: 0 5 2 ��
// B: �� 0 �� 3
// C: �� �� 0 7
// D: �� �� �� 0
