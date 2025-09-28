#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M 5   // 内存能放的元素个数
#define N 15  // 输入数据总数

int input[N] = {42, 25, 20, 8, 35, 30, 12, 28, 15, 40, 10, 5, 45, 50, 18};

typedef struct {
    int key;
    int valid;  // 标记是否属于当前段
} Node;

Node heap[M + 1];  // 小根堆，从1开始存
int heapSize = 0;

// 交换
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// 向下调整
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

// 建堆
void buildHeap() {
    for (int i = heapSize / 2; i >= 1; i--) {
        heapify(i);
    }
}

// 弹出最小值
Node extractMin() {
    Node min = heap[1];
    heap[1] = heap[heapSize--];
    heapify(1);
    return min;
}

// 插入元素
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

    // 初始化堆
    for (int i = 0; i < M; i++) {
        Node node = {input[index++], 1};
        insert(node);
    }
    buildHeap();

    printf("初始归并段划分结果：\n");

    while (heapSize > 0) {
        printf("Run %d: ", run);

        lastOutput = INT_MIN;

        while (heapSize > 0) {
            Node min = extractMin();

            if (!min.valid) break; // 当前段结束

            printf("%d ", min.key);
            lastOutput = min.key;

            if (index < N) {
                int nextVal = input[index++];
                Node newNode;
                newNode.key = nextVal;
                // 判断属于当前段还是下一段
                if (nextVal >= lastOutput) {
                    newNode.valid = 1;
                } else {
                    newNode.valid = 0; // 下一段
                }
                insert(newNode);
            }
        }
        printf("\n");
        run++;
    }

    return 0;
}
