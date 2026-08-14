#include "algo/search.h"

#include "result.h"

SearchResult binary_search(const ListView *list, const void *value)
{
    size_t size = ListView_Size(list);

    if (size == 0)
    {
        return SearchResult_NotFound();
    }

    size_t start = 0;
    size_t end = size - 1;

    while (start <= end)
    {
        // TODO: Por que usar essa fórmula ao invés de `(start + end) / 2`?

        // if `start + end` is even, the division is floored
        size_t mid = start + ((end - start) / 2);
        void *mid_value = ListView_Get(list, mid);

        if (ListView_Compare_Equals(list, value, mid_value))
        {
            return SearchResult_Found(mid, mid_value);
        }

        if (ListView_Compare_Less(list, value, mid_value))
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
