/*
 * trabajo.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "fecha.h"
#include "moto.h"
#include "servicio.h"
#include "servicio.h"

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

int inicializarTrabajos( eTrabajo trabajos[], int tamT );

int buscarLibreTrabajo( eTrabajo trabajos[], int tamT );

int altaTrabajo( eTrabajo trabajos[], int tamT, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo, eServicio servicios[], int tamS, int* pIdTrabajo );

void mostrarTrabajo( eTrabajo unTrabajo, eMoto lista[], int tam, eColor colores[], int tamCo, eServicio servicios[], int tamS );

int mostrarTrabajos( eTrabajo trabajos[], int tamT, eMoto lista[], int tam, eColor colores[], int tamCo, eServicio servicios[], int tamS );

int pedirFecha(eFecha* unaFecha);

#endif /* TRABAJO_H_ */
