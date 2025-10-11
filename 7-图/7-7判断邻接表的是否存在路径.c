#include<stdio.h>
#define IN_MAX 100

typedef struct ArcNode{
    int abjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode,*AdjList[IN_MAX];

typedef struct{
    AdjList ver;
    int vexnnum,arcnum;
}ALGraph;