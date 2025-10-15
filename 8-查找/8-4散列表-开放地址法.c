#include <stdio.h>
#include <stdlib.h>

#define M 11        // 散列表长度，建议取素数
#define EMPTY -1    // 空单元标志
#define DELETED -2  // 被删除单元标志

// 散列表结构
typedef struct {
    int key;
} HashNode;

HashNode hashTable[M];

// 哈希函数：取余法
int hash(int key) {
    return key % M;
}

// 初始化散列表
void initHashTable() {
    for (int i = 0; i < M; i++)
        hashTable[i].key = EMPTY;
}

// 插入关键字（线性探测）
void insertHash(int key) {
    int h = hash(key);
    int i = 0;
    int pos;

    do {
        pos = (h + i) % M;
        if (hashTable[pos].key == EMPTY || hashTable[pos].key == DELETED) {
            hashTable[pos].key = key;
            printf("插入关键字 %d 到槽位 %d\n", key, pos);
            return;
        }
        i++;
    } while (i < M);

    printf("散列表已满，无法插入 %d\n", key);
}

// 查找关键字（线性探测）
int searchHash(int key) {
    int h = hash(key);
    int i = 0;
    int pos;

    do {
        pos = (h + i) % M;
        if (hashTable[pos].key == EMPTY) {
            printf("关键字 %d 未找到。\n", key);
            return -1;
        }
        if (hashTable[pos].key == key) {
            printf("关键字 %d 在槽位 %d 找到。\n", key, pos);
            return pos;
        }
        i++;
    } while (i < M);

    printf("关键字 %d 未找到。\n", key);
    return -1;
}

// 删除关键字（标记删除）
void deleteHash(int key) {
    int pos = searchHash(key);
    if (pos != -1) {
        hashTable[pos].key = DELETED;
        printf("关键字 %d 已被删除（槽位 %d 标记为 DELETED）。\n", key, pos);
    }
}

// 显示散列表
void displayHash() {
    printf("\n--- 散列表内容 ---\n");
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

// 主函数测试
int main() {
    initHashTable();

    int data[] = {22, 41, 53, 46, 30, 13, 01, 67};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        insertHash(data[i]);
    }

    displayHash();

    // 查找测试
    searchHash(41);
    searchHash(50);

    // 删除测试
    deleteHash(41);
    deleteHash(50);

    displayHash();

    // 再插入新元素，验证删除位置可复用
    insertHash(72);
    displayHash();

    return 0;
}
