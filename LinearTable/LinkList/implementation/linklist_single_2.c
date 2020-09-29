// 单链表的实现(不带头节点)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkList
{
    ElemType e;
    struct LinkList *next;
} LinkList;

LinkList *CreateList(void);                              // 初始化链表
int Length(LinkList *L);                                 // 返回表长
LinkList *LocateElem(LinkList *L, ElemType e);           // 按值查找 返回指针指向元素所在节点 若无则返回null[注意空指针检验]
bool GetElem(LinkList *L, int i, ElemType *e);           // 按位查找 返回元素值e
void ListInsert_head(LinkList **L, ElemType e);          // 插入值为e的元素 头插法
void ListInsert_tail(LinkList **L, ElemType e);          // 插入值为e的元素 尾插法
void ListInsert_mid(LinkList *L, ElemType e, int index); // 插入值为e的元素 插入到第index位后面
bool ListDelete(LinkList **L, int i, ElemType *e);       // 删除第i个位置的元素并将值通过e返回
void PrintList(const LinkList *L);                       // 顺序打印单链表所有元素值
bool Empty(const LinkList *L);                           // 判断表是否为空
void DestroyList(LinkList *L);                           // 销毁表

// 主函数测试
int main(void)
{

    // LinkList L = CreateList();
    LinkList *L;
    L = CreateList();
    if (Empty(L))
    {
        printf("List is empty!\n");
    }
    else
    {
        printf("List is not empty\n");
    }
    ListInsert_head(&L, 1);
    ListInsert_head(&L, 2);
    ListInsert_head(&L, 3);
    ListInsert_head(&L, 4);
    ListInsert_head(&L, 5);
    ListInsert_tail(&L, 7);
    ListInsert_tail(&L, 8);
    ListInsert_tail(&L, 9);
    PrintList(L);
    ElemType e;
    GetElem(L, 2, &e);
    printf("7 is in the pointer of %p, the number is %d\n", LocateElem(L, 7), LocateElem(L, 7)->e);
    printf("No.2 elem is %d\n", e);
    if (Empty(L))
    {
        printf("List is empty!\n");
    }
    else
    {
        printf("List is not empty\n");
    }
    ListInsert_mid(L, 100, 2);
    PrintList(L);
    printf("Length: %d\n", Length(L));
    ListDelete(&L, 3, &e);
    printf("Delete %d\n", e);
    PrintList(L);
    ListDelete(&L, 8, &e);
    printf("Delete %d\n", e);
    PrintList(L);
    DestroyList(L);

    getchar();
    return 0;
}

// 功能实现
LinkList *CreateList(void)
{
    LinkList *L = NULL;
    return L;
}

int Length(LinkList *L)
{
    int count = 0;
    LinkList *p = L;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

LinkList *LocateElem(LinkList *L, ElemType e)
{
    LinkList *p = L;
    while (p != NULL)
    {
        if (p->e == e)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

bool GetElem(LinkList *L, int i, ElemType *e)
{
    if (i > Length(L))
    {
        return false;
    }
    LinkList *p = L;
    int count = i;
    for (int i = 1; i < count; i++)
    {
        p = p->next;
    }
    *e = p->e;
    return true;
}

void ListInsert_head(LinkList **L, ElemType e) // 需更改头节点指针的值 因此传入**L
{
    if (Length(*L) == 0)
    {
        LinkList *p = (LinkList *)malloc(sizeof(LinkList));
        p->e = e;
        p->next = NULL;
        *L = p;
    }
    else
    {
        LinkList *p = (LinkList *)malloc(sizeof(LinkList));
        p->e = e;
        p->next = *L;
        *L = p;
    }
}

void ListInsert_tail(LinkList **L, ElemType e) // 可能需要改变头节点指针的值 因此传入**L
{
    if (Length(*L) == 0)
    {
        LinkList *p = (LinkList *)malloc(sizeof(LinkList));
        p->e = e;
        p->next = NULL;
        *L = p;
    }
    else
    {
        LinkList *p = *L, *m;
        m = (LinkList *)malloc(sizeof(LinkList));
        m->e = e;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = m;
        m->next = NULL;
    }
}

void ListInsert_mid(LinkList *L, ElemType e, int index)
{
    if (index <= Length(L))
    {
        LinkList *p = L, *m;
        m = (LinkList *)malloc(sizeof(LinkList));
        m->e = e;

        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        m->next = p->next;
        p->next = m;
    }
    else
    {
        fprintf(stderr, "INSERT ERROR: index out of range!\n");
    }
}

bool ListDelete(LinkList **L, int i, ElemType *e) // 可能需要改变头节点指针的值 因此传入**L
{
    if (i > Length(*L))
    {
        return false;
    }
    if (i == 1)
    {
        LinkList *p = *L;
        *e = p->e;
        *L = (*L)->next;
        free(p);
    }
    else
    {
        LinkList *p = *L, *q;
        for (int j = 1; j < i - 1; j++)
        {
            p = p->next;
        }
        q = p->next;
        *e = q->e;
        p->next = q->next;
        free(q);
    }
    return true;
}

void PrintList(const LinkList *L)
{
    if (Empty(L))
    {
        printf("This list is empty!\n");
    }
    else
    {
        const LinkList *p = L;
        while (p != NULL)
        {
            printf("%d ", p->e);
            p = p->next;
        }
        printf("\n");
    }
}

bool Empty(const LinkList *L)
{
    return L == NULL;
}

void DestroyList(LinkList *L)
{
    int len = Length(L);
    ElemType e;
    printf("Destroy list begins...");
    for (int i = 0; i < len; i++)
    {
        ListDelete(&L, 1, &e);
        printf("\nDelete %d", e);
    }
    free(L);
    printf("\nList has been destroyed!\n");
}