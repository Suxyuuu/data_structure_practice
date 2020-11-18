
#include <windows.h>
#include "BiTree.h"

int main(void)
{
    BiTree root;
    BiTree *T = &root;
    create(&T);
    printf("Create Finish!\n");
    pre_order_recursion(T);
    printf("--> Pre_order(with recursion)\n");
    pre_order_notrecursion(T);
    printf("--> Pre_order(without recursion)\n");
    mid_order_recursion(T);
    printf("--> Mid_order(with recursion)\n");
    mid_order_notrecursion(T);
    printf("--> Mid_order(without recursion)\n");
    rear_order_recursion(T);
    printf("--> Rear_order(with recursion)\n");
    rear_order_notrecursion_1(T);
    printf("--> Rear_order_1(without recursion)\n");
    rear_order_notrecursion_2(T);
    printf("--> Rear_order_2(without recursion)\n");
    layer_order(T);
    printf("--> Layer_order\n");

    //printf("\n");
    system("pause");
    return 0;
}
