#include "unity_fixture.h"

TEST_GROUP_RUNNER(String)
{
    RUN_TEST_CASE(String, Igualdad);
    RUN_TEST_CASE(String, IgualdadVacio);
    RUN_TEST_CASE(String, Desigualdad);
}

