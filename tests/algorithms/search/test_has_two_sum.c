#include "unity.h"

#include <stdlib.h>
#include <unity_internals.h>

#include "algo/search.h"

#include "ds/list/core.h"
#include "ds/list/defaults.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void *sum_func_int(const void *a, const void *b)
{
    int *number = malloc(sizeof(int));

    *number = *(int *)a + *(int *)b;

    return (void *)number;
}

static void test_success(void)
{
    int array[] = {1, 2, 3, 4};
    List list = List_Load_int(array, 4);

    int sum = 5;
    bool result = has_two_sum(&list, (void *)(&sum), sum_func_int);

    TEST_ASSERT_TRUE(result);
}

static void test_dont_exist(void)
{
    int array[] = {1, 2, 3, 4};
    List list = List_Load_int(array, 4);

    int sum = 99;
    bool result = has_two_sum(&list, (void *)(&sum), sum_func_int);

    TEST_ASSERT_FALSE(result);
}

static void test_same_number_fails(void)
{
    int array[] = {1, 2, 3, 4};
    List list = List_Load_int(array, 4);

    int sum = 8;
    bool result = has_two_sum(&list, (void *)(&sum), sum_func_int);

    TEST_ASSERT_FALSE(result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_success);
    RUN_TEST(test_dont_exist);
    RUN_TEST(test_same_number_fails);

    return UNITY_END();
}
