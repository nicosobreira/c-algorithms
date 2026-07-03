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

bool int_le(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, int)
}

bool int_ge(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, int)
}

bool float_le(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, float)
}

bool float_ge(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, float)
}

bool double_le(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, double)
}

bool double_ge(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, double)
}
