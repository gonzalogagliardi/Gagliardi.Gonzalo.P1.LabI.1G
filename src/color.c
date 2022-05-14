/*
 * color.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int mostrarColores( eColor colores[], int tamCo )
{
    int todoOk = 0;
    if (colores != NULL && tamCo > 0 )
    {
        printf("      *** Colores *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tamCo; i++)
        {
            printf("  %d       %-10s\n", colores[i].id, colores[i].descripcion);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdColor( int id, eColor colores[], int tamCo )
{
    int esValido = 0;
    if (colores != NULL && tamCo > 0)
    {
        for (int i = 0; i < tamCo; i++)
        {
            if (id == colores[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}



int cargarDescripcionColor( eColor colores[], int tamCo, int idColor, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (colores != NULL && tamCo > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamCo; i++)
        {
            if (colores[i].id == idColor)
            {
                strcpy(descripcion, colores[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia marca con el id que le pasaron
        }
    }
    return todoOk;
}
