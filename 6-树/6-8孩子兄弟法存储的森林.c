#include <stdio.h>
#include <stdlib.h>

// ==============================
// 一、孩子兄弟结点结构定义
// ==============================
typedef struct CSNode {
    char data;                    // 结点数据
    struct CSNode *firstchild;    // 指向第一个孩子
    struct CSNode *nextsibling;   // 指向右兄弟
} CSNode, *CSTree;

/*
 * 统计叶子结点数（孩子兄弟表示法）
 * 说明：
 *   - 输入 s 可以是某棵树的根，也可以是森林中某个根的指针（因为根与根用 nextsibling 串起来）
 *   - 叶子结点的判定：结点的 firstchild == NULL
 * 返回值：
 *   - 以 s 为起点的子结构中叶子结点的个数（整型）
 */
int add(CSTree s){
    if (s == NULL) 
        return 0;               // 空指针：没有结点，叶子数为 0（递归终止条件）

    int cont = 0;               // 计数器，累加叶子个数

    if (s->firstchild == NULL)  // 如果当前结点没有孩子
        cont++;                 // 当前结点就是一个叶子，计数 +1

    // 递归统计：先统计当前结点的孩子子树（第一个孩子及其后代）中的叶子数
    // 注意：调用 add(s->firstchild) 会遍历当前结点所有孩子（通过孩子的 nextsibling 链）
    cont += add(s->firstchild);

    // 再递归统计：统计当前结点的右兄弟及其后续兄弟（同一层其他子树）中的叶子数
    // 这样可以覆盖整个以 s 为起点的“森林”或兄弟链
    cont += add(s->nextsibling);

    return cont;                // 返回累计的叶子数
}


/*
 * 求树/森林深度（按结点数计）
 * 说明：
 *   - 输入 b 可以是某棵树的根，也可为森林中某个根（根们通过 nextsibling 串联）
 *   - 返回以 b 为起点的子结构的最大深度（深度按结点数计，空树返回 0）
 * 算法思想（递归）：
 *   - fdepth = 深度(第一个孩子) + 1  （+1 表示包含当前结点 b）
 *   - rdepth = 深度(右兄弟)            （右兄弟在同一层，不加 1）
 *   - 返回两者较大值（当前树更深，或同层其他树更深）
 */
int app(CSTree b){
    if (b == NULL) 
        return 0;               // 空树深度定义为 0（递归终止）

    // 计算以 b->firstchild 为根的子树深度，再 +1 把当前结点 b 算上
    int fdepth = app(b->firstchild) + 1;

    // 计算右兄弟（同一层其他根）的深度（不加 1）
    int rdepth = app(b->nextsibling);

    // 返回当前树（包含 b）的深度 与 兄弟链中最大深度 两者中较大的那个
    return (fdepth > rdepth) ? fdepth : rdepth;
}



// ==============================
// 二、构造示例森林
// 例子：
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
    // 动态创建各节点
    CSNode *A = (CSNode*)malloc(sizeof(CSNode));
    CSNode *B = (CSNode*)malloc(sizeof(CSNode));
    CSNode *C = (CSNode*)malloc(sizeof(CSNode));
    CSNode *D = (CSNode*)malloc(sizeof(CSNode));
    CSNode *E = (CSNode*)malloc(sizeof(CSNode));
    CSNode *F = (CSNode*)malloc(sizeof(CSNode));
    CSNode *G = (CSNode*)malloc(sizeof(CSNode));
    CSNode *H = (CSNode*)malloc(sizeof(CSNode));

    // 初始化数据域
    A->data='A'; B->data='B'; C->data='C'; D->data='D';
    E->data='E'; F->data='F'; G->data='G'; H->data='H';

    // 构造第一棵树 T1
    A->firstchild = B;    A->nextsibling = F;
    B->firstchild = NULL; B->nextsibling = C;
    C->firstchild = E;    C->nextsibling = D;
    D->firstchild = NULL; D->nextsibling = NULL;
    E->firstchild = NULL; E->nextsibling = NULL;

    // 构造第二棵树 T2
    F->firstchild = G;    F->nextsibling = NULL;
    G->firstchild = NULL; G->nextsibling = H;
    H->firstchild = NULL; H->nextsibling = NULL;

    return A;  // 返回森林的第一个根（A）
}


// ==============================
// 三、森林的先根遍历（先序遍历）
// 访问顺序：根 → 子树（递归） → 兄弟
// ==============================
void PreOrder(CSTree T) {
    if (T == NULL) return;
    printf("%c ", T->data);          // 访问根结点
    PreOrder(T->firstchild);         // 遍历第一个孩子
    PreOrder(T->nextsibling);        // 遍历兄弟结点
}


// ==============================
// 四、森林的后根遍历（后序遍历）
// 访问顺序：子树 → 根 → 兄弟
// ==============================
void PostOrder(CSTree T) {
    if (T == NULL) return;
    PostOrder(T->firstchild);        // 遍历孩子子树
    printf("%c ", T->data);          // 访问根结点
    PostOrder(T->nextsibling);       // 遍历兄弟结点
}


// ==============================
// 五、主函数测试
// ==============================
int main() {
    CSTree forest = createForest();

    printf("森林的先根遍历结果: ");
    PreOrder(forest);
    printf("\n");

    printf("森林的后根遍历结果: ");
    PostOrder(forest);
    printf("\n");

    printf("森林叶子结点为：%d",add(forest));
    printf("森林的最高：%d",app(forest));
    return 0;
}
