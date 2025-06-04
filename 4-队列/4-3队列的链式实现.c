#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ڵ�ṹ��ÿ���ڵ�����������ָ����
typedef struct Node {
    int data;              // ������
    struct Node *next;     // ָ����һ���ڵ��ָ��
} Node;

// ������нṹ������ͷָ���βָ��
typedef struct {
    Node *front;  // ָ��ͷ��㣨ע�⣺��ͷ��㣬�������ݣ�
    Node *rear;   // ָ�����һ�����ݽڵ�
} LinkQueue;

// ��ʼ������
void Init(LinkQueue *q) {
    // ����һ��ͷ��㣨�������ݣ�
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    // ��ʼʱ��front �� rear ��ָ��ͷ���
    q->front = q->rear = head;

    /*
    ��ǰ���нṹ����ͷ��㣩��
    [ͷ���] -> NULL
    front --> ��
    rear  --> ��
    */
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(LinkQueue *q) {
    return q->front == q->rear;
}

// ��Ӳ����������� x �����β
void EnQueue(LinkQueue *q, int x) {
    Node *s = (Node *)malloc(sizeof(Node)); // �½��ڵ�
    s->data = x;        // �洢����
    s->next = NULL;     // �½ڵ�û����һ��

    q->rear->next = s;  // ����ǰβ���� next ָ���½ڵ�
    q->rear = s;        // ����βָ��ָ���½ڵ�

    /*
    ��� x = 10 ʱ�Ķ��нṹ��
    [ͷ���] -> [10] -> NULL
     front ----------> ��
     rear  -----------------> ��

    ��� x = 20 ʱ�Ľṹ��
    [ͷ���] -> [10] -> [20] -> NULL
     front ----------> ��
     rear  ----------------------> ��

    ��� x = 30 ��ṹ��
    [ͷ���] -> [10] -> [20] -> [30] -> NULL
     front ----------> ��
     rear  ----------------------------> ��
    */
}

// ���Ӳ������Ӷ�ͷɾ��һ��Ԫ�ز����� *x
bool DeQueue(LinkQueue *q, int *x) {
    if (isEmpty(q)) return false; // �ӿ��򷵻� false

    Node *p = q->front->next;     // p ָ���һ�����ݽڵ�
    *x = p->data;                 // ȡ������

    q->front->next = p->next;     // ͷ���ָ����һ���ڵ�
    if (q->rear == p) {
        q->rear = q->front;       // ������ӵ������һ���ڵ㣬rear �ص�ͷ���
    }

    free(p);                      // �ͷų��ӽڵ�
    return true;

    /*
    ����ǰ�ṹ��
    [ͷ���] -> [10] -> [20] -> [30] -> NULL
     front ----------> ��
     rear  ----------------------------> ��

    ���� 10 ��
    [ͷ���] -> [20] -> [30] -> NULL
     front ----------> ��
     rear  ----------------------> ��

    ���� 20 ��
    [ͷ���] -> [30] -> NULL
     front ----------> ��
     rear  -----------------> ��

    ���� 30 �󣨶ӿգ���
    [ͷ���] -> NULL
     front --> ��
     rear  --> ��
    */
}

int main() {
    LinkQueue q;
    Init(&q);  // ��ʼ������

    // �������Ԫ��
    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    int val;

    // ���Ӳ���ӡ
    while (!isEmpty(&q)) {
        if (DeQueue(&q, &val)) {
            printf("����Ԫ��: %d\n", val);
        }
    }

    /*
    ��������
    ����Ԫ��: 10
    ����Ԫ��: 20
    ����Ԫ��: 30
    */

    return 0;
}
