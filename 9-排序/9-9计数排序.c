#include <stdio.h>
#include <stdlib.h>

// �������е����ֵ
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// ��������
void countingSort(int arr[], int n) {
    int i, max = getMax(arr, n);

    // �����������飬����ʼ��Ϊ 0
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // ͳ��ÿ��Ԫ�س��ֵĴ���
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // ����ǰ׺�ͣ�ʹ count[i] ��ʾ <= i ��Ԫ�ظ���
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // �����������֤�ȶ���
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // ���������ԭ����
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("�����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
