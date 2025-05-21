#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;
//L = (a1,a2,a3,an)
// 请设计一个空间复杂度为(O(1)助时间上尽可能高效的算法，重新排列L中的各结点，得
// 到线性表L=(a1,an,a2,an-1,a3,a-2).要求：

