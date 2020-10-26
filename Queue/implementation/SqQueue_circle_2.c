// 循环队列的实现(顺序实现)
// 1. 加设标志位，让删除动作使其为1，插入动作使其为0， 则可识别当前front == rear
// 2. 使用一个计数器记录队列中元素个数（即队列长度）
// 3. 人为浪费一个单元，令队满特征为 front = (rear +1)%N---空闲单元法
// 使用方法2

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define MaxSize 5

struct queue
{
    int data[MaxSize];
    int front, rear; // 队头 队尾
    int length;
};

void initqueue(struct queue *q);          //  初始化队列
bool push(struct queue *q, int data);     // 入队
bool pop(struct queue *q, int *data);     // 出队
bool isempty(struct queue *q);            // 判空
bool isfull(struct queue *q);             // 判满
bool gethead(struct queue *q, int *data); // 获取队首元素
int getlength(struct queue *q);           // 获取队列长度

int main(void)
{
    struct queue m;
    struct queue *q;
    q = &m;
    initqueue(q);
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    int length = getlength(q);
    printf("Length:%d\n", length);
    while (!isempty(q))
    {
        int i;
        pop(q, &i);
        printf("%d->", i);
        gethead(q, &i);
        printf("%d\n", i);
    }
    length = getlength(q);
    printf("Length:%d\n", length);
    printf("===============\n");
    int d;
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    pop(q, &d);
    pop(q, &d);
    pop(q, &d);
    push(q, 6);
    push(q, 7);
    length = getlength(q);
    printf("Length:%d\n", length);
    push(q, 8);
    push(q, 9);
    length = getlength(q);
    printf("Length:%d\n", length);
    system("pause");
    return 0;
}

void initqueue(struct queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->length = 0;
}

bool push(struct queue *q, int data)
{
    if (!isfull(q))
    {
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % MaxSize;
        q->length++;
        return true;
    }
    else
    {
        return false;
    }
}

bool pop(struct queue *q, int *data)
{
    if (!isempty(q))
    {
        *data = q->data[q->front];
        q->front = (q->front + 1) % MaxSize;
        q->length--;
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty(struct queue *q)
{
    if (q->length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isfull(struct queue *q)
{
    if (q->length == MaxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool gethead(struct queue *q, int *data)
{
    if (!isempty(q))
    {
        *data = q->data[q->front];
        return true;
    }
    else
    {
        return false;
    }
}

int getlength(struct queue *q)
{
    return q->length;
}