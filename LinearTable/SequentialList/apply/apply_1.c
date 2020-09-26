// 从有序顺序表中删除其值重复的元素, 使表中所有元素均不同
// 元素类型默认为int
// 时间复杂度O(n)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

// 必要的函数
void InitList(Sqlist *L);                 // 初始化函数
bool ListInsert(Sqlist *L, int i, int e); // 在第i个位置插入值为e的元素
void PrintList(const Sqlist *L);          // 顺序打印顺序表所有元素值

// 本题所需函数
bool DeleteSame(Sqlist *L);

// 主函数
int main(void)
{
    Sqlist L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 2);
    ListInsert(&L, 4, 3);
    ListInsert(&L, 5, 3);
    ListInsert(&L, 6, 3);
    ListInsert(&L, 7, 4);
    printf("Before delete:\n");
    PrintList(&L);
    DeleteSame(&L);
    printf("After delete:\n");
    PrintList(&L);
    getchar();
    return 0;
}

// 本题所需函数实现
bool DeleteSame(Sqlist *L)
{
    if (L->length == 0)
    {
        return false; // 表空
    }
    int i, j;
    for (i = 0, j = 1; j < L->length; j++)
    {
        if (L->data[i] != L->data[j])
        {
            L->data[++i] = L->data[j];
        }
    }
    L->length = i + 1;
    return true;
}

// 必要函数实现
void InitList(Sqlist *L)
{
    L->length = 0;
}

int Length(const Sqlist *L)
{
    return L->length;
}

bool ListInsert(Sqlist *L, int i, int e)
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

void PrintList(const Sqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf(",%d" + !i, L->data[i]); // 默认元素为整型 且 该方式可以巧妙地格式化输出
    }
    printf("\n");
}