// 选择排序 基于数组

#include <stdio.h>
#include <windows.h>

#define N 100

void getarray(int a[], int *len);  // 获取数据
void selectsort(int a[], int len); // 选择排序
void printarray(int a[], int len); // 打印数组

int main(void)
{
    int a[N];
    int len;
    getarray(a, &len);
    printarray(a, len);
    selectsort(a, len);
    printarray(a, len);

    system("pause");
    return 0;
}

// 获取数据
// 输入方式: 数字间用空格隔开  456 2 9 1999 583
void getarray(int a[], int *len)
{
    char ch[N];
    gets(ch);

    int slen = strlen(ch);
    int sum = 0; // 记录每个数据的值
    int j = 0;
    for (int i = 0; i < slen; i++)
    {
        if (ch[i] == ' ')
        {
            a[j] = sum;
            sum = 0;
            j++;
        }
        else
        {
            sum = sum * 10 + ch[i] - '0';
        }
    }
    a[j] = sum;
    *len = j + 1;
}

// 选择排序
void selectsort(int a[], int len)
{
    int target; // 用来记录每轮的最小值的位置
    int temp;
    for (int i = 0; i < len; i++)
    {
        target = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[target] > a[j])
            {
                target = j;
            }
        }
        temp = a[target];
        a[target] = a[i];
        a[i] = temp; // 将最小的与头元素交换位置
    }
}

// 打印数组
// 打印样式: 数字间空格隔开末尾带有换行符
void printarray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}