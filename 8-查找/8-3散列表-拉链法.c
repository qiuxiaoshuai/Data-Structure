#include <stdio.h>
#include <stdlib.h>

#define M 7  // ɢ�б��ȣ�����Ч���Ϻã�

// ����ڵ�ṹ
typedef struct Node {
    int key;             // �ؼ���
    struct Node* next;   // ָ����һ���ڵ�
} Node;

// ɢ�б�ÿ����λ���һ�������ͷָ��
Node* hashTable[M] = {NULL};

// ��ϣ������ȡ�෨
int hash(int key) {
    return key % M;
}

// ����Ԫ��
void insertHash(int key) {
    int h = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // ���ò�λΪ�գ�ֱ�Ӳ���
    if (hashTable[h] == NULL) {
        hashTable[h] = newNode;
    } else {
        // ����ͷ�巨����������߲���Ч��
        newNode->next = hashTable[h];
        hashTable[h] = newNode;
    }
    printf("����ؼ��� %d ����λ %d\n", key, h);
}

// ����Ԫ��
Node* searchHash(int key) {
    int h = hash(key);
    Node* p = hashTable[h];
    while (p != NULL) {
        if (p->key == key) {
            printf("�ؼ��� %d �ڲ�λ %d �ҵ���\n", key, h);
            return p;
        }
        p = p->next;
    }
    printf("�ؼ��� %d δ�ҵ���\n", key);
    return NULL;
}

// ɾ��Ԫ��
void deleteHash(int key) {
    int h = hash(key);
    Node* p = hashTable[h];
    Node* prev = NULL;

    while (p != NULL) {
        if (p->key == key) {
            if (prev == NULL)
                hashTable[h] = p->next;  // ɾ��ͷ�ڵ�
            else
                prev->next = p->next;    // ɾ���м�ڵ�

            free(p);
            printf("�ؼ��� %d �ѴӲ�λ %d ɾ����\n", key, h);
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("�ؼ��� %d �����ڣ��޷�ɾ����\n", key);
}

// ��ʾ����ɢ�б�
void displayHash() {
    printf("\n--- ɢ�б����� ---\n");
    for (int i = 0; i < M; i++) {
        printf("[%d] -> ", i);
        Node* p = hashTable[i];
        while (p != NULL) {
            printf("%d -> ", p->key);
            p = p->next;
        }
        printf("NULL\n");
    }
    printf("-------------------\n");
}

// ����������
int main() {
    int data[] = {15, 28, 19, 20, 33, 12, 17, 44};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        insertHash(data[i]);
    }

    displayHash();

    // ���Ҳ���
    searchHash(19);
    searchHash(21);

    // ɾ������
    deleteHash(28);
    deleteHash(21);

    displayHash();

    return 0;
}
