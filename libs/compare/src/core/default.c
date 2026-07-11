#include "default.h"

bool int_equals(COMPARE_FUNC_ARGS)
{
    EQUALS(a, b, int);
}

bool int_less(COMPARE_FUNC_ARGS)
{
    LESS(a, b, int);
}

bool double_equals(COMPARE_FUNC_ARGS)
{
    EQUALS(a, b, double);
}

bool double_less(COMPARE_FUNC_ARGS)
{
    LESS(a, b, double);
}
