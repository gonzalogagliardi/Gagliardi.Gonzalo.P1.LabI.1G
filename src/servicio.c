/*
 * servicio.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int mostrarServicios( eServicio servicios[], int tamS )
{
    int todoOk = 0;
    if (servicios != NULL && tamS > 0 )
    {
        printf("      *** Servicios  *** \n\n");
        printf("  Id          Descripcion         Precio\n");
        for (int i = 0; i < tamS; i++)
        {
            printf("  %d       %-10s          $%d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }

        todoOk = 1;
    }

    return todoOk;
}

int validarIdServicio( int id, eServicio servicios[], int tamS )
{
    int esValido = 0;
    if (servicios != NULL && tamS > 0)
    {
        for (int i = 0; i < tamS; i++)
        {
            if (id == servicios[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionServicio( eServicio servicios[], int tamS, int idServicio, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (servicios != NULL && tamS > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamS; i++)
        {
            if (servicios[i].id == idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int cargarPrecioServicio( eServicio servicios[], int tamS, int idServicio, int* precio )
{
    int todoOk = 0;
    int flag = 1;

    if (servicios != NULL && tamS > 0 && precio != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamS; i++)
        {
            if (servicios[i].id == idServicio)
            {
                *precio = servicios[i].precio;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
