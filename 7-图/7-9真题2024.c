#include<stdio.h>
#define MAXV 10

typedef struct{
    int numVertices,numEdges; //���������������
    char VerticesList[MAXV]; //����� 
    int Edge[MAXV][MAXV]; //�ڽӾ���
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

// // �ж�ͼ�Ƿ���Ψһ����������
// int uniquely(MGraph G) {
//     int inDegree[MAXV];
//     calculateInDegree(G, inDegree);  // �������

//     int count = 0;  // ��¼���Ϊ 0 �Ķ�������

//     while (1) {
//         count = 0;  // ��¼��ǰ���Ϊ 0 �Ķ�����
//         int zeroInDegreeVertex = -1;

//         // �ҳ��������Ϊ 0 �Ķ���
//         for (int i = 0; i < G.numVertices; i++) {
//             if (inDegree[i] == 0) {
//                 count++;
//                 zeroInDegreeVertex = i;  // ��¼���һ�����Ϊ 0 �Ķ���
//             }
//         }

//         // ����ж���������Ϊ 0����˵������������Ψһ��
//         if (count > 1) {
//             return 0;
//         }

//         // ������ж��㶼���������ˣ��˳�
//         if (count == 0) {
//             break;
//         }

//         // ѡ��һ�����Ϊ 0 �Ķ��㲢�Ƴ���
//         for (int j = 0; j < G.numVertices; j++) {
//             if (G.Edge[zeroInDegreeVertex][j] == 1) {
//                 inDegree[j]--;  // ɾ���ö���󣬸������ڶ�������
//             }
//         }

//         // ���ö���������Ϊ��ֵ����ʾ���ѱ�����
//         inDegree[zeroInDegreeVertex] = -1;
//     }

//     return 1;  // ���ÿ��ֻ��һ���������Ϊ 0����������Ψһ
// }

int main() {
    MGraph G;
    G.numVertices = 4;
    G.numEdges = 4;

    G.VerticesList[0] = 'A';
    G.VerticesList[1] = 'B';
    G.VerticesList[2] = 'C';
    G.VerticesList[3] = 'D';

    // �ڽӾ���ʾ����A->B, A->C, C->D��
    G.Edge[0][1] = 1;
    G.Edge[0][2] = 1;
    G.Edge[2][3] = 1;

    if (app(G)) {
        printf("��ͼ��Ψһ����������\n");
    } else {
        printf("��ͼû��Ψһ����������\n");
    }

    return 0;
}