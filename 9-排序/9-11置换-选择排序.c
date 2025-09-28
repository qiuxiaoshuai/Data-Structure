#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M 5   // �ڴ��ܷŵ�Ԫ�ظ���
#define N 15  // ������������

int input[N] = {42, 25, 20, 8, 35, 30, 12, 28, 15, 40, 10, 5, 45, 50, 18};

typedef struct {
    int key;
    int valid;  // ����Ƿ����ڵ�ǰ��
} Node;

Node heap[M + 1];  // С���ѣ���1��ʼ��
int heapSize = 0;

// ����
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// ���µ���
void heapify(int i) {
    int smallest = i;
    int l = i * 2, r = i * 2 + 1;
    if (l <= heapSize && heap[l].key < heap[smallest].key) smallest = l;
    if (r <= heapSize && heap[r].key < heap[smallest].key) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// ����
void buildHeap() {
    for (int i = heapSize / 2; i >= 1; i--) {
        heapify(i);
    }
}

// ������Сֵ
Node extractMin() {
    Node min = heap[1];
    heap[1] = heap[heapSize--];
    heapify(1);
    return min;
}

// ����Ԫ��
void insert(Node x) {
    heap[++heapSize] = x;
    int i = heapSize;
    while (i > 1 && heap[i].key < heap[i / 2].key) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

int main() {
    int index = 0;
    int lastOutput = INT_MIN;
    int run = 1;

    // ��ʼ����
    for (int i = 0; i < M; i++) {
        Node node = {input[index++], 1};
        insert(node);
    }
    buildHeap();

    printf("��ʼ�鲢�λ��ֽ����\n");

    while (heapSize > 0) {
        printf("Run %d: ", run);

        lastOutput = INT_MIN;

        while (heapSize > 0) {
            Node min = extractMin();

            if (!min.valid) break; // ��ǰ�ν���

            printf("%d ", min.key);
            lastOutput = min.key;

            if (index < N) {
                int nextVal = input[index++];
                Node newNode;
                newNode.key = nextVal;
                // �ж����ڵ�ǰ�λ�����һ��
                if (nextVal >= lastOutput) {
                    newNode.valid = 1;
                } else {
                    newNode.valid = 0; // ��һ��
                }
                insert(newNode);
            }
        }
        printf("\n");
        run++;
    }

    return 0;
}
