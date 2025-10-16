#include <stdio.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 分区函数：返回枢轴的位置
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high]; // 选最后一个元素作为枢轴
    int i = low - 1;
    int j, temp;

    printf("分区: pivot = %d\n", pivot);

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交换 arr[i+1] 和 arr[high] (把 pivot 放到正确位置)
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf("  分区完成: ");
    printArray(arr, n);

    return i + 1;
}

// 快速排序
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);

        // 递归排序左区间和右区间
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    // int arr[] = {8,7,6,5,4,3,2,1};
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    quickSort(arr, 0, n - 1, n);

    printf("\n排序后: ");
    printArray(arr, n);

    return 0;
}
