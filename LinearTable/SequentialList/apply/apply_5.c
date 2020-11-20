// 假设长为n的顺序表A[0,n-1]中每个数据元素为一整数
// 请写出按照下列思路将表中元素按值从小到大排序的算法
//      第一趟排序将最小值放入A[0], 最大值放入A[n-1]
//      第二趟排序将次小值放入A[1], 次大值放入A[n-2]    ...依此下去

#include <stdio.h>
#include <windows.h>

void mysort(int A[], int n)
{
    int left = 0, right = n - 1;
    int min = 0, max = 0;
    int i = 0;
    int temp;
    while (left < right)
    {
        for (i = left; i < right + 1; i++)
        {
            if (A[i] > A[max])
            {
                max = i;
            }
            if (A[i] < A[min])
            {
                min = i;
            }
        }
        if (right - 1 == left)
        {
            temp = A[min];
            A[min] = A[max];
            A[max] = temp;
        }
        else
        {
            temp = A[min];
            A[min] = A[left];
            A[left] = temp;

            temp = A[max];
            A[max] = A[right];
            A[right] = temp;
        }

        left++;
        right--;
        min = left;
        max = left;
    }
}

int main(void)
{
    int A[10] = {0, 3, 5, 2, 1, 8, 8, 4, 9, 6};
    mysort(A, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}