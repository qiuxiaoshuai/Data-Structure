#include <stdio.h>
#include <stdlib.h>

// ��������
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ��С�ѵ���
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// ������С��
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// ��ȡ��Сֵ
int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// ������Ԫ��
void insertHeap(int arr[], int *n, int key) {
    arr[*n] = key;
    (*n)++;
    int i = *n - 1;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ��ѹ鲢������
int optimalMerge(int files[], int n) {
    buildHeap(files, n);
    int cost = 0;

    while (n > 1) {
        int a = extractMin(files, &n);
        int b = extractMin(files, &n);
        int sum = a + b;
        cost += sum;
        insertHeap(files, &n, sum);
    }

    return cost;
}

int main() {
    int files[] = {20, 30, 10, 5, 30};
    int n = sizeof(files) / sizeof(files[0]);

    int result = optimalMerge(files, n);
    printf("��С�ϲ�����: %d\n", result);

    return 0;
}
