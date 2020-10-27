// 链表方式 实现队列
// 带有 头节点和尾节点的单链表

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

struct LinkList
{
    int data;
    struct LinkList *next;
};

struct queue
{
    struct LinkList *head;
    struct LinkList *tail;
    int length;
};

void initqueue(struct queue *q);          //  初始化队列
bool push(struct queue *q, int data);     // 入队
bool pop(struct queue *q, int *data);     // 出队
bool isempty(struct queue *q);            // 判空
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
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
}

bool push(struct queue *q, int data)
{
    if (isempty(q))
    {
        struct LinkList *newnode;
        newnode = (struct LinkList *)malloc(sizeof(struct LinkList));
        newnode->data = data;
        newnode->next = NULL;
        q->head = newnode;
        q->tail = newnode;
        q->length++;
    }
    else
    {
        struct LinkList *newnode;
        newnode = (struct LinkList *)malloc(sizeof(struct LinkList));
        newnode->data = data;
        newnode->next = NULL;
        q->tail->next = newnode;
        q->tail = newnode;
        q->length++;
    }
    return true;
}

bool pop(struct queue *q, int *data)
{
    if (!isempty(q))
    {
        *data = q->head->data;
        struct LinkList *temp;
        temp = q->head;
        q->head = q->head->next;
        q->length--;
        free(temp);
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty(struct queue *q)
{
    return q->length == 0;
}

bool gethead(struct queue *q, int *data)
{
    if (isempty(q))
    {
        return false;
    }
    *data = q->head->data;
    return true;
}

int getlength(struct queue *q)
{
    return q->length;
}