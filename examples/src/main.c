#include <stdio.h>

#include "ds/list.h"

#define SIZE 3

int main(void)
{
    int array[SIZE] = {9, 2, 1};

    List list = List_Load(array, SIZE, sizeof(array[0]));
    List *p_l = &list;

    List_Pop(p_l);
    List_Pop(p_l);
    List_Pop(p_l);

    List_Push(p_l, &(int){42});
    List_Push(p_l, &(int){3});

    List_Swap(p_l, 0, 1);
    for (size_t i = 0; i < List_Size(p_l); ++i)
    {
        int *p_num = (int *)List_Get(p_l, i);
        printf("%d ", *p_num);
    }
    printf("\n");

    List_Free(p_l);

    return 0;
}
