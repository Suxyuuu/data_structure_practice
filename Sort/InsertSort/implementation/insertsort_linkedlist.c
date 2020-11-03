// 直接插入排序 基于链表

#include <stdio.h>
#include <windows.h>
#define N 100

// 链表节点
typedef struct Node
{
    int data;
    Node *next;
} Node, *List;

void getlist(List *L, int *len); // 获取数据列表
void insertsort(List *L);        // 插入排序
void printlist(List L);          // 打印列表

int main(void)
{
    List L;
    int len;
    getlist(&L, &len);
    printlist(L);
    insertsort(&L);
    printlist(L);
    system("pause");
    return 0;
}

// 获取数据存入链表
// 输入方式: 数字间用空格隔开  456 2 9 1999 583
void getlist(List *L, int *len)
{
    *L = (List)malloc(sizeof(Node));
    List p = *L;
    p->next = NULL;
    List temp;
    char ch[N];
    gets(ch);

    int slen = strlen(ch);
    int sum = 0;
    int j = 0;
    for (int i = 0; i < slen; i++)
    {
        if (ch[i] == ' ')
        {
            if (j == 0)
            {
                p->data = sum;
            }
            else
            {
                temp = (List)malloc(sizeof(Node));
                temp->data = sum;
                temp->next = NULL;
                p->next = temp;
                p = p->next;
            }
            sum = 0;
            j++;
        }
        else
        {
            sum = sum * 10 + ch[i] - '0';
        }
    }
    temp = (List)malloc(sizeof(Node));
    temp->data = sum;
    temp->next = NULL;
    p->next = temp;
    p = p->next;
    *len = j + 1;
}

/* 插入排序过程
 *      将链表划分为两个链表 以排好序的done 和 未排好序的notdone
 *      每次取出notdone中的一个节点 在done中找到恰当的位置插入进去
 * */
void insertsort(List *L)
{
    List done = *L, notdone = (*L)->next; // done 已排好序链表 notdone 未排好序链表
    done->next = NULL;                    // 两个链表断开
    List tempnode = done;                 // 游走指针
    List tempnodepre = NULL;              // 记录游走指针的前驱节点 方便插入

    while (notdone) // 外循环 每个notdone的节点都要循环一遍
    {
        int flag = 0;             // 若插入了一次节点 则置为1 从而跳出内循环
        while (tempnode && !flag) // 内循环 用来寻找插入位置
        {
            if (tempnode->data >= notdone->data) // 当未排序好的节点的值小于等于已排好的节点值时 就可以插入了(插入到该节点的前面)
            {
                List m = notdone;
                notdone = notdone->next; // 更新notdone 减少一个节点
                m->next = tempnode;      // 插入到tempnode的前面
                if (tempnodepre)         // 判断tempnode是否是第一个节点
                {
                    tempnodepre->next = m;
                    tempnode = done;
                    tempnodepre = NULL; // 无论temonode是否为第一个节点 都需要将其恢复至头节点 方便下一轮外循环 同时恢复其前驱节点
                    flag = 1;
                }
                else
                {
                    tempnode = m;
                    done = tempnode; // 若tempnode为第一个节点 done需要改变
                    tempnodepre = NULL;
                    flag = 1;
                }
            }
            else
            {
                tempnodepre = tempnode; // 大于时则向后继续寻找合适位置
                tempnode = tempnode->next;
            }
        }
        flag = 0;
    }
    *L = done;
}

// 打印链表内容
void printlist(List L)
{
    List p = L;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}