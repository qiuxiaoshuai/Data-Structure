#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义节点结构，每个节点包含数据域和指针域
typedef struct Node {
    int data;              // 数据域
    struct Node *next;     // 指向下一个节点的指针
} Node;

// 定义队列结构，包含头指针和尾指针
typedef struct {
    Node *front;  // 指向头结点（注意：是头结点，不存数据）
    Node *rear;   // 指向最后一个数据节点
} LinkQueue;

// 初始化队列
void Init(LinkQueue *q) {
    // 创建一个头结点（不存数据）
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    // 初始时，front 和 rear 都指向头结点
    q->front = q->rear = head;

    /*
    当前队列结构（仅头结点）：
    [头结点] -> NULL
    front --> ↑
    rear  --> ↑
    */
}

// 判断队列是否为空
bool isEmpty(LinkQueue *q) {
    return q->front == q->rear;
}

// 入队操作：将数据 x 加入队尾
void EnQueue(LinkQueue *q, int x) {
    Node *s = (Node *)malloc(sizeof(Node)); // 新建节点
    s->data = x;        // 存储数据
    s->next = NULL;     // 新节点没有下一个

    q->rear->next = s;  // 将当前尾结点的 next 指向新节点
    q->rear = s;        // 更新尾指针指向新节点

    /*
    入队 x = 10 时的队列结构：
    [头结点] -> [10] -> NULL
     front ----------> ↑
     rear  -----------------> ↑

    入队 x = 20 时的结构：
    [头结点] -> [10] -> [20] -> NULL
     front ----------> ↑
     rear  ----------------------> ↑

    入队 x = 30 后结构：
    [头结点] -> [10] -> [20] -> [30] -> NULL
     front ----------> ↑
     rear  ----------------------------> ↑
    */
}

// 出队操作：从队头删除一个元素并存入 *x
bool DeQueue(LinkQueue *q, int *x) {
    if (isEmpty(q)) return false; // 队空则返回 false

    Node *p = q->front->next;     // p 指向第一个数据节点
    *x = p->data;                 // 取出数据

    q->front->next = p->next;     // 头结点指向下一个节点
    if (q->rear == p) {
        q->rear = q->front;       // 如果出队的是最后一个节点，rear 回到头结点
    }

    free(p);                      // 释放出队节点
    return true;

    /*
    出队前结构：
    [头结点] -> [10] -> [20] -> [30] -> NULL
     front ----------> ↑
     rear  ----------------------------> ↑

    出队 10 后：
    [头结点] -> [20] -> [30] -> NULL
     front ----------> ↑
     rear  ----------------------> ↑

    出队 20 后：
    [头结点] -> [30] -> NULL
     front ----------> ↑
     rear  -----------------> ↑

    出队 30 后（队空）：
    [头结点] -> NULL
     front --> ↑
     rear  --> ↑
    */
}

int main() {
    LinkQueue q;
    Init(&q);  // 初始化队列

    // 入队三个元素
    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    int val;

    // 出队并打印
    while (!isEmpty(&q)) {
        if (DeQueue(&q, &val)) {
            printf("出队元素: %d\n", val);
        }
    }

    /*
    输出结果：
    出队元素: 10
    出队元素: 20
    出队元素: 30
    */

    return 0;
}
