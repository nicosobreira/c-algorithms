#include <stdio.h>

#include "compare/core.h"

typedef struct Point
{
    int x;
    int y;
} Point;

static int compare_PointX(const void *a, const void *b)
{
    Point a_point = *(const Point *)a;
    Point b_point = *(const Point *)b;

    return a_point.x - b_point.x;
}

int main(void)
{
    Compare compare = Compare_New(compare_PointX);

    Point a = {.x = 10, .y = 7};
    Point b = {.x = 3, .y = 20};

    if (Compare_Greater(&compare, &a, &b))
    {
        printf("(true) The point a has a greater value of x.\n");
    }
    else
    {
        printf("(false) The point b has a greater value of x.\n");
    }

    return 0;
}
