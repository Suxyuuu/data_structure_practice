// 普通二叉树的实现(链表)
// 遍历操作的实现: 前序遍历(递归/非递归) 中序遍历(递归/非递归) 后序遍历(递归/非递归) 层序遍历

/* 输入方式 仅支持非负数的输入 用负数来表示无子树[若数据类型为字符 则选择一特殊字符来代替即可]
 * 例:
 *               1
 *             /   \
 *           2       3
 *         /   \       \
 *        4     5       6
 *               \     /
 *                7   8
 *   输入: (以下-1可用任意负数代替)
 *   1
 *   2
 *   4
 *   -1
 *   -1
 *   5
 *   -1
 *   7
 *   -1
 *   -1
 *   3
 *   -1
 *   6
 *   8
 *   -1
 *   -1
 *   -1
*/
#if !defined(_BITREE_H_)
#define _BITREE_H_

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define Max 100
typedef struct BiTree
{
    int data;
    BiTree *lchild;
    BiTree *rchild;
} BiTree;

typedef struct stack
{
    BiTree *node[Max];
    int top;
} stack;

void create(BiTree **T); // 创建二叉树

bool pre_order_recursion(BiTree *T); // 三种遍历方式(使用递归)
bool mid_order_recursion(BiTree *T);
bool rear_order_recursion(BiTree *T);

bool pre_order_notrecursion(BiTree *T); // 三种遍历方式(不使用递归)
bool mid_order_notrecursion(BiTree *T);
bool rear_order_notrecursion_1(BiTree *T);
bool rear_order_notrecursion_2(BiTree *T); // 后序遍历的非递归实现方式较为特殊 共有两种实现方式

bool layer_order(BiTree *T); // 层序遍历 使用队列

// 创建二叉树
void create(BiTree **T)
{
    int num;
    scanf("%d", &num);
    if (num < 0) // 负数表示空节点
    {
        *T = NULL;
        return;
    }
    *T = (BiTree *)malloc(sizeof(BiTree));
    (*T)->data = num;
    create(&((*T)->lchild));
    create(&((*T)->rchild));
}

// 前序遍历 递归
bool pre_order_recursion(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }
    printf("%d ", T->data);
    pre_order_recursion(T->lchild);
    pre_order_recursion(T->rchild);
    return true;
}

// 中序遍历 递归
bool mid_order_recursion(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }
    mid_order_recursion(T->lchild);
    printf("%d ", T->data);
    mid_order_recursion(T->rchild);
    return true;
}

// 后序遍历 递归
bool rear_order_recursion(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }
    rear_order_recursion(T->lchild);
    rear_order_recursion(T->rchild);
    printf("%d ", T->data);
    return true;
}

// 前序遍历 非递归
bool pre_order_notrecursion(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }

    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    BiTree *p = T;

    while (p || s->top != -1)
    {
        if (p != NULL)
        {
            printf("%d ", p->data);  // 访问节点
            s->node[++(s->top)] = p; // 入栈
            p = p->lchild;
        }
        else
        {
            p = s->node[s->top];
            s->node[(s->top)--] = NULL; // 出栈
            p = p->rchild;
        }
    }

    return true;
}

// 中序遍历 非递归
bool mid_order_notrecursion(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }

    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    BiTree *p = T;

    while (p || s->top != -1)
    {
        if (p != NULL)
        {
            s->node[++(s->top)] = p; // 入栈
            p = p->lchild;
        }
        else
        {
            p = s->node[s->top];
            printf("%d ", p->data);     // 访问节点
            s->node[(s->top)--] = NULL; // 出栈
            p = p->rchild;
        }
    }

    return true;
}

/* 后序遍历 非递归 第一种:
 *   将前序遍历的非递归形式 访问左右子树互换 最后再逆序
 *   原因: 
 *      前序 根 左 右 --> 交换左右子树 (该步实现与前序遍历非递归类似)
 *      得到 根 右 左 --> 逆置 (该步通过访问节点时将节点压入另一个栈, 最后统一输出, 即为逆置)
 *      得到 左 右 根 --> 恰好为后序遍历
*/
bool rear_order_notrecursion_1(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }

    stack *s = (stack *)malloc(sizeof(stack)); // 用来遍历的栈
    s->top = -1;
    stack *output = (stack *)malloc(sizeof(stack)); // 用来输出用的栈
    output->top = -1;
    BiTree *p = T;

    while (p || s->top != -1)
    {
        if (p != NULL)
        {
            output->node[++(output->top)] = p; // 访问节点
            s->node[++(s->top)] = p;           // 入栈
            p = p->rchild;                     // 交换左右子树
        }
        else
        {
            p = s->node[s->top];
            s->node[(s->top)--] = NULL; // 出栈
            p = p->lchild;              // 交换左右子树
        }
    }
    // 输出遍历结果
    while (output->top != -1)
    {
        printf("%d ", output->node[(output->top)--]->data);
    }

    return true;
}

/* 后序遍历 非递归 第二种:
 *   由于后序遍历需要先访问左子树与右子树后才访问根节点
 *   因此如果遍历到了一个节点后 需要判断是否访问过右子树
 *   访问过 则访问该节点本身 / 未访问过 则访问该节点的右子树
 *   解决方法: 用一个指针来记录最近访问过的节点(如果轮到访问某个节点 其本身有右子树 则最近访问过的节点一定是其右子树的根节点)
*/
bool rear_order_notrecursion_2(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }

    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    BiTree *p = T;
    BiTree *r = NULL; // 记录最近访问过的节点

    while (p || s->top != -1)
    {
        if (p)
        {
            s->node[++(s->top)] = p;
            p = p->lchild;
        }
        else
        {
            p = s->node[s->top];
            if (p->rchild && r != p->rchild)
            {
                // s->node[(s->top)--] = NULL;
                p = p->rchild;
            }
            else
            {
                printf("%d ", p->data);
                s->node[(s->top)--] = NULL;
                r = p;
                p = NULL;
            }
        }
    }

    return true;
}

// 层序遍历 使用队列
bool layer_order(BiTree *T)
{
    if (T == NULL)
    {
        return false;
    }

    typedef struct queue
    {
        BiTree *node[Max];
        int front;
        int rear;
    } queue;

    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = 0;
    BiTree *p = T;
    q->node[q->rear++] = T;

    while (q->front != q->rear)
    {
        p = q->node[q->front];
        printf("%d ", p->data);
        q->node[q->front] = NULL;
        q->front = (q->front + 1) % Max;
        if (p->lchild)
        {
            q->node[q->rear] = p->lchild;
            q->rear = (q->rear + 1) % Max;
        }
        if (p->rchild)
        {
            q->node[q->rear] = p->rchild;
            q->rear = (q->rear + 1) % Max;
        }
    }

    return true;
}

#endif // _BITREE_H_
