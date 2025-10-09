#include <stdio.h>
#define MAXV 100  // ��󶥵���

// ͼ�Ľṹ����
typedef struct {
    char vexs[MAXV];        // �����
    int arcs[MAXV][MAXV];   // �ڽӾ���
    int vexnum, arcnum;     // �������ͱ���
} MGraph;

// ������Ȩͼ���ڽӾ��󷨣�
void CreateGraph(MGraph *G) {
    int i, j, k;
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
            G->arcs[i][j] = 0;
        }
    }

    // �������Ϣ
    printf("���������(��ʽ: ����1 ����2)\n");
    for (k = 0; k < G->arcnum; k++) {
        scanf(" %c %c", &v1, &v2);

        int p1 = -1, p2 = -1;
        for (i = 0; i < G->vexnum; i++) {
            if (G->vexs[i] == v1) p1 = i;
            if (G->vexs[i] == v2) p2 = i;
        }
        if (p1 != -1 && p2 != -1) {
            G->arcs[p1][p2] = 1;
            G->arcs[p2][p1] = 1; // ����ͼ�Գ�
        }
    }
}

// ����ڽӾ���
void DisplayGraph(MGraph G) {
    int i, j;
    printf("\n��Ȩͼ���ڽӾ������£�\n    ");
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
// �����붥�����ͱ���(�ո�ָ�): 4 4
// ���������������(���ַ�): A B C D
// ���������(��ʽ: ����1 ����2)
// A B
// A C
// B D
// C D

// ��Ȩͼ���ڽӾ������£�
//     A B C D
// A: 0 1 1 0
// B: 1 0 0 1
// C: 1 0 0 1
// D: 0 1 1 0
