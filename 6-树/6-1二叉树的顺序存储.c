#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int last_index;
} SeqBiTree;

void initTree(SeqBiTree* tree) {
    tree->last_index = -1;
}

void insert(SeqBiTree* tree, char value) {
    if (tree->last_index + 1 >= MAX_SIZE) return;
    tree->data[++tree->last_index] = value;
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) printf(" ");
}

void printTree(SeqBiTree* tree) {
    int n = tree->last_index + 1;
    if (n == 0) return;

    int height = 0;
    while ((1 << height) <= n) height++;  // 计算树高

    int max_width = (1 << height) * 2; // 最大宽度估算

    int index = 0;
    for (int level = 0; level < height; level++) {
        int nodes = 1 << level;
        int space_between = max_width / nodes - 1;
        int space_front = space_between / 2;

        printSpaces(space_front);
        for (int i = 0; i < nodes && index < n; i++, index++) {
            printf("%c", tree->data[index]);
            if (i < nodes - 1) printSpaces(space_between);
        }
        printf("\n");
    }
}

int main() {
    SeqBiTree tree;
    initTree(&tree);

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    for (int i = 0; i < 7; i++) insert(&tree, nodes[i]);

    printf("\n二叉树结构（无连接线）：\n\n");
    printTree(&tree);

    return 0;
}
