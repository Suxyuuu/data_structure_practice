// 用非递归算法 找到二叉树中一节点q的兄弟节点
// 思路: 用层序遍历/后序遍历(此处用层序遍历) 当访问一个节点时 判断其孩子是否为q 即可

#include <windows.h>
#include "../implementation/BiTree.h"

BiTree *getbro(BiTree *T, BiTree *q)
{
    BiTree *queue[Max];
    int front, rear;
    front = rear = -1;
    BiTree *p = T;
    queue[++rear] = p;

    while (front != rear)
    {
        p = queue[++front];
        if (p->lchild == q)
        {
            return p->rchild == NULL ? NULL : p->rchild;
        }
        if (p->rchild == q)
        {
            return p->lchild == NULL ? NULL : p->lchild;
        }
        if (p->lchild != NULL)
        {
            queue[++rear] = p->lchild;
        }
        if (p->rchild != NULL)
        {
            queue[++rear] = p->rchild;
        }
    }
}
