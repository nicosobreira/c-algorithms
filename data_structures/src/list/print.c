#include "ds/list.h"

#include <stdio.h>

#define LIST_PRINT(list, type, fmt)                  \
    if (List_IsEmpty(list))                          \
    {                                                \
        return;                                      \
    }                                                \
                                                     \
    printf(fmt, *(type *)List_Get(list, 0));         \
    for (size_t i = 1; i < List_Size(list); ++i)     \
    {                                                \
        printf(" " fmt, *(type *)List_Get(list, i)); \
    }                                                \
                                                     \
    printf("\n");

void List_Print_int(List *self)
{
    LIST_PRINT(self, int, "%d")
}

void List_Print_float(List *self)
{
    LIST_PRINT(self, float, "%g")
}

void List_Print_double(List *self)
{
    LIST_PRINT(self, double, "%g")
}
