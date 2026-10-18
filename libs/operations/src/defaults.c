#include "operations/defaults.h"

#include <string.h>

static void add_int(void *result, const void *a, const void *b)
{
    int sum = *(int *)a + *(int *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void subtract_int(void *result, const void *a, const void *b)
{
    int sum = *(int *)a - *(int *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void multiply_int(void *result, const void *a, const void *b)
{
    int sum = *(int *)a * *(int *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void divide_int(void *result, const void *a, const void *b)
{
    int sum = *(int *)a / *(int *)b;

    memcpy(result, &sum, sizeof(sum));
}

Operations Operations_New_int(void)
{
    return Operations_New(sizeof(int), (OperationsFunctions){
                                           .add = add_int,
                                           .subtract = subtract_int,
                                           .multiply = multiply_int,
                                           .divide = divide_int,
                                       });
}

////////////////////////////////////////////////////////////////////////

static void add_double(void *result, const void *a, const void *b)
{
    double sum = *(double *)a + *(double *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void subtract_double(void *result, const void *a, const void *b)
{
    double sum = *(double *)a - *(double *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void multiply_double(void *result, const void *a, const void *b)
{
    double sum = *(double *)a * *(double *)b;

    memcpy(result, &sum, sizeof(sum));
}

static void divide_double(void *result, const void *a, const void *b)
{
    double sum = *(double *)a / *(double *)b;

    memcpy(result, &sum, sizeof(sum));
}

Operations Operations_New_double(void)
{
    return Operations_New(sizeof(double), (OperationsFunctions){
                                              .add = add_double,
                                              .subtract = subtract_double,
                                              .multiply = multiply_double,
                                              .divide = divide_double,
                                          });
}
