#include <stdio.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 希尔排序
void shellSort(int arr[], int n) {
    int gap, i, j, temp, step = 1;

    // 逐步缩小 gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        printf("第 %d 轮 (gap = %d):\n", step++, gap);

        // 对每个分组进行插入排序
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // 插入排序的变形：间隔为 gap
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;

            // 输出当前过程
            printf("  插入元素 %d 后: ", temp);
            printArray(arr, n);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    shellSort(arr, n);

    printf("排序后: ");
    printArray(arr, n);

    return 0;
}
