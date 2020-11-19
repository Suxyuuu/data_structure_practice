// 写一非递归算法 交换数据信息为item的节点的左，右子树的位置 [假设该二叉树中仅有一个满足条件的节点]
// 做法: 采用层序遍历的方式来找到该节点 然后交换左右子树指针即可

#include "../implementation/BiTree.h"
#include <windows.h>

void exchange(BiTree *T, int item)
{
    BiTree *a[Max];
    int front, rear;
    front = rear = -1;
    BiTree *p;
    a[++rear] = T;
    while (front != rear)
    {
        p = a[++front];
        if (p->data == item)
        {
            break;
        }
        if (p->lchild)
        {
            a[++rear] = p->lchild;
            a[++rear] = p->rchild;
        }
    }
    BiTree *temp;
    temp = p->lchild;
    p->lchild = p->rchild;
    p->rchild = temp;
}

int main(void)
{
    BiTree root;
    BiTree *T = &root;
    create(&T);
    printf("Create Finish!\n");

    layer_order(T);
    printf("--> Layer_order\n");

    exchange(T, 2);

    layer_order(T);
    printf("--> Layer_order\n");

    //printf("\n");
    system("pause");
    return 0;
}
