#pragma once

#include "ds/list/view.h"

typedef struct MaxSubarrayResult
{
    size_t low;
    size_t high;
    void *sum;
} MaxSubarrayResult;

MaxSubarrayResult max_subarray_brute_force(const ListView *list);
