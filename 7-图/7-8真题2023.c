#include <stdio.h>
#define MAXV 4  // ��󶥵���

// ͼ���ڽӾ���洢�ṹ
typedef struct {
    int numVertices, numEdges;        // ������������
    char verticesList[MAXV];          // ������Ϣ����A��B��C��D��
    int Edge[MAXV][MAXV];             // �ڽӾ���
} MGraph;

/*
�������ܣ�
    ������г��ȴ�����ȵĶ��㣨K���㣩��������K����ĸ���
����˼�룺
    ����ÿһ������i��
        - ͳ�Ƴ��ȣ�cunum�����ڵ�i����ͳ�Ʒ�0Ԫ�صĸ���
        - ͳ����ȣ�runum�����ڵ�i����ͳ�Ʒ�0Ԫ�صĸ���
        - ������ > ��ȣ���ö���ΪK���㣬�����������
ʱ�临�Ӷȣ�
    O(n^2)����Ϊ��Ҫ����ѭ�������ڽӾ���
�ռ临�Ӷȣ�
    O(1)����ʹ�ó�����������������ȡ����ȡ���������
*/
int printVertices(MGraph G) {
    int count = 0;  // ͳ��K�������
    int runum, cunum;

    printf("K����Ϊ: ");
    for (int i = 0; i < G.numVertices; i++) {
        runum = cunum = 0;
        // ͳ�Ƶ�i������ĳ��������
        for (int j = 0; j < G.numVertices; j++) {
            if (G.Edge[i][j] != 0) cunum++; // ���ȣ���i��
            if (G.Edge[j][i] != 0) runum++; // ��ȣ���i��
        }
        if (cunum > runum) { // ������ > ��ȣ���ΪK����
            printf("%c ", G.verticesList[i]);
            count++;
        }
    }
    return count;
}

int main() {
    // ��ʼ��һ������ͼ���ڽӾ����ʾ��
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
    printf("\nK��������: %d\n", kCount);

    return 0;
}
