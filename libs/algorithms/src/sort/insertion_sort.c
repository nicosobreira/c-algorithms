#include "algo/sort.h"

#include <stdlib.h>
#include <string.h>

#include "ds/list.h"

/**
Loop invariant.

    Initialization:
At the start j = 1, so the subarray list[0..j - 1] has one element (list[0]). And so, it's sorted.
The subarray list[j..n] isn't sorted yet.

    Maintain:
Let i = j and key = list[j]. The subarray list[0..i - 1] is sorted prior to the while loop.
If i > 0 and key < list[i - 1], then the key is the smallest value comparing to list[i..j], but we don't know if this is
true for the subarray list[0..i - 1], so we decrement i by 1.
If i == 0 or key > list[i], then key is the smallest element in the subarray list[i..j].

    Finalization
When j = n - 1, the subarray list[0..n - 1] is sorted.
*/
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
