#include "compare_funcs.h"

int compare_int(const void *a, const void *b)
{
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    return int_a - int_b;
}

int compare_double(const void *a, const void *b)
{
    double double_a = *(const double *)a;
    double double_b = *(const double *)b;

    if (double_a < double_b)
    {
        return -1;
    }

    if (double_a > double_b)
    {
        return 1;
    }

    return 0;
}
