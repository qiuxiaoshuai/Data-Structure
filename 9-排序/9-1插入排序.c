#include <stdio.h>

// 打印数组函数
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 插入排序函数（带步骤输出）
void insertionSort(int arr[], int n) {
    int i, j, key, step = 1;
    for (i = 1; i < n; i++) {  // 从第二个元素开始
        key = arr[i];          
        j = i - 1;

        printf("第 %d 步: 插入元素 %d\n", step++, key);

        // 将比 key 大的元素后移
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

            printf("  移动元素后: ");
            printArray(arr, n);
        }

        // 插入 key 到正确的位置
        arr[j + 1] = key;

        printf("  插入完成:   ");
        printArray(arr, n);
        printf("\n");
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    insertionSort(arr, n);

    printf("排序后: ");
    printArray(arr, n);

    return 0;
}
