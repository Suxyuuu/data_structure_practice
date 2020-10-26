// 普通队列的实现(顺序实现)

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define MaxSize 5

struct queue
{
    int data[MaxSize];
    int front, rear; // 队头 队尾
};

void initqueue(struct queue *q);          //  初始化队列
void push(struct queue *q, int data);     // 入队
void pop(struct queue *q, int *data);     // 出队
BOOL isempty(struct queue *q);            // 判空
void gethead(struct queue *q, int *data); // 获取队首元素

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
    while (!isempty(q))
    {
        int i;
        pop(q, &i);
        printf("%d->", i);
        gethead(q, &i);
        printf("%d\n", i);
    }
    system("pause");
    return 0;
}

void initqueue(struct queue *q)
{
    q->front = 0;
    q->rear = 0;
}

void push(struct queue *q, int data)
{
    if (q->rear + 1 <= MaxSize)
    {
        q->data[q->rear] = data;
        q->rear++;
    }
}

void pop(struct queue *q, int *data)
{
    if (!isempty(q))
    {
        *data = q->data[q->front];
        q->front++;
    }
}

BOOL isempty(struct queue *q)
{
    return q->front == q->rear;
}

void gethead(struct queue *q, int *data)
{
    if (!isempty(q))
    {
        *data = q->data[q->front];
    }
}