#include <stdio.h>

// ��ӡ���麯��
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �۰����������
void binaryInsertionSort(int arr[], int n) {
    int i, j, key, left, right, mid, step = 1;

    for (i = 1; i < n; i++) {
        key = arr[i];
        left = 0;
        right = i - 1;

        // �ö��ַ����Ҳ���λ��
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        printf("�� %d ��: Ԫ�� %d ����λ�� -> %d\n", step++, key, left);

        // �� [left, i-1] ��Ԫ���������һλ
        for (j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        arr[left] = key;  // ���뵽��ȷλ��

        printf("  ���������: ");
        printArray(arr, n);
        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    binaryInsertionSort(arr, n);

    printf("�����: ");
    printArray(arr, n);

    return 0;
}
