#include "unity.h"

#include "compare/core.h"

void setUp(void)
{
}
void tearDown(void)
{
}

// ------------------------------------------------------------
// Compare_New (generic constructor)
// ------------------------------------------------------------

static bool always_equal(const void *a, const void *b)
{
    (void)a;
    (void)b;

    return true;
}

static bool always_less(const void *a, const void *b)
{
    (void)a;
    (void)b;

    return false;
}

static void test_compare_new_stores_function_pointers(void)
{
    Compare compare = Compare_New(always_equal, always_less);

    TEST_ASSERT_TRUE(compare.equals == always_equal);
    TEST_ASSERT_TRUE(compare.less == always_less);
}

static void test_compare_new_dispatches_to_given_functions(void)
{
    Compare compare = Compare_New(always_equal, always_less);

    int a = 1;
    int b = 2;

    TEST_ASSERT_TRUE(Compare_Equals(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Less(&compare, &a, &b));
}

// ------------------------------------------------------------
// Compare_New_int
// ------------------------------------------------------------

static void test_compare_new_int_equals(void)
{
    Compare compare = Compare_New_int();

    int a = 5;
    int b = 5;
    int c = 8;

    TEST_ASSERT_TRUE(Compare_Equals(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Equals(&compare, &a, &c));
}

static void test_compare_new_int_less(void)
{
    Compare compare = Compare_New_int();

    int a = 3;
    int b = 8;

    TEST_ASSERT_TRUE(Compare_Less(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Less(&compare, &b, &a));
    TEST_ASSERT_FALSE(Compare_Less(&compare, &a, &a));
}

// ------------------------------------------------------------
// Compare_New_double
// ------------------------------------------------------------

static void test_compare_new_double_equals(void)
{
    Compare compare = Compare_New_double();

    double a = 1.5;
    double b = 1.5;
    double c = 2.5;

    TEST_ASSERT_TRUE(Compare_Equals(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Equals(&compare, &a, &c));
}

static void test_compare_new_double_less(void)
{
    Compare compare = Compare_New_double();

    double a = 1.1;
    double b = 2.2;

    TEST_ASSERT_TRUE(Compare_Less(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Less(&compare, &b, &a));
}

// ------------------------------------------------------------
// Compare_LessEquals / Compare_NotEqual / Compare_Greater / Compare_GreaterEquals
// ------------------------------------------------------------

static void test_compare_less_equals(void)
{
    Compare compare = Compare_New_int();

    int a = 3;
    int b = 8;

    TEST_ASSERT_TRUE(Compare_LessEquals(&compare, &a, &b));
    TEST_ASSERT_TRUE(Compare_LessEquals(&compare, &a, &a));
    TEST_ASSERT_FALSE(Compare_LessEquals(&compare, &b, &a));
}

static void test_compare_not_equal(void)
{
    Compare compare = Compare_New_int();

    int a = 3;
    int b = 8;

    TEST_ASSERT_TRUE(Compare_NotEqual(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_NotEqual(&compare, &a, &a));
}

static void test_compare_greater(void)
{
    Compare compare = Compare_New_int();

    int a = 8;
    int b = 3;

    TEST_ASSERT_TRUE(Compare_Greater(&compare, &a, &b));
    TEST_ASSERT_FALSE(Compare_Greater(&compare, &b, &a));
    TEST_ASSERT_FALSE(Compare_Greater(&compare, &a, &a));
}

static void test_compare_greater_equals(void)
{
    Compare compare = Compare_New_int();

    int a = 8;
    int b = 3;

    TEST_ASSERT_TRUE(Compare_GreaterEquals(&compare, &a, &b));
    TEST_ASSERT_TRUE(Compare_GreaterEquals(&compare, &a, &a));
    TEST_ASSERT_FALSE(Compare_GreaterEquals(&compare, &b, &a));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_compare_new_stores_function_pointers);
    RUN_TEST(test_compare_new_dispatches_to_given_functions);

    RUN_TEST(test_compare_new_int_equals);
    RUN_TEST(test_compare_new_int_less);

    RUN_TEST(test_compare_new_double_equals);
    RUN_TEST(test_compare_new_double_less);

    RUN_TEST(test_compare_less_equals);
    RUN_TEST(test_compare_not_equal);
    RUN_TEST(test_compare_greater);
    RUN_TEST(test_compare_greater_equals);

    return UNITY_END();
}
