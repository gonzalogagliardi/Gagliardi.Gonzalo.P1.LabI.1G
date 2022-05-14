/*
 * tipo.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int mostrarTipo( eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    if (tipos != NULL && tamTipo > 0 )
    {
        printf("      *** Tipo *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tamTipo; i++)
        {
            printf("  %d       %-10s\n", tipos[i].id, tipos[i].descripcion);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdTipo( int id, eTipo tipos[], int tamTipo )
{
    int esValido = 0;
    if (tipos != NULL && tamTipo > 0)
    {
        for (int i = 0; i < tamTipo; i++)
        {
            if (id == tipos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionTipo( eTipo tipos[], int tamTipo, int idTipo, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (tipos != NULL && tamTipo > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamTipo; i++)
        {
            if (tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
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
