/*
 * informes.h
 *
 *  Created on: 17 may. 2022
 *      Author: NBGonza
 */
#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"



#ifndef INFORMES_H_
#define INFORMES_H_


int menuInformes();

int informarMotosColor( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int informarMotosIdColor( int idColor, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int informarMotosPromedioPuntaje( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo);

int informarMotosIdTipo( int idTipo, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int mostrarMotoMayorCilindrada(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo);

int informarMotosPorTipo( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo );

int cantMotosColorTipo(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo);

int mostrarTrabajosMoto(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam);

int colorMasElegido(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo);

int montoTrabajosMoto(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam);

int mostrarServicioMotos(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam);

int mostrarServiciosFecha(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam);

#endif /* INFORMES_H_ */
