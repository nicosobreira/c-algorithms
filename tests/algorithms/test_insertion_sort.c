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
    List list = List_Load(array, 1, sizeof(int));

    insertion_sort(&list, int_increasing);

    TEST_ASSERT_EQUAL_INT_ARRAY(array, list.ptr, 1);
}

static void test_general_case(void)
{
    int array[] = {3, 2, 1};
    List list = List_Load(array, 3, sizeof(int));

    insertion_sort(&list, int_increasing);

    int expected[] = {1, 2, 3};

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, list.ptr, 3);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_single_element);
    RUN_TEST(test_general_case);

    return UNITY_END();
}
