#include "unity.h"

#include "operations/core.h"
#include "operations/defaults.h"

// TODO: Full test coverage (new test struct and defaults)

void setUp(void)
{
}

void tearDown(void)
{
}

static void add(void)
{
    int result;
    int a = 3;
    int b = 2;

    Operations op = Operations_New_int();

    Operations_Add(&op, &result, &a, &b);

    TEST_ASSERT_EQUAL(5, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(add);

    return UNITY_END();
}
