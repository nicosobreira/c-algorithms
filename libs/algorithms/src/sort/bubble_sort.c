#include "algo/sort.h"

#include "ds/list/core.h"

void bubble_sort(List *list)
{
    const size_t last_index = List_Size(list) - 1;

    for (size_t i = 0; i < last_index; ++i)
    {
        for (size_t j = last_index; j >= i + 1; --j)
        {
            void *current = List_Get(list, j);
            void *previous = List_Get(list, j - 1);

            if (List_Compare_Less(list, current, previous))
            {
                List_Swap(list, j, j - 1);
            }
        }
    }
}
