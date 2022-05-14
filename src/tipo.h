/*
 * tipo.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

int mostrarTipo( eTipo tipos[], int tamTipo );

int validarIdTipo( int id, eTipo tipos[], int tamTipo );

int cargarDescripcionTipo( eTipo tipos[], int tamTipo, int idTipo, char descripcion[] );

#endif /* TIPO_H_ */
