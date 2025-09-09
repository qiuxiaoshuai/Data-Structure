#include <stdio.h>
#include <stdlib.h>

// 找数组中的最大值
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// 计数排序
void countingSort(int arr[], int n) {
    int i, max = getMax(arr, n);

    // 创建计数数组，并初始化为 0
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // 统计每个元素出现的次数
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 计算前缀和，使 count[i] 表示 <= i 的元素个数
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 逆序遍历，保证稳定性
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将结果拷回原数组
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("排序后: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
