// 数组A[m+n]中存放两个线性表 前m个元素为一个 后n个为另一个
// 要求: 将两个线性表位置互换
// 思路: 1. 两个线性表原地逆序   2. A数组整体逆序

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int ElemType; // 根据所需改变elemtype
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Sqlist; // 顺序表结构定义

// 本题所需函数
void reverse(Sqlist *S, int a, int b);
// 必要的函数
void InitList(Sqlist *L);                 // 初始化函数
bool ListInsert(Sqlist *L, int i, int e); // 在第i个位置插入值为e的元素
void PrintList(const Sqlist *L);          // 顺序打印顺序表所有元素值

// 测试主函数
int main(void)
{
    Sqlist L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 5);
    ListInsert(&L, 6, 100);
    ListInsert(&L, 7, 101);
    ListInsert(&L, 8, 102);
    ListInsert(&L, 9, 103);

    reverse(&L, 0, 4);
    reverse(&L, 5, 8);
    reverse(&L, 0, 8);

    PrintList(&L);

    getchar();
    return 0;
}

// 本题所需函数的实现
void reverse(Sqlist *S, int a, int b)
{
    int temp = 0;
    for (int i = 0; i < (b - a + 1) / 2; i++)
    {
        temp = S->data[a + i];
        S->data[a + i] = S->data[b - i];
        S->data[b - i] = temp;
    }
}

// 其他必要函数
void InitList(Sqlist *L)
{
    L->length = 0;
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
