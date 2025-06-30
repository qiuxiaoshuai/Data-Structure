#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链队列中每个节点的结构体，包含数据域和指向下一个节点的指针
typedef struct Node {
    int data;              // 存储数据
    struct Node *next;     // 指向下一个节点的指针
} Node;

// 定义链队列结构，包含头指针和尾指针
typedef struct {
    Node *front;  // 指向队头（头结点，不存放数据）
    Node *rear;   // 指向队尾（最后一个有效数据节点）
} LinkQueue;

// 初始化链队列
void Init(LinkQueue *q) {
    Node *head = (Node *)malloc(sizeof(Node)); // 创建头结点
    head->next = NULL;                         // 初始化指针为空

    q->front = q->rear = head;                 // 初始时头尾都指向头结点

    /*
    初始状态：
    [头结点] -> NULL
    front --> 头结点
    rear  --> 头结点
    */
}

// 判断队列是否为空
bool isEmpty(LinkQueue *q) {
    return q->front == q->rear; // 如果头尾指针相同，则队列为空
}

// 入队操作：将元素 x 插入到队尾
void EnQueue(LinkQueue *q, int x) {
    Node *s = (Node *)malloc(sizeof(Node)); // 创建新节点
    s->data = x;        // 存入数据
    s->next = NULL;     // 新节点的 next 设为空

    q->rear->next = s;  // 原队尾指向新节点
    q->rear = s;        // 更新队尾指针为新节点

    /*
    入队示例：
    入队 x = 10：
    [头结点] -> [10] -> NULL
    front ----------> 头结点
    rear  -----------------> 新节点

    入队 x = 20：
    [头结点] -> [10] -> [20] -> NULL
    rear  -----------------------> 新节点
    */
}

// 出队操作：删除队头第一个有效元素，并将其值保存在 *x 中
bool DeQueue(LinkQueue *q, int *x) {
    if (isEmpty(q)) return false; // 队列空，无法出队

    Node *p = q->front->next;     // p 指向第一个有效节点
    *x = p->data;                 // 获取数据

    q->front->next = p->next;     // 移除节点
    if (q->rear == p) {           // 如果移除的是最后一个元素
        q->rear = q->front;       // 尾指针也回退到头结点
    }

    free(p);                      // 释放节点内存
    return true;

    /*
    出队示例：
    初始：
    [头结点] -> [10] -> [20] -> [30] -> NULL

    出队一次（10）：
    [头结点] -> [20] -> [30] -> NULL

    出队两次（20）：
    [头结点] -> [30] -> NULL

    出队三次（30）：
    [头结点] -> NULL
    front --> 头结点
    rear  --> 头结点
    */
}

int main() {
    LinkQueue q;
    Init(&q);  // 初始化队列

    // 入队操作
    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    int val;

    // 出队并打印每个元素
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
