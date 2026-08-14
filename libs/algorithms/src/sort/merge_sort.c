#include "algo/sort.h"

#include <stddef.h>

#include "ds/list/core.h"
#include "ds/list/view.h"

// TODO: Implement an iterative Merge Sort

static inline void fill_up(ListView *list, List *side, size_t list_start, size_t side_start)
{
    size_t k = list_start + 1;
    for (size_t i = side_start; i < List_Size(side); ++i)
    {
        ListView_Set(list, k, List_Get(side, i));
        k += 1;
    }
}

static inline void merge(ListView *list, size_t p, size_t q, size_t r)
{
    // The parameters `q` and `r` are the sizes of their subarrays.
    // Because `List_LoadSlice` receives **indexes** we have to tranform them

    List left = ListView_LoadSlice(list, p, q - 1);
    List right = ListView_LoadSlice(list, q, r - 1);

    // It isn't possible to use sentinels (-inf or +inf) because the `cmp`
    // function can compare values in many ways (less equal or greater equal)

    size_t i = 0;
    size_t j = 0;
    for (size_t k = p; k < r; ++k)
    {
        if (ListView_Compare_Less(list, List_Get(&left, i), List_Get(&right, j)))
        {
            ListView_Set(list, k, List_Get(&left, i));

            i += 1;

            if (i >= List_Size(&left))
            {
                fill_up(list, &right, k, j);
                break;
            }
        }
        else
        {
            ListView_Set(list, k, List_Get(&right, j));

            j += 1;

            if (j >= List_Size(&right))
            {
                fill_up(list, &left, k, i);
                break;
            }
        }
    }
}

static inline void sort(ListView *list, size_t p, size_t r)
{
    const size_t size = r - p;

    // Base Case
    if (size <= 1)
    {
        return;
    }

    // Divide
    const size_t mid = p + (size / 2);

    sort(list, p, mid); // Left

    sort(list, mid, r); // Right

    // Conquer
    merge(list, p, mid, r);
}

void merge_sort(ListView *list)
{
    sort(list, 0, ListView_Size(list));
}
