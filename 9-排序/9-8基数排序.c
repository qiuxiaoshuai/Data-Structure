#include <stdio.h>
#include <stdlib.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ��ȡ�����е����ֵ
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// �� exp λ���м�������exp = 1 -> ��λ��10 -> ʮλ...��
void countSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // �������
    int count[10] = {0};

    // ͳ��ÿ��Ͱ������
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // ����ǰ׺�ͣ�ȷ��λ�ã�
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // �ȶ����򣺴Ӻ���ǰ����
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // ������ԭ����
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

// ��������
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // �ҵ����ֵ������λ��
    int step = 1;

    // ��λ���򣬴Ӹ�λ�����λ
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        printf("�� %d �� (exp = %d): ", step++, exp);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    radixSort(arr, n);

    printf("\n�����: ");
    printArray(arr, n);

    return 0;
}
