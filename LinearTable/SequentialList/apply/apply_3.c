// 求两个【等长】有序整数序列的中位数
// 如: A[11 13 15 17 19] B[2 4 6 8 20] ==> 中位数: 11
// 思路:
// 1. 分别求两个序列的中位数a和b
// 2. 若a=b, 即为中位数
//    若a<b, 舍弃A中较小的一半和B中较大的一半(保持舍弃长度相同)
//    若a>b, 舍弃A中较大的一半和B中较小的一半(保持舍弃长度相同)
// 3. 重复步骤1和2

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
int findmiddle(Sqlist *A, Sqlist *B, int n);
// 其他必要的函数
void InitList(Sqlist *L);                 // 初始化函数
bool ListInsert(Sqlist *L, int i, int e); // 在第i个位置插入值为e的元素

// 测试主函数
int main(void)
{
    Sqlist A, B;
    InitList(&A);
    InitList(&B);
    ListInsert(&A, 1, 11);
    ListInsert(&A, 2, 13);
    ListInsert(&A, 3, 15);
    ListInsert(&A, 4, 17);
    ListInsert(&A, 5, 19);
    ListInsert(&B, 1, 2);
    ListInsert(&B, 2, 4);
    ListInsert(&B, 3, 6);
    ListInsert(&B, 4, 8);
    ListInsert(&B, 5, 20);

    printf("%d\n", findmiddle(&A, &B, 5));

    getchar();
    return 0;
}

// 本题所需函数的实现
int findmiddle(Sqlist *A, Sqlist *B, int n)
{
    int a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1, am, bm; // 分别表示A和B的首位末位和中位
    while (a1 != a2 || b1 != b2)
    {
        am = (a1 + a2) / 2;
        bm = (b1 + b2) / 2;
        if (A->data[am] == B->data[bm]) // 满足条件a=b
        {
            return A->data[am];
        }
        if (A->data[am] < B->data[bm]) // 满足条件a<b
        {
            if ((a1 + a2) % 2 == 0) // 奇数个
            {
                a1 = am; // 丢弃前一半
                b2 = bm; // 丢弃后一半
            }
            else // 偶数个
            {
                a1 = am + 1; // 保持舍弃长度相同
                b2 = bm;
            }
        }
        else // 满足条件a>b
        {
            if ((a1 + a2) % 2 == 0) // 奇数个
            {
                a2 = am; // 丢弃后一半
                b1 = bm; // 丢弃前一半
            }
            else // 偶数个
            {
                a2 = am; // 保持舍弃长度相同
                b1 = bm + 1;
            }
        }
    }
    return A->data[a1] < B->data[b1] ? A->data[a1] : B->data[b1];
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
