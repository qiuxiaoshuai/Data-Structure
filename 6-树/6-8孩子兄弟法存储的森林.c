#include <stdio.h>
#include <stdlib.h>

// ==============================
// һ�������ֵܽ��ṹ����
// ==============================
typedef struct CSNode {
    char data;                    // �������
    struct CSNode *firstchild;    // ָ���һ������
    struct CSNode *nextsibling;   // ָ�����ֵ�
} CSNode, *CSTree;

/*
 * ͳ��Ҷ�ӽ�����������ֵܱ�ʾ����
 * ˵����
 *   - ���� s ������ĳ�����ĸ���Ҳ������ɭ����ĳ������ָ�루��Ϊ������� nextsibling ��������
 *   - Ҷ�ӽ����ж������� firstchild == NULL
 * ����ֵ��
 *   - �� s Ϊ�����ӽṹ��Ҷ�ӽ��ĸ��������ͣ�
 */
int add(CSTree s){
    if (s == NULL) 
        return 0;               // ��ָ�룺û�н�㣬Ҷ����Ϊ 0���ݹ���ֹ������

    int cont = 0;               // ���������ۼ�Ҷ�Ӹ���

    if (s->firstchild == NULL)  // �����ǰ���û�к���
        cont++;                 // ��ǰ������һ��Ҷ�ӣ����� +1

    // �ݹ�ͳ�ƣ���ͳ�Ƶ�ǰ���ĺ�����������һ�����Ӽ��������е�Ҷ����
    // ע�⣺���� add(s->firstchild) �������ǰ������к��ӣ�ͨ�����ӵ� nextsibling ����
    cont += add(s->firstchild);

    // �ٵݹ�ͳ�ƣ�ͳ�Ƶ�ǰ�������ֵܼ�������ֵܣ�ͬһ�������������е�Ҷ����
    // �������Ը��������� s Ϊ���ġ�ɭ�֡����ֵ���
    cont += add(s->nextsibling);

    return cont;                // �����ۼƵ�Ҷ����
}


/*
 * ����/ɭ����ȣ���������ƣ�
 * ˵����
 *   - ���� b ������ĳ�����ĸ���Ҳ��Ϊɭ����ĳ����������ͨ�� nextsibling ������
 *   - ������ b Ϊ�����ӽṹ�������ȣ���Ȱ�������ƣ��������� 0��
 * �㷨˼�루�ݹ飩��
 *   - fdepth = ���(��һ������) + 1  ��+1 ��ʾ������ǰ��� b��
 *   - rdepth = ���(���ֵ�)            �����ֵ���ͬһ�㣬���� 1��
 *   - �������߽ϴ�ֵ����ǰ�������ͬ�����������
 */
int app(CSTree b){
    if (b == NULL) 
        return 0;               // ������ȶ���Ϊ 0���ݹ���ֹ��

    // ������ b->firstchild Ϊ����������ȣ��� +1 �ѵ�ǰ��� b ����
    int fdepth = app(b->firstchild) + 1;

    // �������ֵܣ�ͬһ��������������ȣ����� 1��
    int rdepth = app(b->nextsibling);

    // ���ص�ǰ�������� b������� �� �ֵ����������� �����нϴ���Ǹ�
    return (fdepth > rdepth) ? fdepth : rdepth;
}



// ==============================
// ��������ʾ��ɭ��
// ���ӣ�
// T1:      A
//         /|\
//        B C D
//          |
//          E
//
// T2:      F
//         / \
//        G   H
// ==============================
CSTree createForest() {
    // ��̬�������ڵ�
    CSNode *A = (CSNode*)malloc(sizeof(CSNode));
    CSNode *B = (CSNode*)malloc(sizeof(CSNode));
    CSNode *C = (CSNode*)malloc(sizeof(CSNode));
    CSNode *D = (CSNode*)malloc(sizeof(CSNode));
    CSNode *E = (CSNode*)malloc(sizeof(CSNode));
    CSNode *F = (CSNode*)malloc(sizeof(CSNode));
    CSNode *G = (CSNode*)malloc(sizeof(CSNode));
    CSNode *H = (CSNode*)malloc(sizeof(CSNode));

    // ��ʼ��������
    A->data='A'; B->data='B'; C->data='C'; D->data='D';
    E->data='E'; F->data='F'; G->data='G'; H->data='H';

    // �����һ���� T1
    A->firstchild = B;    A->nextsibling = F;
    B->firstchild = NULL; B->nextsibling = C;
    C->firstchild = E;    C->nextsibling = D;
    D->firstchild = NULL; D->nextsibling = NULL;
    E->firstchild = NULL; E->nextsibling = NULL;

    // ����ڶ����� T2
    F->firstchild = G;    F->nextsibling = NULL;
    G->firstchild = NULL; G->nextsibling = H;
    H->firstchild = NULL; H->nextsibling = NULL;

    return A;  // ����ɭ�ֵĵ�һ������A��
}


// ==============================
// ����ɭ�ֵ��ȸ����������������
// ����˳�򣺸� �� �������ݹ飩 �� �ֵ�
// ==============================
void PreOrder(CSTree T) {
    if (T == NULL) return;
    printf("%c ", T->data);          // ���ʸ����
    PreOrder(T->firstchild);         // ������һ������
    PreOrder(T->nextsibling);        // �����ֵܽ��
}


// ==============================
// �ġ�ɭ�ֵĺ�����������������
// ����˳������ �� �� �� �ֵ�
// ==============================
void PostOrder(CSTree T) {
    if (T == NULL) return;
    PostOrder(T->firstchild);        // ������������
    printf("%c ", T->data);          // ���ʸ����
    PostOrder(T->nextsibling);       // �����ֵܽ��
}


// ==============================
// �塢����������
// ==============================
int main() {
    CSTree forest = createForest();

    printf("ɭ�ֵ��ȸ��������: ");
    PreOrder(forest);
    printf("\n");

    printf("ɭ�ֵĺ���������: ");
    PostOrder(forest);
    printf("\n");

    printf("ɭ��Ҷ�ӽ��Ϊ��%d",add(forest));
    printf("ɭ�ֵ���ߣ�%d",app(forest));
    return 0;
}
