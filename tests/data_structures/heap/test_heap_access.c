#include "unity.h"

#include <stdbool.h>

#include "ds/heap/core.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void test_parent(void)
{
    TEST_ASSERT_EQUAL_size_t(4, Heap_ParentIndex(9));
    TEST_ASSERT_EQUAL_size_t(1, Heap_ParentIndex(4));
    TEST_ASSERT_EQUAL_size_t(0, Heap_ParentIndex(1));
}

static void test_left(void)
{
    TEST_ASSERT_EQUAL_size_t(1, Heap_LeftIndex(0));
    TEST_ASSERT_EQUAL_size_t(3, Heap_LeftIndex(1));
    TEST_ASSERT_EQUAL_size_t(7, Heap_LeftIndex(3));

    TEST_ASSERT_EQUAL_size_t(5, Heap_LeftIndex(2));

    TEST_ASSERT_EQUAL_size_t(9, Heap_LeftIndex(4));
}

static void test_right(void)
{
    TEST_ASSERT_EQUAL_size_t(2, Heap_RightIndex(0));
    TEST_ASSERT_EQUAL_size_t(6, Heap_RightIndex(2));

    TEST_ASSERT_EQUAL_size_t(4, Heap_RightIndex(1));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_parent);
    RUN_TEST(test_left);
    RUN_TEST(test_right);

    return UNITY_END();
}
