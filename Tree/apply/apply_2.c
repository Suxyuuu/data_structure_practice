// 写一非递归算法 输出二叉树某一值为item的节点的所有祖先节点 [假设该二叉树中仅有一个满足条件的节点]
// 做法: 采用非递归后序遍历 当访问到该节点时 栈中元素即为其祖先节点

#include "../implementation/BiTree.h"
#include <windows.h>

void GetAncestors(BiTree *T, int item);
// void PrintResult(BiTree *p);

int main(void)
{
    BiTree root;
    BiTree *T = &root;
    create(&T);
    printf("Create Finish!\n");

    GetAncestors(T, 4);
    system("pause");
    return 0;
}

void GetAncestors(BiTree *T, int item)
{
    BiTree *s[Max];
    int top = -1; // 建立栈
    BiTree *cur = T;
    BiTree *pre = NULL; // 存放当前结点指针 和 最近访问过的节点指针

    while (cur || top != -1)
    {
        if (cur)
        {
            s[++top] = cur;
            cur = cur->lchild;
        }
        else
        {
            cur = s[top];
            if (cur->rchild && cur->rchild != pre)
            {
                cur = cur->rchild;
            }
            else
            {
                if (cur->data == item)
                {
                    goto PrintResult;
                    return;
                }
                else
                {
                    s[top--] = NULL;
                    pre = cur;
                    cur = NULL;
                }
            }
        }
    }

PrintResult:
{
    int num = top;
    printf("Ancestors:");
    while (num >= 0)
    {
        printf("%d ", s[num]->data);
        num--;
    }
    printf("\n");
}
}
