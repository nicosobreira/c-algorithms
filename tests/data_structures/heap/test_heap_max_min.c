#include "unity.h"

#include "ds/heap/core.h"
#include "ds/heap/defaults.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void test_is_max(void)
{
    int array[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    Heap heap = Heap_Load_int(array, sizeof(array) / sizeof(array[0]));

    bool is_max = Heap_IsMax(&heap);

    TEST_ASSERT_EQUAL_INT(true, is_max);
}

static void test_isnt_max(void)
{
    int array[] = {16, 14, 10, 8, 7, 11, 3, 2, 4, 1};
    Heap heap = Heap_Load_int(array, sizeof(array) / sizeof(array[0]));

    bool is_max = Heap_IsMax(&heap);

    TEST_ASSERT_EQUAL_INT(false, is_max);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_is_max);
    RUN_TEST(test_isnt_max);

    return UNITY_END();
}
