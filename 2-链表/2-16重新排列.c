#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;
//L = (a1,a2,a3,an)
// �����һ���ռ临�Ӷ�Ϊ(O(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㣬��
// �����Ա�L=(a1,an,a2,an-1,a3,a-2).Ҫ��

