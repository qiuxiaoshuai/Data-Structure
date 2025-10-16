#include <stdio.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ð�����򣨴����������
void bubbleSort(int arr[], int n) {
    int i, j, temp, step = 1;
    int swapped;  // ����Ƿ��������������Ż�

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        printf("�� %d ������:\n", step++);

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ��������Ԫ��
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }

            printf("  �Ƚ� [%d,%d] ��: ", j, j + 1);
            printArray(arr, n);
        }

        // �������û�з���������˵������������ã�ֱ���˳�
        if (!swapped) break;

        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    bubbleSort(arr, n);

    printf("�����: ");
    printArray(arr, n);

    return 0;
}
