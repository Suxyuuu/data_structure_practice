// 用非递归算法 采用折半查找的方式 查找一个 严格 递增的顺序表中 不大于item的最大元素的位置
// 如果有 返回位置 如果无 返回0

#include <stdio.h>
#include <windows.h>

int getvalue(int A[], int n, int item)
{
    if (A[0] > item)
    {
        return 0;
    }

    int left = 0, right = n - 1, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] < item)
        {
            left = mid + 1;
        }
        if (A[mid] > item)
        {
            right = mid - 1;
        }
        if (A[mid] == item)
        {
            return mid;
        }
    }

    if (left == right)
    {
        if (A[left] <= item)
        {
            return left;
        }
        else
        {
            return left - 1;
        }
    }
    else
    {
        return right;
    }
}

int main(void)
{
    int A[5] = {1, 2, 3, 4, 6};
    printf("%d\n", getvalue(A, 5, 5)); // 3
    printf("%d\n", getvalue(A, 5, 6)); // 4
    printf("%d\n", getvalue(A, 5, 0)); // 0
    printf("%d\n", getvalue(A, 5, 1)); // 0
    printf("%d\n", getvalue(A, 5, 3)); // 2
    int B[6] = {2, 5, 7, 9, 10, 14};
    printf("%d\n", getvalue(B, 6, 5));  // 1
    printf("%d\n", getvalue(B, 6, 4));  // 0
    printf("%d\n", getvalue(B, 6, 11)); // 4
    printf("%d\n", getvalue(B, 6, 14)); // 5
    printf("%d\n", getvalue(B, 6, 15)); // 5

    system("pause");
    return 0;
}