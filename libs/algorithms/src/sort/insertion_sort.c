#include "algo/sort.h"

#include <stdlib.h>
#include <string.h>

#include "ds/list/core.h"

/** Insertion Sort Loop Invariant
For Loop:

    Initialization
At the start j = 1, so the subarray list[0..j - 1] has one element, namely list[0]. Therefore, list[0..j - 1] is sorted.

    Maintain
Let key = list[j] and i = j. We compare the key with the sorted subarray list[0..i - 1] until either (1) i == 0 or (2)
key > list[i - 1], while moving the list[i..j - 1] to the right, making key the smallest element of the subarray
list[i..j]. Then we make list[i] = key. In case none of those conditions are true, i is decremented by 1.

* As a result, the subarray list[0..j] is sorted.

    Finalization

When j = n - 1, the subarray list[0..n - 1], that is the entire array list, is sorted.
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
