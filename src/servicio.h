/*
 * servicio.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

int mostrarServicios( eServicio servicios[], int tamS );

int validarIdServicio( int id, eServicio servicios[], int tamS );

int cargarDescripcionServicio( eServicio servicios[], int tamS, int idServicio, char descripcion[] );

int cargarPrecioServicio( eServicio servicios[], int tamS, int idServicio, int* precio );

#endif /* SERVICIO_H_ */
