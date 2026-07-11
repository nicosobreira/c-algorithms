#include "algo/search.h"

#include "result.h"

SearchResult binary_search(const List *list, const void *value, EqualsFunc equals)
{
    (void)list;
    (void)value;
    return SearchResult_NotFound();
}
