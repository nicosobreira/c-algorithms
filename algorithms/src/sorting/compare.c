#include "algo/sorting.h"

#define COMPARE(a, b, operator, type) \
    type va = *(const type *)a;       \
    type vb = *(const type *)b;       \
                                      \
    if (va operator vb)               \
    {                                 \
        return true;                  \
    }                                 \
                                      \
    return false;

bool int_le(const void *a, const void *b)
{
    COMPARE(a, b, <=, int)
}

bool int_ge(const void *a, const void *b)
{
    COMPARE(a, b, >=, int)
}

bool float_le(const void *a, const void *b)
{
    COMPARE(a, b, <=, float)
}

bool float_ge(const void *a, const void *b)
{
    COMPARE(a, b, >=, float)
}

bool double_le(const void *a, const void *b)
{
    COMPARE(a, b, <=, double)
}

bool double_ge(const void *a, const void *b)
{
    COMPARE(a, b, >=, double)
}
