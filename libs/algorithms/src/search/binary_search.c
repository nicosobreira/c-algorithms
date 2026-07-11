#include "algo/search.h"

#include "result.h"

SearchResult binary_search(const List *list, const void *value)
{
    size_t size = List_Size(list);

    if (size == 0)
    {
        return SearchResult_NotFound();
    }

    size_t start = 0;
    size_t end = size - 1;

    while (start <= end)
    {
        // TODO: Por que usar essa fórmula ao invés de `(start + end) / 2`?

        size_t mid = start + ((end - start) / 2);
        void *mid_value = List_Get(list, mid);

        if (List_Compare_Equals(list, value, mid_value))
        {
            return SearchResult_Found(mid, mid_value);
        }

        if (List_Compare_Less(list, value, mid_value))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return SearchResult_NotFound();
}
