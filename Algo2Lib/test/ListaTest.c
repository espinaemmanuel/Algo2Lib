#include "unity_fixture.h"
#include "tlista.h"
#include <string.h>

TEST_GROUP(Lista);

TEST_SETUP(Lista)
{
}

TEST_TEAR_DOWN(Lista)
{
}

int copiarString(const void* origen, void* destino){
	strcpy(destino, origen);
	return 0;
}

int destruirString(void* dato){
	return 0;
}

TEST(Lista, Insertar)
{
	TLista lista;
	struct TLista_config config;
	char* palabras[] = {"uno", "dos", "tres"};
	char buffer[100];

	config.crearCopiaDato = copiarString;
	config.destruirDato = destruirString;
	config.sizeDato = 100;

	TEST_ASSERT_EQUAL(TL_OK, TL_crear(&lista, &config));
	TEST_ASSERT_EQUAL(TL_OK, TL_insertarDespues(&lista, palabras[0]));
	TEST_ASSERT_EQUAL(TL_OK, TL_insertarDespues(&lista, palabras[1]));
	TEST_ASSERT_EQUAL(TL_OK, TL_insertarDespues(&lista, palabras[2]));

	TEST_ASSERT_EQUAL(TL_OK, TL_primero(&lista));
	TEST_ASSERT_EQUAL(TL_OK, TL_elemento(&lista, buffer));
	TEST_ASSERT_EQUAL_STRING("uno", buffer);

	TEST_ASSERT_EQUAL(TL_OK, TL_siguiente(&lista));
	TEST_ASSERT_EQUAL(TL_OK, TL_elemento(&lista, buffer));
	TEST_ASSERT_EQUAL_STRING("dos", buffer);

	TEST_ASSERT_EQUAL(TL_OK, TL_siguiente(&lista));
	TEST_ASSERT_EQUAL(TL_OK, TL_elemento(&lista, buffer));
	TEST_ASSERT_EQUAL_STRING("tres", buffer);

	TEST_ASSERT_EQUAL(TL_FIN, TL_siguiente(&lista));

	TEST_ASSERT_EQUAL(TL_OK, TL_destruir(&lista));
}

TEST(Lista, InsertarAntes){

}

TEST(Lista, InsertarDespues){

}

TEST(Lista, Eliminar){

}
