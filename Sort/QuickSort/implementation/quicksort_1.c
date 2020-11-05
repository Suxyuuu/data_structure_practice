// 快速排序 严蔚敏版 (该版较为常见)

#include <stdio.h>
#include <windows.h>
#define N 100

// 非递归排序所需的栈
typedef struct stack
{
    int data[N];
    int top;
} stack;

void getarray(int a[], int *len);                     // 获取数据
void quicksort_recursion(int a[], int low, int high); // 快速排序 递归
void quicksort_norecursion(int a[], int len);         // 快速排序 非递归
void printarray(int a[], int len);                    // 打印数组

int oneround(int a[], int low, int high); // 工具函数(非递归使用) 快速排序一小轮的过程 返回划分值排序好的位置
void pop(stack *s);                       // 工具函数(非递归使用) 弹出栈
void push(stack *s, int data);            // 工具函数(非递归使用) 压入栈
int s_top(stack *s);                      // 工具函数(非递归使用) 获取栈顶元素值

int main(void)
{
    int a[N];
    int len;
    getarray(a, &len);
    printarray(a, len);
    quicksort_norecursion(a, len);
    printarray(a, len);
    quicksort_recursion(a, 0, len - 1);
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

// 快速排序 递归
void quicksort_recursion(int a[], int low, int high)
{
    int pivot = a[low];
    int first = low;
    int last = high;
    if (first >= last)
    {
        return;
    }
    while (first < last)
    {
        while (first < last && a[last] >= pivot)
        {
            last--;
        }
        a[first] = a[last];
        while (first < last && a[first] <= pivot)
        {
            first++;
        }
        a[last] = a[first];
    }
    a[first] = pivot;
    quicksort_recursion(a, low, first - 1);
    quicksort_recursion(a, first + 1, high);
}

// 快速排序 非递归
void quicksort_norecursion(int a[], int len)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1; // 栈初始化
    int first = 0, last = len - 1;
    int mid;
    push(s, first);
    push(s, last);
    while (s->top != -1)
    {
        last = s_top(s);
        pop(s);
        first = s_top(s);
        pop(s);
        mid = oneround(a, first, last);
        if (mid - 1 > first)
        {
            push(s, first);
            push(s, mid - 1);
        }
        if (mid + 1 < last)
        {
            push(s, mid + 1);
            push(s, last);
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

// 工具函数(非递归使用) 快速排序一小轮的过程 返回划分值排序好的位置
int oneround(int a[], int low, int high)
{
    int first = low;
    int last = high;
    int pivot = a[low];
    while (first < last)
    {
        while (a[last] >= pivot && first < last)
        {
            last--;
        }
        a[first] = a[last];
        while (a[first] < pivot && first < last)
        {
            first++;
        }
        a[last] = a[first];
    }
    a[first] = pivot;
    return first;
}

// 工具函数(非递归使用) 弹出栈
void pop(stack *s)
{
    s->top--;
}

// 工具函数(非递归使用) 压入栈
void push(stack *s, int data)
{
    s->data[++(s->top)] = data;
}

// 工具函数(非递归使用) 获取栈顶元素的值
int s_top(stack *s)
{
    return s->data[s->top];
}