#include "unity_fixture.h"
#include "tstring.h"

TEST_GROUP(String);

TEST_SETUP(String)
{
}

TEST_TEAR_DOWN(String)
{
}


TEST(String, Igualdad)
{
	TString sA, sB;
	TString_crear(&sA, "Hola mundo");
	TString_crear(&sB, "Hola mundo");

	TEST_ASSERT_EQUAL(TString_sonIguales(&sA, &sB), 1);

	TString_destruir(&sA);
	TString_destruir(&sB);
}

TEST(String, IgualdadVacio)
{
	TString sA, sB;
	TString_crear(&sA, "");
	TString_crear(&sB, "");

	TEST_ASSERT_EQUAL(TString_sonIguales(&sA, &sB), 1);

	TString_destruir(&sA);
	TString_destruir(&sB);
}

TEST(String, Desigualdad)
{
	TString sA, sB;
	TString_crear(&sA, "Hola");
	TString_crear(&sB, "Mundo");

	TEST_ASSERT_EQUAL(TString_sonIguales(&sA, &sB), 0);

	TString_destruir(&sA);
	TString_destruir(&sB);
}

