#include "unity.h"

#include "ds/list.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void test_list_load(void)
{
    int expected[] = {1, 3, 108};
    List list = List_Load(expected, 3, sizeof(int));

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, list.ptr, 3);

    List_Free(&list);
}

static void test_list_swap(void)
{
    int array[] = {1, 3, 108};
    List list = List_Load(array, 3, sizeof(int));

    List_Swap(&list, 1, 2);

    int expected[] = {1, 108, 3};

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, list.ptr, 3);
}

static void test_list_new_slice(void)
{
    int array[] = {1, 3, 108};
    List list = List_Load(array, 3, sizeof(int));

    List slice = List_NewSlice(&list, 0, 1);

    int expected[] = {1, 3};

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, slice.ptr, 2);
}

static void test_list_push_increases_size(void)
{
    List list = List_WithCapacity(2, sizeof(int));

    int value = 42;
    List_Push(&list, &value);

    TEST_ASSERT_EQUAL_UINT(1, List_Size(&list));
    TEST_ASSERT_EQUAL_INT(42, *(int *)List_Get(&list, 0));

    List_Free(&list);
}

static void test_list_get_set(void)
{
    int array[] = {1, 2, 3};
    List list = List_Load(array, 3, sizeof(int));

    int new_value = 99;
    List_Set(&list, 1, &new_value);

    TEST_ASSERT_EQUAL_INT(99, *(int *)List_Get(&list, 1));

    List_Free(&list);
}

static void test_list_is_empty(void)
{
    List list = List_WithCapacity(4, sizeof(int));
    TEST_ASSERT_TRUE(List_IsEmpty(&list));

    int value = 1;
    List_Push(&list, &value);
    TEST_ASSERT_FALSE(List_IsEmpty(&list));

    List_Free(&list);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_list_load);
    RUN_TEST(test_list_swap);
    RUN_TEST(test_list_new_slice);
    RUN_TEST(test_list_push_increases_size);
    RUN_TEST(test_list_get_set);
    RUN_TEST(test_list_is_empty);

    return UNITY_END();
}
