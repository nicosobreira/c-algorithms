/** @file
 * Generic value comparison.
 *
 * # Usage
 *
 * Create an CompareFunc following the guidelines, then use @ref Compare_New to create a Compare struct.
 *
 * ## Example
 *
 * @code
 * #include <stdio.h>
 *
 * #include "compare/core.h"
 *
 * typedef struct Point
 * {
 *     int x;
 *     int y;
 * } Point;
 *
 * int compare_PointX(const void *a, const void* b)
 * {
 *     Point a_Point = *(const Point *)a;
 *     Point b_Point = *(const Point *)b;
 *
 *     return a_Point.x - b_Point.x;
 * }
 *
 * int main(void)
 * {
 *     Compare compare = Compare_New(compare_PointX);
 *
 *     Point a = {.x = 10, .y = 7};
 *     Point b = {.x = 3,  .y = 20};
 *
 *     if (Compare_Greater(&compare, &a, &b))
 *     {
 *         printf("(true) The point a has a greater value of x.\n");
 *     }
 *     else
 *     {
 *          printf("(false) The point b has a greater value of x.\n");
 *     }
 *
 *     return 0;
 * }
 * @endcode
 */

#pragma once

#include <stdbool.h>

/** Compare two values.
 * @param a[in] An pointer that need to be casted.
 * @param b[in] An pointer that need to be casted.
 * @return If `a` < `b` then return a negative integer (-1 for example).
 *         If `a` > `b` then return a positive integer (1 for example).
 *         If `a` == `b` then return zero.
 *
 * @note This function is similar to the `compare` function used in `qsort` (from `<stdlib>`), **but** we are not
 * comparing the position relative to an array, instead, we analyse the relation between `a` and `b`.
 *
 * @warning It's responsibility of this function to **cast** the correct data
 * type (from `void *` to `int *` for example). Wrong casting is undefined.
 */
typedef int (*CompareFunc)(const void *a, const void *b);

/** Wrapper to CompareFunc.
 */
typedef struct Compare
{
    const CompareFunc cmp;
} Compare;

Compare Compare_New(CompareFunc cmp);

bool Compare_Equals(const Compare *self, const void *a, const void *b);

bool Compare_Less(const Compare *self, const void *a, const void *b);

bool Compare_LessEquals(const Compare *self, const void *a, const void *b);

bool Compare_NotEqual(const Compare *self, const void *a, const void *b);

bool Compare_Greater(const Compare *self, const void *a, const void *b);

bool Compare_GreaterEquals(const Compare *self, const void *a, const void *b);
