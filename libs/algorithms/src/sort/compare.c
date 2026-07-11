#include "algo/sort.h"

#define COMPARE(a, b, operator, type) \
    type va = *(const type *)a;       \
    type vb = *(const type *)b;       \
                                      \
    return va operator vb;

bool int_increasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, int)
}

bool int_decreasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, int)
}

bool float_increasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, float)
}

bool float_decreasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, float)
}

bool double_increasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, <=, double)
}

bool double_decreasing(COMPARE_FUNC_ARGS)
{
    COMPARE(a, b, >=, double)
}
