// 构造一个栈

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define N 5

struct stack
{
    int data[N];
    int top;
};

void initstack(struct stack **s);
bool isempty(struct stack *s);
bool isfull(struct stack *s);
bool push(struct stack *s, int data);
bool pop(struct stack *s, int *data);
bool gettop(struct stack *s, int *data);
void destroystack(struct stack *s);

int main(void)
{
    struct stack *s;
    int i;
    initstack(&s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    pop(s, &i);
    // pop 3
    printf("%d\n", i);
    pop(s, &i);
    // pop 2
    printf("%d\n", i);
    push(s, 4);
    printf("===============\n");
    // it should be 1 4 in stack
    while (!isempty(s))
    {
        pop(s, &i);
        printf("%d\n", i);
    }
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10); // stack overflow
    push(s, 11);
    printf("===============\n");
    // if should be 5 6 7 8 9 in stack
    while (!isempty(s))
    {
        pop(s, &i);
        printf("%d\n", i);
    }

    system("pause");
    return 0;
}

void initstack(struct stack **s)
{
    *s = (struct stack *)malloc(sizeof(struct stack));
    (*s)->top = -1;
}

bool isempty(struct stack *s)
{
    return s->top == -1;
}

bool isfull(struct stack *s)
{
    return s->top == N - 1;
}

bool push(struct stack *s, int data)
{
    if (!isfull(s))
    {
        s->data[++s->top] = data;
        return true;
    }
    else
    {
        return false;
    }
}

bool pop(struct stack *s, int *data)
{
    if (!isempty(s))
    {
        *data = s->data[s->top];
        s->top--;
        return true;
    }
    else
    {
        return false;
    }
}

bool gettop(struct stack *s, int *data)
{
    if (isempty(s))
    {
        return false;
    }
    *data = s->data[s->top];
    return true;
}

void destroystack(struct stack *s)
{
    free(s);
}