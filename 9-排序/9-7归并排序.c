#include <stdio.h>
#include <stdlib.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 合并两个有序子数组 arr[l..m], arr[m+1..r]
void merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;  // 左子数组长度
    int n2 = r - m;      // 右子数组长度

    // 临时数组
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 拷贝数据
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // 合并
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 复制剩余部分
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);

    printf("合并区间 [%d,%d]: ", l, r);
    printArray(arr, n);
}

// 归并排序
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // 分治：递归排序左右部分
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        // 合并
        merge(arr, l, m, r, n);
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    mergeSort(arr, 0, n - 1, n);

    printf("\n排序后: ");
    printArray(arr, n);

    return 0;
}
