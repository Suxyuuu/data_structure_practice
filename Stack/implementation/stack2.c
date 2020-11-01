// 构造一个栈(使用链表实现)
// 链表不带头节点 采用头插法 栈顶在头节点处 栈底在链表末尾

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

typedef struct linknode
{
    int data;
    linknode *next;
} linknode;

typedef struct
{
    linknode *top; // 栈顶指针
    int count;     // 栈内元素总数
} stack;

void initstack(stack **s);
bool isempty(stack *s);
// bool isfull(stack *s);
bool push(stack *s, int data);
bool pop(stack *s, int *data);
bool gettop(stack *s, int *data);
void destroystack(stack *s);

int main(void)
{
    stack *s;
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
    push(s, 10);
    push(s, 11);
    printf("===============\n");
    // if should be 5 6 7 8 9 10 11 in stack
    while (!isempty(s))
    {
        pop(s, &i);
        printf("%d\n", i);
    }

    system("pause");
    return 0;
}

void initstack(stack **s)
{
    //linknode *firstnode;
    *s = (stack *)malloc(sizeof(stack));
    (*s)->top = NULL;
    (*s)->count = 0;
}

bool isempty(stack *s)
{
    return s->count == 0;
}

bool push(stack *s, int data)
{
    linknode *newnode = (linknode *)malloc(sizeof(linknode));
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
    s->count++;
    return true;
}

bool pop(stack *s, int *data)
{
    if (isempty(s))
    {
        return false;
    }
    linknode *del = s->top;
    *data = s->top->data;
    s->top = s->top->next;
    s->count--;
    free(del);
    return true;
}

bool gettop(stack *s, int *data)
{
    if (isempty(s))
    {
        return false;
    }
    *data = s->top->data;
    return true;
}

void destroystack(stack *s)
{
    linknode *del;
    while (s->top)
    {
        del = s->top;
        s->top = s->top->next;
        free(del);
    }
    free(s);
}