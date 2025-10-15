#include <stdio.h>
#include <stdlib.h>

#define M 11        // ɢ�б��ȣ�����ȡ����
#define EMPTY -1    // �յ�Ԫ��־
#define DELETED -2  // ��ɾ����Ԫ��־

// ɢ�б�ṹ
typedef struct {
    int key;
} HashNode;

HashNode hashTable[M];

// ��ϣ������ȡ�෨
int hash(int key) {
    return key % M;
}

// ��ʼ��ɢ�б�
void initHashTable() {
    for (int i = 0; i < M; i++)
        hashTable[i].key = EMPTY;
}

// ����ؼ��֣�����̽�⣩
void insertHash(int key) {
    int h = hash(key);
    int i = 0;
    int pos;

    do {
        pos = (h + i) % M;
        if (hashTable[pos].key == EMPTY || hashTable[pos].key == DELETED) {
            hashTable[pos].key = key;
            printf("����ؼ��� %d ����λ %d\n", key, pos);
            return;
        }
        i++;
    } while (i < M);

    printf("ɢ�б��������޷����� %d\n", key);
}

// ���ҹؼ��֣�����̽�⣩
int searchHash(int key) {
    int h = hash(key);
    int i = 0;
    int pos;

    do {
        pos = (h + i) % M;
        if (hashTable[pos].key == EMPTY) {
            printf("�ؼ��� %d δ�ҵ���\n", key);
            return -1;
        }
        if (hashTable[pos].key == key) {
            printf("�ؼ��� %d �ڲ�λ %d �ҵ���\n", key, pos);
            return pos;
        }
        i++;
    } while (i < M);

    printf("�ؼ��� %d δ�ҵ���\n", key);
    return -1;
}

// ɾ���ؼ��֣����ɾ����
void deleteHash(int key) {
    int pos = searchHash(key);
    if (pos != -1) {
        hashTable[pos].key = DELETED;
        printf("�ؼ��� %d �ѱ�ɾ������λ %d ���Ϊ DELETED����\n", key, pos);
    }
}

// ��ʾɢ�б�
void displayHash() {
    printf("\n--- ɢ�б����� ---\n");
    for (int i = 0; i < M; i++) {
        if (hashTable[i].key == EMPTY)
            printf("[%2d] -> EMPTY\n", i);
        else if (hashTable[i].key == DELETED)
            printf("[%2d] -> DELETED\n", i);
        else
            printf("[%2d] -> %d\n", i, hashTable[i].key);
    }
    printf("-------------------\n");
}

// ����������
int main() {
    initHashTable();

    int data[] = {22, 41, 53, 46, 30, 13, 01, 67};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        insertHash(data[i]);
    }

    displayHash();

    // ���Ҳ���
    searchHash(41);
    searchHash(50);

    // ɾ������
    deleteHash(41);
    deleteHash(50);

    displayHash();

    // �ٲ�����Ԫ�أ���֤ɾ��λ�ÿɸ���
    insertHash(72);
    displayHash();

    return 0;
}
