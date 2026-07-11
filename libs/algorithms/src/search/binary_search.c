#include "algo/search.h"

#include "result.h"

SearchResult binary_search(const List *list, const void *value)
{
    size_t start = 0;
    size_t end = List_Size(list);

    while (start < end)
    {
        size_t mid = (start + end) / 2;
        void *mid_value = List_Get(list, mid);

        if (List_Compare_Equals(list, value, mid_value))
        {
            return SearchResult_Found(mid, mid_value);
        }

        if (List_Compare_Less(list, value, mid_value))
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }

    return SearchResult_NotFound();
}
