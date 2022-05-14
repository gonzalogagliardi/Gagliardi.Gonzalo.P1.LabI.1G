/*
 * moto.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef MOTO_H_
#define MOTO_H_

#include "color.h"
#include "tipo.h"

typedef struct
{
    int id;
    char marca[20];
    int idColor;
    int idTipo;
    int cilindradas;
    int puntaje;
    int isEmpty;
} eMoto;


int menu();

int inicializarMotos(eMoto lista[], int tam);

int buscarLibre(eMoto lista[], int tam);

int altaMoto(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo, int* pId);

void mostrarMoto(eMoto lista, eColor colores[], int tamCo, eTipo tipos[], int tamTipo);

int mostrarMotos( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int ordenarMotos(eMoto lista[], int tam, eTipo tipos[], int tamTipo);

int bajaMoto( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int buscarMotoId( eMoto lista[], int tam, int Id );

int modificarMoto( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int menuModificar( eMoto lista[], int tam, int indice, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int cargarColorMoto( eMoto lista[], int tam, eColor colores[], int tamCo, int idmoto, char color[] );

int validarMotoId( eMoto lista[], int tam, int id );
#endif /* MOTO_H_ */
