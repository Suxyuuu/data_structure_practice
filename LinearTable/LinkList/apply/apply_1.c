// 实现单链表的选择排序 [不能增加和使用新的链节点空间 不得改变链节点的数据域中原有的内容]

#include "../implementation/linklist_single.h"
#include <windows.h>

void selectsort(LinkList *list)
{
    LinkList *cur = list->next; // 游走指针
    LinkList *precur = list;    // 游走指针的前驱
    LinkList *ready = list;     // 指向已经排好序的序列的最后一个节点
    LinkList *min;              // 最小值指针
    LinkList *premin;           // 最小值指针的前驱

    while (ready->next)
    {
        min = ready->next;
        premin = ready;

        while (cur)
        {
            if (cur->e < min->e)
            {
                min = cur;
                premin = precur; // 找到最小值节点
            }
            precur = cur;
            cur = cur->next;
        }
        if (min != ready->next && ready->next != premin) // 交换 不相邻两个节点
        {
            LinkList *temp;
            temp = ready->next;
            premin->next = min->next;
            ready->next = temp->next;
            min->next = ready->next;
            ready->next = min;
            temp->next = premin->next;
            premin->next = temp;
        }
        if (min != ready->next && ready->next == premin) // 交换 相邻两个节点
        {
            premin->next = min->next;
            min->next = premin;
            ready->next = min;
        }

        ready = ready->next;
        cur = ready->next;
        precur = ready;
    }
}

int main(void)
{
    LinkList L = CreateList();
    ListInsert_tail(&L, 5);
    ListInsert_tail(&L, 9);
    ListInsert_tail(&L, 7);
    ListInsert_tail(&L, 8);
    ListInsert_tail(&L, 6);
    ListInsert_tail(&L, 1);
    ListInsert_tail(&L, 3);
    ListInsert_tail(&L, 4);
    ListInsert_tail(&L, 2);
    PrintList(&L);

    selectsort(&L);
    PrintList(&L);

    system("pause");
    return 0;
}