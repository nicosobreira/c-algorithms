#include "unity.h"

#include "algo/sort.h"
#include "ds/list.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void test_single_element(void)
{
    int array[] = {1};
    List list = List_Load_int(array, 1);

    insertion_sort(&list);

    TEST_ASSERT_EQUAL_INT_ARRAY(array, list.ptr, 1);

    List_Free(&list);
}

static void test_general_case(void)
{
    int array[] = {3, 2, 1};
    List list = List_Load_int(array, 3);

    insertion_sort(&list);

    int expected[] = {1, 2, 3};

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, list.ptr, 3);

    List_Free(&list);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_single_element);
    RUN_TEST(test_general_case);

    return UNITY_END();
}
