/*
 * tlista.c
 *
 *  Created on: 31/12/2011
 *      Author: emmanuel
 */

#include "tlista.h"
#include <stdlib.h>

int TL_crear(TLista* l, const struct TLista_config* config){
	l->crearCopiaDato = config->crearCopiaDato;
	l->destruirDato = config->destruirDato;
	l->sizeDato = config->sizeDato;

	l->header.anterior = &(l->header);
	l->header.siguiente = &(l->header);
	l->corriente = &(l->header);
	l->numElementos = 0;

	return TL_OK;
}

int TL_destruir(TLista* l){
	int estado = TL_OK;

	while(l->numElementos > 0 && estado == TL_OK){
		estado = TL_eliminar(l);
	}

	return estado;
}

int TL_crearCopia(const TLista* l, TLista* copia){
	struct TLista_config config;
	NodoLista* nodo;
	int estado = TL_OK;

	config.sizeDato = l->sizeDato;
	config.crearCopiaDato = l->crearCopiaDato;
	config.destruirDato = l->destruirDato;

	TL_crear(copia, &config);

	nodo = l->header.siguiente;
	while(nodo != &(l->header) && estado == TL_OK){
		estado = TL_insertarDespues(copia, nodo->dato);
		nodo = nodo->siguiente;
	}

	return estado;
}

int TL_cantidad(const TLista* l){
	return l->numElementos;
}

int TL_siguiente(TLista* l){
	if(l->corriente->siguiente == &(l->header)){
		return TL_FIN;
	}

	l->corriente = l->corriente->siguiente;

	return TL_OK;
}

int TL_anterior(TLista* l){
	if(l->corriente->anterior == &(l->header)){
		return TL_FIN;
	}

	l->corriente = l->corriente->anterior;

	return TL_OK;
}

int TL_primero(TLista* l){
	if(l->numElementos == 0){
		return TL_VACIA;
	}

	l->corriente = l->header.siguiente;

	return TL_OK;
}

int TL_ultimo(TLista* l){
	if(l->numElementos == 0){
		return TL_VACIA;
	}

	l->corriente = l->header.anterior;

	return TL_OK;
}

int TL_elemento(const TLista* l, void* dato){
	if(l->numElementos == 0){
		return TL_VACIA;
	}

	if(l->crearCopiaDato(l->corriente->dato, dato) != 0){
		return TL_COPIAR_DATO;
	}

	return TL_OK;
}

NodoLista* TL_PRIV_AlocarNodo(const size_t sizeDato){
	NodoLista* nuevoNodo;
	void* nuevoDato;

	nuevoNodo = (NodoLista*) malloc(sizeof(NodoLista));
	if(nuevoNodo == NULL){
		return 0;
	}

	nuevoDato = malloc(sizeDato);
	if(nuevoDato == NULL){
		free(nuevoNodo);
		return 0;
	}

	nuevoNodo->dato = nuevoDato;

	return nuevoNodo;
}

int TL_PRIV_LiberarNodo(NodoLista* nodo){
	free(nodo->dato);
	free(nodo);

	return TL_OK;
}

int TL_insertarAntes(TLista* l, const void* dato){
	NodoLista* nuevoNodo;
	nuevoNodo = TL_PRIV_AlocarNodo(l->sizeDato);
	if(nuevoNodo == 0){
		return TL_NO_MEMORIA;
	}

	if(l->crearCopiaDato(dato, nuevoNodo->dato) != 0){
		TL_PRIV_LiberarNodo(nuevoNodo);
		return TL_COPIAR_DATO;
	}

	nuevoNodo->siguiente = l->corriente;
	nuevoNodo->anterior = l->corriente->anterior;
	nuevoNodo->siguiente->anterior = nuevoNodo;
	nuevoNodo->anterior->siguiente = nuevoNodo;
	l->corriente = nuevoNodo;

	l->numElementos++;

	return TL_OK;
}

int TL_insertarDespues(TLista* l, const void* dato){
	NodoLista* nuevoNodo;
	nuevoNodo = TL_PRIV_AlocarNodo(l->sizeDato);
	if(nuevoNodo == 0){
		return TL_NO_MEMORIA;
	}

	if(l->crearCopiaDato(dato, nuevoNodo->dato) != 0){
		TL_PRIV_LiberarNodo(nuevoNodo);
		return TL_COPIAR_DATO;
	}

	nuevoNodo->siguiente = l->corriente->siguiente;
	nuevoNodo->anterior = l->corriente;
	nuevoNodo->siguiente->anterior = nuevoNodo;
	nuevoNodo->anterior->siguiente = nuevoNodo;
	l->corriente = nuevoNodo;

	l->numElementos++;

	return TL_OK;
}

int TL_eliminar(TLista* l){
	NodoLista* eliminado;

	if(l->numElementos == 0){
		return TL_VACIA;
	}

	if(l->destruirDato(l->corriente->dato) != 0){
		return TL_DESTRUIR_DATO;
	}

	l->corriente->anterior->siguiente = l->corriente->siguiente;
	l->corriente->siguiente->anterior = l->corriente->anterior;

	eliminado = l->corriente;
	if(l->corriente->siguiente != &(l->header)){
		l->corriente = l->corriente->siguiente;
	} else {
		l->corriente = l->corriente->anterior;
	}

	TL_PRIV_LiberarNodo(eliminado);

	l->numElementos--;

	return TL_OK;

}

