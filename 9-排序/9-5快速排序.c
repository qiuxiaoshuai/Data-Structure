#include <stdio.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �������������������λ��
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high]; // ѡ���һ��Ԫ����Ϊ����
    int i = low - 1;
    int j, temp;

    printf("����: pivot = %d\n", pivot);

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // ���� arr[i] �� arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // ���� arr[i+1] �� arr[high] (�� pivot �ŵ���ȷλ��)
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf("  �������: ");
    printArray(arr, n);

    return i + 1;
}

// ��������
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);

        // �ݹ������������������
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    // int arr[] = {8,7,6,5,4,3,2,1};
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    quickSort(arr, 0, n - 1, n);

    printf("\n�����: ");
    printArray(arr, n);

    return 0;
}
