#include <stdio.h>
#include <stdlib.h>

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �ϲ��������������� arr[l..m], arr[m+1..r]
void merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;  // �������鳤��
    int n2 = r - m;      // �������鳤��

    // ��ʱ����
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // ��������
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // �ϲ�
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // ����ʣ�ಿ��
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);

    printf("�ϲ����� [%d,%d]: ", l, r);
    printArray(arr, n);
}

// �鲢����
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // ���Σ��ݹ��������Ҳ���
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        // �ϲ�
        merge(arr, l, m, r, n);
    }
}

int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ: ");
    printArray(arr, n);
    printf("\n");

    mergeSort(arr, 0, n - 1, n);

    printf("\n�����: ");
    printArray(arr, n);

    return 0;
}
