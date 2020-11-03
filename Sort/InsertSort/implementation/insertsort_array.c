// 直接插入排序 基于数组

#include <stdio.h>
#include <windows.h>

#define N 100

void getarray(int a[], int *len);  // 获取数据
void insertsort(int a[], int len); // 插入排序
void printarray(int a[], int len); // 打印数组

int main(void)
{
    int a[N]; // 存放数据
    int len;  // 数据个数
    getarray(a, &len);
    printarray(a, len);
    insertsort(a, len);
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
    int sum = 0;
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

// 插入排序
void insertsort(int a[], int len)
{
    int temp;
    int j;
    for (int i = 1; i < len; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j]; // 元素后移
            j--;
        }
        a[j + 1] = temp;
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