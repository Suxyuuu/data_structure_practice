// 顺序表的实现
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType; // 根据所需改变elemtype
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Sqlist; // 顺序表结构定义

void InitList(Sqlist *L);                          // 初始化函数
int Length(const Sqlist *L);                       // 返回表长
int LocateElem(const Sqlist *L, ElemType e);       // 按值查找 返回元素位序(1-n) 若无则返回0
bool GetElem(const Sqlist *L, int i, ElemType *e); // 按位查找 返回元素值e
bool ListInsert(Sqlist *L, int i, ElemType e);     // 在第i个位置插入值为e的元素
bool ListDelete(Sqlist *L, int i, ElemType *e);    // 删除第i个位置的元素并将值通过e返回
void PrintList(const Sqlist *L);                   // 顺序打印顺序表所有元素值
bool Empty(const Sqlist *L);                       // 判断表是否为空
void DestroyList(Sqlist *L);                       // 销毁表

int main(void)
{
    // 测试
    Sqlist L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    printf("input 1 2 3 4\n");
    PrintList(&L);
    printf("length: %d\n", Length(&L));
    printf("2 in the place:%d\n", LocateElem(&L, 2));
    int e;
    GetElem(&L, 3, &e);
    printf("no.3 num is :%d\n", e);
    ListDelete(&L, 4, &e);
    printf("deleted no.4 is %d\n", e);
    PrintList(&L);
    if (Empty(&L))
    {
        printf("this list is empty\n");
    }
    else
    {
        printf("this list is not empty\n");
    }
    DestroyList(&L);
    getchar();

    return 0;
}

// 功能实现
void InitList(Sqlist *L)
{
    L->length = 0;
}

int Length(const Sqlist *L)
{
    return L->length;
}

int LocateElem(const Sqlist *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0; // 表示未找到
}

bool GetElem(const Sqlist *L, int i, ElemType *e)
{
    if (i > L->length || i <= 0) // i值不合法
    {
        return false;
    }
    else
    {
        *e = L->data[i - 1];
        return true;
    }
}

bool ListInsert(Sqlist *L, int i, ElemType e)
{
    if (i > L->length + 1 || i <= 0 || L->length >= MAXSIZE) // i值不合法 或 表满
    {
        return false;
    }
    for (int j = L->length; j >= i; j--) // 第i个元素及之后的元素后移
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(Sqlist *L, int i, ElemType *e)
{
    if (i <= 0 || i > L->length) // i值不合法
    {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

void PrintList(const Sqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf(",%d" + !i, L->data[i]); // 默认元素为整型 且 该方式可以巧妙地格式化输出
    }
    printf("\n");
}

bool Empty(const Sqlist *L)
{
    return L->length == 0;
}

void DestroyList(Sqlist *L)
{
    free(L);
}