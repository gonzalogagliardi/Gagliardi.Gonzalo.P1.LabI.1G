/*
 * color.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
    int id;
    char descripcion[20];
}eColor;

int mostrarColores( eColor colores[], int tamCo );

int validarIdColor( int id, eColor colores[], int tamCo );

int cargarDescripcionColor( eColor colores[], int tamCo, int idColor, char descripcion[] );


#endif /* COLOR_H_ */
