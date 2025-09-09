#include <stdio.h>
#include <stdlib.h>

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 获取数组中的最大值
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// 按 exp 位进行计数排序（exp = 1 -> 个位，10 -> 十位...）
void countSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // 输出数组
    int count[10] = {0};

    // 统计每个桶的数量
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // 计算前缀和（确定位置）
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 稳定排序：从后往前遍历
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 拷贝回原数组
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

// 基数排序
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // 找到最大值，决定位数
    int step = 1;

    // 按位排序，从个位到最高位
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        printf("第 %d 轮 (exp = %d): ", step++, exp);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    printArray(arr, n);
    printf("\n");

    radixSort(arr, n);

    printf("\n排序后: ");
    printArray(arr, n);

    return 0;
}
