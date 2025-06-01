#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next,*precur;
}Node,*LinkNode;

void printList(LinkNode List){
    while(List != NULL){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}

void csrList(LinkNode *L,int a[],int len_a){
    *L = (Node *)malloc(sizeof(Node)); // 创建头结点（不存数据）
    (*L)->next = NULL;
    (*L)->precur = NULL;
    LinkNode tail = *L; // 尾指针初始化为头结点
    LinkNode fir = NULL;
    for (int i = 0; i < len_a; i++) {
        LinkNode s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->next = NULL;
        s->precur = tail;//s的前驱节点是未更改的tail
        tail->next = s;
        tail = s;
    }
    (*L)->precur = tail;  
}

int IfSymmetry(LinkNode *L,int len_a){
    LinkNode head = (*L)->next,tail = (*L)->precur;
    for(int i=0;i<len_a/2;i++){
        if(head->data != tail->data){
            return -1;
            break;
        }
        head = head->next;
        tail = tail->precur;
    }
    return 1;
}
int main(){
    LinkNode L;
    int a[] = {1,2,1};
    int len_a = sizeof(a) / sizeof(a[0]);
    csrList(&L,a,len_a);
    int res = IfSymmetry(&L,len_a);
    printf("%s",res == 1 ? "对称":"不对称");
}
