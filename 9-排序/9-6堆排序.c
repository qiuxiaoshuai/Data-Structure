#include <stdio.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ����Ϊ�󶥶�
void heapify(int arr[], int n, int i) {
    int largest = i;          // �ȼ��赱ǰ������
    int left = 2 * i + 1;     // ����
    int right = 2 * i + 2;    // �Һ���

    // ������ӱȵ�ǰ����
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ����Һ��ӱȵ�ǰ���ֵ����
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���Ǹ���㣬�������ݹ����
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// ������
void heapSort(int arr[], int n) {
    // 1. ���ѣ�����Ϊ�󶥶ѣ�
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    printf("��ʼ�󶥶�: ");
    printArray(arr, n);

    // 2. ���ȡ���Ѷ�Ԫ�أ����ֵ��
    for (int i = n - 1; i > 0; i--) {
        // ���Ѷ��뵱ǰĩβ����
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        printf("�����Ѷ��͵� %d ��Ԫ�غ�: ", i);
        printArray(arr, n);

        // ����ʣ��Ķ�
        heapify(arr, i, 0);

        printf("  �����Ѻ�: ");
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    heapSort(arr, n);

    printf("\n�����: ");
    printArray(arr, n);

    return 0;
}
