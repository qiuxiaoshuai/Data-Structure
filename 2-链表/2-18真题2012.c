#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node,*LinkNode;

void printList(LinkNode List){
    while(List != NULL){
        printf("%c ",List->data);
        List = List->next;
    }
    printf("\n");
}

int csh(LinkNode *L,char A[],int leng){
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
    LinkNode list = *L;
    for(int i=0;i<leng;i++){
        LinkNode p = (Node *)malloc(sizeof(Node));
        p->data = A[i];
        p->next = NULL;
        list->next = p;
        list = p; //更新链表
    }
    printList((*L)->next); 
}

void add(LinkNode str1,LinkNode str2,int len_1,int len_2){
    LinkNode p=str1->next,q=str2->next;
    char *arr1 = (char *)malloc(sizeof(char) * len_1);
    char *arr2 = (char *)malloc(sizeof(char) * len_2);
    for(int i=0;i<len_1;i++){
        arr1[i] = p->data;
        p = p->next;
    }
    for(int i=0;i<len_2;i++){
        arr2[i] = q->data;
        q = q->next;
    }
    int j = len_1-1,b = len_2 - 1;
    int index_if = 0;
    while(arr1[j] == arr2[b] && j >=0 && b >= 0){
        j--;
        b--;
        index_if++;
    }
    printf("开始的位置是为%c",arr1[j+1]);
}

int main(){
    LinkNode L1,L2;
    char str1[] = {'l','o','a','d','i','n','g'};
    int len_str1 = sizeof(str1) / sizeof(str1[0]);
    char str2[] = {'b','e','i','n','g'};
    int len_str2 = sizeof(str2) / sizeof(str2[0]);
    csh(&L1,str1,len_str1);
    csh(&L2,str2,len_str2);
    add(L1, L2, len_str1, len_str2);
}