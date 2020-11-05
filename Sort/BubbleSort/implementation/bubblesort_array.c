// 冒泡排序 基于数组

#include <stdio.h>
#include <windows.h>

#define N 100

void getarray(int a[], int *len);  // 获取数据
void bubblesort(int a[], int len); // 冒泡排序
void printarray(int a[], int len); // 打印数组

int main(void)
{
    int a[N];
    int len;
    getarray(a, &len);
    printarray(a, len);
    bubblesort(a, len);
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

// 冒泡排序
void bubblesort(int a[], int len)
{
    int flag = 0; // 记录每轮是否发生了元素交换 若未交换则直接跳出循环
    int temp;
    for (int i = 0; i < len - 1; i++) // 最坏情况需要循环n-1轮
    {
        flag = 0;
        for (int j = 0; j < len - 1 - i; j++) // 每轮会排好最大值 下一次则无需继续比较
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
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