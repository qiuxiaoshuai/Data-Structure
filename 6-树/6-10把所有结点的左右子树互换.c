#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
    char data;                // �洢�ڵ������
    struct TreeNode* left;    // ���ӽڵ�
    struct TreeNode* right;   // ���ӽڵ�
} TreeNode;

// �����µĽڵ�
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// �����������
TreeNode* buildTree(char* input) {
    if (*input == '\0') return NULL;

    // �������ڵ�
    TreeNode* root = createNode(*input);
    input++;

    // ʹ�ö��н��в������������
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (*input != '\0') {
        TreeNode* current = queue[front++];
        
        // ���ӽڵ�
        if (*input != '#') {
            current->left = createNode(*input);
            queue[rear++] = current->left;
        }
        input++;

        // ���ӽڵ�
        if (*input != '#') {
            current->right = createNode(*input);
            queue[rear++] = current->right;
        }
        input++;
    }

    return root;
}

// ��ӡ�����������������
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

// ��ӡ���Ľṹ���ݹ��ӡ����
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
    printf("������������Ĳ�������ַ�����ʹ�� '#' ��ʾ�սڵ㣩��");
    scanf("%s", input);

    TreeNode* root = buildTree(input);
    
    printf("���Ĳ�����������\n");
    printTree(root);

    printf("���Ľṹ�����\n");
    printStructure(root, 0);

    hh(root);
    printf("hh���Ĳ�����������\n");
    printTree(root);
    printStructure(root, 0);
    return 0;
}
