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
    const int search = 100;

    int array[] = {1, 2, 3};
    List list = List_Load_int(array, 3);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_FALSE(SearchResult_Check(&sr));
}

static void test_element_dont_exist_between(void)
{
    const int search = 2;

    int array[] = {1, 3, 5, 8, 9};
    List list = List_Load_int(array, 5);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_FALSE(SearchResult_Check(&sr));
}

static void test_top_success(void)
{
    const int search = 9;
    const size_t index = 4;

    int array[] = {1, 3, 5, 8, search};
    List list = List_Load_int(array, 5);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_TRUE(SearchResult_Check(&sr));

    TEST_ASSERT_EQUAL_size_t(index, SearchResult_Index(&sr));

    int value = *(int *)SearchResult_PointerTo(&sr);
    TEST_ASSERT_EQUAL_INT(search, value);

    List_Free(&list);
}

static void test_mid_success(void)
{
    const int search = 5;
    const size_t index = 2;

    int array[] = {1, 3, search, 8, 9};
    List list = List_Load_int(array, 5);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_TRUE(SearchResult_Check(&sr));

    TEST_ASSERT_EQUAL_size_t(index, SearchResult_Index(&sr));

    int value = *(int *)SearchResult_PointerTo(&sr);
    TEST_ASSERT_EQUAL_INT(search, value);

    List_Free(&list);
}

static void test_bottom_success(void)
{
    const int search = 1;
    const size_t index = 0;

    int array[] = {1, 3, 5, 8, 9};
    List list = List_Load_int(array, 5);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_TRUE(SearchResult_Check(&sr));

    TEST_ASSERT_EQUAL_size_t(index, SearchResult_Index(&sr));

    int value = *(int *)SearchResult_PointerTo(&sr);
    TEST_ASSERT_EQUAL_INT(search, value);

    List_Free(&list);
}

static void test_single_element_success(void)
{
    const int search = 1;
    const size_t index = 0;

    int array[] = {search};
    List list = List_Load_int(array, 1);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_TRUE(SearchResult_Check(&sr));

    TEST_ASSERT_EQUAL_size_t(index, SearchResult_Index(&sr));

    int value = *(int *)SearchResult_PointerTo(&sr);
    TEST_ASSERT_EQUAL_INT(search, value);

    List_Free(&list);
}

static void test_single_element_failure(void)
{
    const int search = 20;

    int array[] = {1};
    List list = List_Load_int(array, 1);

    SearchResult sr = binary_search(&list, &search);

    TEST_ASSERT_FALSE(SearchResult_Check(&sr));

    List_Free(&list);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_element_dont_exist);
    RUN_TEST(test_element_dont_exist_between);

    RUN_TEST(test_top_success);
    RUN_TEST(test_mid_success);
    RUN_TEST(test_bottom_success);

    RUN_TEST(test_single_element_success);
    RUN_TEST(test_single_element_failure);

    return UNITY_END();
}
