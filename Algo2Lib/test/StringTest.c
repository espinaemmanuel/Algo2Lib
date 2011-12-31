#include "unity_fixture.h"
#include <stdio.h>
#include <memory.h>

TEST_GROUP(String);

static char output[100];
static const char * expected;

TEST_SETUP(String)
{
    memset(output, 0xaa, sizeof output);
    expected = "";
}

TEST_TEAR_DOWN(String)
{
}

static void expect(const char * s)
{
    expected = s;
}

static void given(int charsWritten)
{
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
}


TEST(String, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(String, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}
