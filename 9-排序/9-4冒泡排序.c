#include <stdio.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 冒泡排序（带步骤输出）
void bubbleSort(int arr[], int n) {
    int i, j, temp, step = 1;
    int swapped;  // 标记是否发生交换，用于优化

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        printf("第 %d 轮排序:\n", step++);

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换相邻元素
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }

            printf("  比较 [%d,%d] 后: ", j, j + 1);
            printArray(arr, n);
        }

        // 如果本轮没有发生交换，说明数组已排序好，直接退出
        if (!swapped) break;

        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    bubbleSort(arr, n);

    printf("排序后: ");
    printArray(arr, n);

    return 0;
}
