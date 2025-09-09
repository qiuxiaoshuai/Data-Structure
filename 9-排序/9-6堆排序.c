#include <stdio.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 调整为大顶堆
void heapify(int arr[], int n, int i) {
    int largest = i;          // 先假设当前结点最大
    int left = 2 * i + 1;     // 左孩子
    int right = 2 * i + 2;    // 右孩子

    // 如果左孩子比当前结点大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右孩子比当前最大值还大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根结点，交换并递归调整
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(int arr[], int n) {
    // 1. 建堆（调整为大顶堆）
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    printf("初始大顶堆: ");
    printArray(arr, n);

    // 2. 逐个取出堆顶元素（最大值）
    for (int i = n - 1; i > 0; i--) {
        // 将堆顶与当前末尾交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        printf("交换堆顶和第 %d 个元素后: ", i);
        printArray(arr, n);

        // 调整剩余的堆
        heapify(arr, i, 0);

        printf("  调整堆后: ");
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    heapSort(arr, n);

    printf("\n排序后: ");
    printArray(arr, n);

    return 0;
}
