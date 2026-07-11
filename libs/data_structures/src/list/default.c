#include "ds/list.h"

#include "compare/core.h"

List List_New_int(size_t size)
{
    return List_New(size, sizeof(int), Compare_New_int());
}

List List_WithCapacity_int(size_t capacity)
{
    return List_WithCapacity(capacity, sizeof(int), Compare_New_int());
}

List List_Load_int(const int *array, size_t size)
{
    return List_Load(array, size, sizeof(int), Compare_New_int());
}

// ------------------------------------------------------------

List List_New_double(size_t size)
{
    return List_New(size, sizeof(double), Compare_New_double());
}

List List_WithCapacity_double(size_t capacity)
{
    return List_WithCapacity(capacity, sizeof(double), Compare_New_double());
}

List List_Load_double(const double *array, size_t size)
{
    return List_Load(array, size, sizeof(double), Compare_New_double());
}
