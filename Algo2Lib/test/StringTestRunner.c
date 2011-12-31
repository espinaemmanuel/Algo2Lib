#include "unity_fixture.h"

TEST_GROUP_RUNNER(String)
{
    RUN_TEST_CASE(String, NoFormatOperations);
    RUN_TEST_CASE(String, InsertString);
}

