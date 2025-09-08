#include <stdio.h>

// 打印数组函数
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 折半插入排序函数
void binaryInsertionSort(int arr[], int n) {
    int i, j, key, left, right, mid, step = 1;

    for (i = 1; i < n; i++) {
        key = arr[i];
        left = 0;
        right = i - 1;

        // 用二分法查找插入位置
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        printf("第 %d 步: 元素 %d 插入位置 -> %d\n", step++, key, left);

        // 将 [left, i-1] 的元素整体后移一位
        for (j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        arr[left] = key;  // 插入到正确位置

        printf("  插入后数组: ");
        printArray(arr, n);
        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    binaryInsertionSort(arr, n);

    printf("排序后: ");
    printArray(arr, n);

    return 0;
}
