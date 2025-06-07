#include<stdio.h>
#include<stdlib.h>
typedef struct Linknode{
    int data;
    struct Linknode *next;  
} Linknode, *LinkStack;

// 初始化栈（设置为空栈）
void InitStack(LinkStack *top) {
    *top = NULL;
}

//入栈
void Push(LinkStack *top,int x){
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    if(!p){
        printf("内存分配失败!\n");
    }
    p->data = x;
    p->next = *top;
    *top = p;
}

//出栈
int Pop(LinkStack *top,int *x){
    if(*top == NULL){
        printf("栈为空\n");
    }
    Linknode *tamp = *top;
    *x = tamp->data;//获取当前出栈的元素
    *top = tamp->next;//让栈顶指针指向下一个节点（出栈）
    free(tamp);
}

//输出栈元素!!! 这里传入的top只是副本不改变原指针
void printfStack(LinkStack top){
    printf("\n");
    printf("当前栈顶到栈底\n");
    while(top){
        printf("%d\n",top->data);
        top = top->next;
    }
}

int main(){
    LinkStack s;
    InitStack(&s);
    int arr[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0;i<sizeof(arr) / sizeof(arr[0]);i++){
        Push(&s,arr[i]);
    }
    printfStack(s);
}