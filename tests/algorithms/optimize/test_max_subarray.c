#include "unity.h"

#include "algo/optimize.h"

#include "ds/list/core.h"
#include "ds/list/defaults.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void correctness_brute(void)
{
    double array[3] = {10.0, 20.0, 30.0};

    List list = List_Load_double(array, 3);

    MaxSubarrayResult result = max_subarray_brute_force(LIST_VIEW(&list));

    MaxSubarrayResult expected = {
        .low = 0,
        .high = 2,
    };

    TEST_ASSERT_EQUAL(expected.low, result.low);
    TEST_ASSERT_EQUAL(expected.high, result.high);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(correctness_brute);

    return UNITY_END();
}
