// 用非递归算法实现计算 哈夫曼树的带权路径长度(WPL)
// WPL: 叶节点权值×(叶节点层数-1) 求和
// 思路: 用非递归的后序遍历实现————当访问某个节点时, 此时栈中元素个数-1(减去其自身) 即为其所在层数-1

#include <windows.h>
#include "../implementation/BiTree.h"

int GET_WPL(BiTree *T)
{
    int WPL = 0;      // WPL带权路径长度
    BiTree *s[Max];   // 栈
    int top = -1;     // 栈顶指针
    BiTree *p = T;    // 游走指针
    BiTree *r = NULL; // 最近访问节点指针 (后序遍历算法所需)

    while (p || top != -1)
    {
        if (p)
        {
            s[++top] = p;
            p = p->lchild;
        }
        else
        {
            p = s[top];
            if (p->rchild && p->rchild != r)
            {
                p = p->rchild;
            }
            else
            {
                if (p->lchild == NULL && p->rchild == NULL) // 叶节点
                {
                    WPL = WPL + top * (p->data);
                }
                r = p;
                top--;
                p = NULL;
            }
        }
    }
    return WPL;
}

int main(void)
{
    BiTree root;
    BiTree *T = &root;
    create(&T);
    printf("Create Finish!\n");

    printf("WPL: %d\n", GET_WPL(T));
    system("pause");
    return 0;
}