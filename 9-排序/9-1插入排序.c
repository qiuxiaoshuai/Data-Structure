#include <stdio.h>

// ��ӡ���麯��
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �����������������������
void insertionSort(int arr[], int n) {
    int i, j, key, step = 1;
    for (i = 1; i < n; i++) {  // �ӵڶ���Ԫ�ؿ�ʼ
        key = arr[i];          
        j = i - 1;

        printf("�� %d ��: ����Ԫ�� %d\n", step++, key);

        // ���� key ���Ԫ�غ���
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

            printf("  �ƶ�Ԫ�غ�: ");
            printArray(arr, n);
        }

        // ���� key ����ȷ��λ��
        arr[j + 1] = key;

        printf("  �������:   ");
        printArray(arr, n);
        printf("\n");
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    insertionSort(arr, n);

    printf("�����: ");
    printArray(arr, n);

    return 0;
}
