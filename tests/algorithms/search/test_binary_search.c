#include "unity.h"

#include "ds/list.h"

#include "algo/search.h"

void setUp(void)
{
}
void tearDown(void)
{
}

static void test_element_dont_exist(void)
{
    int array[] = {1, 2, 3};
    List list = List_Load_int(array, 3);

    SearchResult sr = binary_search(&list, &(int){100});

    bool did_find = SearchResult_Check(&sr);

    TEST_ASSERT_EQUAL(false, did_find);
}

static void test_correctness_top(void)
{
    int array[] = {1, 3, 5, 8, 9};
    List list = List_Load_int(array, 5);

    SearchResult sr = binary_search(&list, &(int){9});

    bool did_find = SearchResult_Check(&sr);

    TEST_ASSERT_EQUAL(true, did_find);

    TEST_ASSERT_EQUAL_size_t(4, SearchResult_Index(&sr));

    int value = *(int *)SearchResult_PointerTo(&sr);

    TEST_ASSERT_EQUAL_INT(9, value);

    List_Free(&list);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_element_dont_exist);
    RUN_TEST(test_correctness_top);

    return UNITY_END();
}
