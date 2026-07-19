#include "algo/search.h"

#include <stdlib.h>

#include "algo/sort.h"
#include "ds/list/core.h"

/** Why this algorithm takes O(n lg n) on worst case?
Sorting the array with merge sort takes O(n lg n) and finding a valid pair takes O(n).
 */
bool has_two_sum(const List *list, const void *sum, void *(sum_func)(const void *, const void *))
{
    if (List_Size(list) == 0)
    {
        return false;
    }

    size_t start = 0;
    size_t end = List_Size(list) - 1;

    List copy = List_LoadSlice(list, start, end);

    merge_sort(&copy);

    while (start < end)
    {
        void *current_sum = sum_func(List_Get(&copy, start), List_Get(&copy, end));

        // TODO: ver se colocar o `List_Compare_Equals` primeiro funciona melhor
        // para valores `double`, devido a imprecisão.

        if (List_Compare_Greater(&copy, current_sum, sum))
        {
            start += 1;
        }
        else if (List_Compare_Less(&copy, current_sum, sum))
        {
            end -= 1;
        }
        else
        {
            free(current_sum);

            return true;
        }

        free(current_sum);
    }

    return false;
}
