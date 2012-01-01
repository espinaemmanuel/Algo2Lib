/*
 * tlista.h
 *
 *  Created on: 31/12/2011
 *      Author: emmanuel
 */

#ifndef TLISTA_H_
#define TLISTA_H_

#include <stdlib.h>

#define TL_OK 0
#define TL_FIN -1
#define TL_VACIA -2
#define TL_NO_MEMORIA -3
#define TL_COPIAR_DATO -4;
#define TL_DESTRUIR_DATO -5;

struct TLista_config{
	size_t sizeDato;
	int (*crearCopiaDato)(const void* origen, void* destino);
	int (*destruirDato)(void* dato);
};


struct _NodoLista;
typedef struct _NodoLista NodoLista;

struct _NodoLista{
	void* dato;
	NodoLista* siguiente;
	NodoLista* anterior;
};

typedef struct _TLista{
	int numElementos;
	size_t sizeDato;
	int (*crearCopiaDato)(const void* origen, void* destino);
	int (*destruirDato)(void* dato);

	NodoLista header;
	NodoLista* corriente;
}TLista;

int TL_crear(TLista* l, const struct TLista_config* config);
int TL_destruir(TLista* l);
int TL_crearCopia(const TLista* l, TLista* copia);

int TL_cantidad(const TLista* l);

int TL_siguiente(TLista* l);
int TL_anterior(TLista* l);
int TL_primero(TLista* l);
int TL_ultimo(TLista* l);

int TL_elemento(const TLista* l, void* dato);
int TL_insertarAntes(TLista* l, const void* dato);
int TL_insertarDespues(TLista* l, const void* dato);

/*Elimina y coloca el puntero en el siguiente, y si era el ultimo en el anterior*/
int TL_eliminar(TLista* l);

#endif /* TLISTA_H_ */
