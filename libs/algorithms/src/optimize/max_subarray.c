#include "algo/optimize.h"

#include <stdlib.h>
#include <string.h>

#include "utils/allocation.h"

#include "ds/list/compare.h"
#include "ds/list/operations.h"
#include "ds/list/view.h"

// Maximize the difference between the current day and the future

// FIX: Letting the data_size by publicy avaible via a get function is
// dangerous. Create a function named ListView_Alloc() to do the same.

MaxSubarrayResult max_subarray_brute_force(const ListView *list)
{
    // Optimal buy and sell prices
    size_t buy = 0;
    size_t sell = 0;

    const size_t data_size = ListView_DataSize(list);

    void *change = must_malloc(data_size);
    void *max_change = must_malloc(data_size);

    memset(max_change, 0, data_size);

    for (size_t b = 0; b < ListView_Size(list) - 1; b++) // Buy
    {
        for (size_t s = b + 1; s < ListView_Size(list); s++) // Sell
        {
            ListView_Operations_SubtractAt(list, change, s, b);

            if (ListView_Compare_Greater(list, change, max_change))
            {
                memcpy(max_change, change, data_size);

                buy = b;
                sell = s;
            }
        }
    }

    free(change);
    free(max_change);

    return (MaxSubarrayResult){
        .low = buy,
        .high = sell,
        .sum = max_change,
    };
}

static inline MaxSubarrayResult find_max_crossing_subarray(ListView *list, size_t start, size_t end)
{
    const size_t mid = (start + end) / 2;
}

static MaxSubarrayResult divide(ListView *list, size_t start, size_t end)
{
    if (start == end)
    {
        return (MaxSubarrayResult){
            .low = start,
            .high = start,
            .sum = ListView_Get(list, start),
        };
    }

    size_t mid = (start + end) / 2;
    MaxSubarrayResult left = divide(list, start, mid);
    MaxSubarrayResult right = divide(list, mid + 1, end);
    MaxSubarrayResult middle = middle(list, start, end);
}

MaxSubarrayResult max_subarray(ListView *list)
{
    const size_t low = 0;
    const size_t high = ListView_Size(list);

    divide(list, low, high);
}
