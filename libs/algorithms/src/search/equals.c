#include "algo/search.h"

#define EQUALS(a, b, type)        \
    type va = *(const type *)(a); \
    type vb = *(const type *)(b); \
                                  \
    return va == vb;

bool int_equals(const void *a, const void *b)
{
    EQUALS(a, b, int);
}

bool float_equals(const void *a, const void *b)
{
    EQUALS(a, b, float);
}

bool double_equals(const void *a, const void *b)
{
    EQUALS(a, b, double);
}
