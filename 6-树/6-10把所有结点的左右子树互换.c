#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
    char data;                // 存储节点的数据
    struct TreeNode* left;    // 左子节点
    struct TreeNode* right;   // 右子节点
} TreeNode;

// 创建新的节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 层序构造二叉树
TreeNode* buildTree(char* input) {
    if (*input == '\0') return NULL;

    // 创建根节点
    TreeNode* root = createNode(*input);
    input++;

    // 使用队列进行层序遍历构建树
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (*input != '\0') {
        TreeNode* current = queue[front++];
        
        // 左子节点
        if (*input != '#') {
            current->left = createNode(*input);
            queue[rear++] = current->left;
        }
        input++;

        // 右子节点
        if (*input != '#') {
            current->right = createNode(*input);
            queue[rear++] = current->right;
        }
        input++;
    }

    return root;
}

// 打印二叉树（层序遍历）
void printTree(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];
        if (current != NULL) {
            printf("%c ", current->data);
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        } else {
            printf("# ");
        }
    }
    printf("\n");
}

// 打印树的结构（递归打印树）
void printStructure(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    printStructure(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%c\n", root->data);
    printStructure(root->left, level + 1);
}

int hh(TreeNode *root){
    if(!root) return 0;
    TreeNode *p = root->left;
    root->left = root->right;
    root->right = p;
    hh(root->left);
    hh(root->right);
}

int main() {
    char input[100];
    printf("请输入二叉树的层序遍历字符串（使用 '#' 表示空节点）：");
    scanf("%s", input);

    TreeNode* root = buildTree(input);
    
    printf("树的层序遍历输出：\n");
    printTree(root);

    printf("树的结构输出：\n");
    printStructure(root, 0);

    hh(root);
    printf("hh树的层序遍历输出：\n");
    printTree(root);
    printStructure(root, 0);
    return 0;
}
