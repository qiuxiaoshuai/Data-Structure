#include <stdio.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ϣ������
void shellSort(int arr[], int n) {
    int gap, i, j, temp, step = 1;

    // ����С gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        printf("�� %d �� (gap = %d):\n", step++, gap);

        // ��ÿ��������в�������
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // ��������ı��Σ����Ϊ gap
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;

            // �����ǰ����
            printf("  ����Ԫ�� %d ��: ", temp);
            printArray(arr, n);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    shellSort(arr, n);

    printf("�����: ");
    printArray(arr, n);

    return 0;
}
