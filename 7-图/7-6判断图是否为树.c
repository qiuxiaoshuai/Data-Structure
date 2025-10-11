#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#define IN_MAX 10

typedef struct{
    int abj[IN_MAX][IN_MAX];
    int n, m;//n�Ƕ���m�Ǳ�
    bool vist[IN_MAX]; //���ʱ��
}GE;

void DFS(GE *G, int v){
    // 1?? ��ǵ�ǰ���� v �Ѿ������ʹ�
    G->vist[v] = true;

    // 2?? ������ǰ���� v �����п����ڽӶ���
    for(int i = 0; i < G->n; i++) {

        // 3?? �ж�������
        // a) abj[v][i] == 1  �� ���� v �붥�� i �б�����
        // b) vist[i] == false �� ���� i ��û�б����ʹ�
        if(G->abj[v][i] && G->vist[i] == false) {

            // 4?? �ݹ���� DFS ���ڽӶ��� i ���з���
            // ��һ�������� i ��·��������ȱ�����ֱ�����ʵ����пɴﶥ��
            DFS(G, i);
        }
    }

    // 5?? �� for ѭ������ʱ��˵�� v �������ڽӶ��㶼�Ѿ����ʹ�
    // DFS �Զ����ص���һ���ݹ���ã�������������δ���ʶ���
}

bool add(GE *G){
    if(G->m != G->n-1) return false; //�жϱ߳��Ƿ�Ϊ��������һ

    for(int i=0;i<G->n;i++) G->vist[i] = false;  //��ʼ�����λ

    DFS(G,0); // ��0��㿪ʼ��ȱ���

    for(int i=0;i<G->n;i++) if(G->vist[i] == false) return false;
    
    return true;
}

int main() {
    GE G;
    G.n = 5; // ��������0~4
    G.m = 4; // ����

    // ��ʼ���ڽӾ���
    for (int i = 0; i < G.n; i++)
        for (int j = 0; j < G.n; j++)
            G.abj[i][j] = 0;

    // ����ͼ�ṹ��ӱ�
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

    // ��ӡ�ڽӹ�ϵ
    printf("ͼ���ڽӹ�ϵ���£�\n");
    for (int i = 0; i < G.n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < G.n; j++) {
            if (G.abj[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }

    // �ж��Ƿ�Ϊ��
    if (add(&G))
        printf("\n? ������ͼ��һ������\n");
    else
        printf("\n? ������ͼ����һ������\n");

    return 0;
}
