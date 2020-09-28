// 找到数组中的主元素 即该元素出现次数大于总数的一半 否则无主元素 返回-1
// 思路:
//      依次扫描数组元素 第一个整数保存到temp中, 并count++
//      若下一个元素等于temp, 则count++ 否则count--
//      当count为0时, 将下一个整数保存到temp中 直至扫描完整个数组
//      重新扫描数组, 统计temp的值出现的次数 若大于一半 则返回temp 否则 返回 -1

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
int getnumber(Sqlist *L, int length);
// 其他必要的函数
void InitList(Sqlist *L);                 // 初始化函数
bool ListInsert(Sqlist *L, int i, int e); // 在第i个位置插入值为e的元素

// 测试主函数
int main(void)
{
    Sqlist A;
    InitList(&A);
    ListInsert(&A, 1, 0);
    ListInsert(&A, 2, 5);
    ListInsert(&A, 3, 5);
    ListInsert(&A, 4, 3);
    ListInsert(&A, 5, 5);
    ListInsert(&A, 6, 1);
    ListInsert(&A, 7, 5);
    ListInsert(&A, 8, 7);

    printf("%d\n", getnumber(&A, A.length));

    getchar();
    return 0;
}

// 本题所需函数的实现
int getnumber(Sqlist *L, int length)
{
    int temp = 0, count = 0;
    for (int i = 0; i < length; i++)
    {
        if (count == 0)
        {
            temp = L->data[i];
            count++;
        }
        else
        {
            if (temp == L->data[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    count = 0;
    for (int i = 0; i < length; i++)
    {
        if (L->data[i] == temp)
        {
            count++;
        }
    }
    if (count > length / 2)
    {
        return temp;
    }
    else
    {
        return -1;
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
