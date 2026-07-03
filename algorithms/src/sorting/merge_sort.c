#include "algo/sorting.h"

#include "ds/list.h"

static void fill_up(List *list, List *side, size_t list_start, size_t side_start)
{
    size_t k = list_start + 1;
    for (size_t i = side_start; i < List_Size(side); ++i)
    {
        List_Set(list, k, List_Get(side, i));
        k += 1;
    }
}

static void merge(List *list, size_t p, size_t q, size_t r, CompareFunc cmp)
{
    // The parameters `q` and `r` are the sizes of their subarrays.
    // Because `List_NewSlice` receives **indexes** we have to tranform them

    List left = List_NewSlice(list, p, q - 1);
    List right = List_NewSlice(list, q, r - 1);

    // It isnt't possible to use sentinels (-inf or +inf) because the `cmp`
    // function can compare values in diferent ways (less equal or greater equal)

    size_t i = 0;
    size_t j = 0;
    for (size_t k = p; k < r; ++k)
    {
        if (cmp(List_Get(&left, i), List_Get(&right, j)))
        {
            List_Set(list, k, List_Get(&left, i));

            i += 1;

            if (i >= List_Size(&left))
            {
                fill_up(list, &right, k, j);
                break;
            }
        }
        else
        {
            List_Set(list, k, List_Get(&right, j));

            j += 1;

            if (j >= List_Size(&right))
            {
                fill_up(list, &left, k, i);
                break;
            }
        }
    }
}

static void sort(List *list, size_t p, size_t r, CompareFunc cmp)
{
    const size_t size = r - p;

    // Base Case
    if (size <= 1)
    {
        return;
    }

    // Divide
    const size_t mid = p + (size / 2);

    sort(list, p, mid, cmp); // Left

    sort(list, mid, r, cmp); // Right

    // Conquer
    merge(list, p, mid, r, cmp);
}

void merge_sort(List *list, CompareFunc cmp)
{
    sort(list, 0, List_Size(list), cmp);
}
