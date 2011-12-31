/*
 * tstring.c
 *
 *  Created on: 04/09/2011
 *      Author: emmanuel
 */

#include "tstring.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int TString_crear(TString *s, const char* texto){
	int tamTexto;
	tamTexto = strlen(texto);

	s->d = (char*) malloc(tamTexto + 1);

	if(s->d == NULL){
		return TSTRING_ERROR_NO_MEMORY;
	}

	strcpy(s->d, texto);

	return TSTRING_OK;
}


int TString_destruir(TString *s){
	free(s->d);
	return TSTRING_OK;
}


int TString_crearPorCopia(TString *s, const TString* origen){
	int tamTexto;
	tamTexto = strlen(origen->d);

	s->d = (char*) malloc(tamTexto + 1);

	if(s->d == NULL){
		return TSTRING_ERROR_NO_MEMORY;
	}

	strcpy(s->d, origen->d);

	return TSTRING_OK;
}

int TString_copiar(TString *s, const TString* origen){

	if(s != origen){
		int tam;
		tam = strlen(origen->d);
		free(s->d);
		s->d = (char*)malloc(tam + 1);
		if(s->d == NULL){
			return TSTRING_ERROR_NO_MEMORY;
		}
		strcpy(s->d, origen->d);
	}

	return TSTRING_OK;
}

int TString_concatenar(TString *s1, const TString *s2){
	int tam1, tam2;
	char* buffer;

	tam1 = strlen(s1->d);
	tam2 = strlen(s2->d);

	buffer = (char*) malloc(tam1 + tam2 + 1);

	if(buffer == NULL){
		return TSTRING_ERROR_NO_MEMORY;
	}

	strcpy(buffer, s1->d);
	strcat(buffer, s2->d);

	free(s1->d);
	s1->d = buffer;

	return TSTRING_OK;
}

int TString_sonIguales(const TString *s1, const TString *s2){
	int cmp;
	cmp = strcmp(s1->d, s2->d);

	if(cmp == 0){
		return 1;
	} else {
		return 0;
	}
}

int TString_comparar(const TString *s1, const TString *s2){
	int cmp;
	cmp = strcmp(s1->d, s2->d);

	if(cmp > 0){
		return TSTRING_MAYOR;
	} else if (cmp < 0) {
		return TSTRING_MENOR;
	} else {
		return TSTRING_IGUALES;
	}
}

int TString_print(const TString *s1){
	printf("%s", s1->d);
	return TSTRING_OK;
}
