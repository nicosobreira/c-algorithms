#include "algo/sort.h"

#include <stdlib.h>
#include <string.h>

#include "compare/core.h"

#include "ds/list.h"

void insertion_sort(List *list)
{
    for (size_t j = 1; j < List_Size(list); ++j)
    {
        void *key = List_GetCopy(list, j);

        size_t i = j;
        while (i > 0 && List_Compare_Less(list, key, List_Get(list, i - 1)))
        {
            List_Set(list, i, List_Get(list, i - 1));

            i -= 1;
        }

        List_Set(list, i, key);

        free(key);
    }
}
