#include <stdio.h>
#include <stdlib.h>

#define M 7  // 散列表长度（素数效果较好）

// 链表节点结构
typedef struct Node {
    int key;             // 关键字
    struct Node* next;   // 指向下一个节点
} Node;

// 散列表：每个槽位存放一个链表的头指针
Node* hashTable[M] = {NULL};

// 哈希函数：取余法
int hash(int key) {
    return key % M;
}

// 插入元素
void insertHash(int key) {
    int h = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // 若该槽位为空，直接插入
    if (hashTable[h] == NULL) {
        hashTable[h] = newNode;
    } else {
        // 否则头插法插入链表，提高插入效率
        newNode->next = hashTable[h];
        hashTable[h] = newNode;
    }
    printf("插入关键字 %d 到槽位 %d\n", key, h);
}

// 查找元素
Node* searchHash(int key) {
    int h = hash(key);
    Node* p = hashTable[h];
    while (p != NULL) {
        if (p->key == key) {
            printf("关键字 %d 在槽位 %d 找到。\n", key, h);
            return p;
        }
        p = p->next;
    }
    printf("关键字 %d 未找到。\n", key);
    return NULL;
}

// 删除元素
void deleteHash(int key) {
    int h = hash(key);
    Node* p = hashTable[h];
    Node* prev = NULL;

    while (p != NULL) {
        if (p->key == key) {
            if (prev == NULL)
                hashTable[h] = p->next;  // 删除头节点
            else
                prev->next = p->next;    // 删除中间节点

            free(p);
            printf("关键字 %d 已从槽位 %d 删除。\n", key, h);
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("关键字 %d 不存在，无法删除。\n", key);
}

// 显示整个散列表
void displayHash() {
    printf("\n--- 散列表内容 ---\n");
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

// 主函数测试
int main() {
    int data[] = {15, 28, 19, 20, 33, 12, 17, 44};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        insertHash(data[i]);
    }

    displayHash();

    // 查找测试
    searchHash(19);
    searchHash(21);

    // 删除测试
    deleteHash(28);
    deleteHash(21);

    displayHash();

    return 0;
}
