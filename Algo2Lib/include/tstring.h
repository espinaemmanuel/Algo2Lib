/*
 * string.h
 *
 *  Created on: 04/09/2011
 *      Author: emmanuel
 */

#ifndef STRING_H_
#define STRING_H_

typedef struct{
	char* d;
}TString;

#define TSTRING_MAYOR	-1
#define TSTRING_IGUALES	0
#define TSTRING_MENOR	1

#define TSTRING_OK 0
#define TSTRING_ERROR_NO_MEMORY -1

int TString_crear(TString *s, const char* texto);
int TString_destruir(TString *s);
int TString_crearPorCopia(TString *s, const TString* origen);
int TString_copiar(TString *s, const TString* origen);
int TString_concatenar(TString *s1, const TString *s2);
int TString_sonIguales(const TString *s1, const TString *s2);
int TString_comparar(const TString *s1, const TString *s2);
int TString_print(const TString *s1);



#endif /* STRING_H_ */
