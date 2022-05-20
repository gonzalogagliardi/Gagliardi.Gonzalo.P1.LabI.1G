/*
 * trabajo.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "fecha.h"
#include "input.h"
#include "moto.h"


int inicializarTrabajos( eTrabajo trabajos[], int tamT )
{
    int todoOk = 0;
    if (trabajos != NULL && tamT > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamT; i++)
        {
            trabajos[i].isEmpty = 1;
        }
    }
    return todoOk;
}


int buscarLibreTrabajo( eTrabajo trabajos[], int tamT )
{
    int indice = -1;
    for (int i = 0; i < tamT; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaTrabajo( eTrabajo trabajos[], int tamT, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo, eServicio servicios[], int tamS, int* pIdTrabajo )
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    eFecha auxFecha;


    if (trabajos != NULL && tamT > 0 && lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 && servicios != NULL && tamS > 0  && pIdTrabajo != NULL )
    {
        system("cls");
        printf("  ***Alta Trabajo*** \n\n");
        indice = buscarLibreTrabajo(trabajos, tamT);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;

            mostrarMotos(lista, tam, colores, tamCo, tipos, tamTipo);
            printf("Ingrese id de Moto: ");
            scanf("%d", &auxTrabajo.idMoto);
            while ( buscarMotoId(lista, tam, auxTrabajo.idMoto) == -1  )
            {
                printf("Error, ingrese id de Moto  valido: ");
                scanf("%d", &auxTrabajo.idMoto);
            }

            mostrarServicios(servicios, tamS);
            printf("Ingrese id de Servicio: ");
            scanf("%d", &auxTrabajo.idServicio);
            while ( !validarIdServicio(auxTrabajo.idServicio, servicios, tamS)    )
            {
                printf("Error, ingrese id de Servicio  valido: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

           pedirFecha(&auxFecha);

            auxTrabajo.fecha = auxFecha;

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarTrabajo( eTrabajo unTrabajo, eMoto lista[], int tam, eColor colores[], int tamCo, eServicio servicios[], int tamS )
{
    char descColor[20];
    char descServicio[20];
    int precio;

    if ( cargarColorMoto(lista, tam, colores, tamCo, unTrabajo.idMoto, descColor) == 1 &&
            cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descServicio) == 1 &&
            cargarPrecioServicio(servicios, tamS, unTrabajo.idServicio, &precio) == 1 )
    {
        printf(" %d        %-10s         %-10s      $%d       %2d/%2d/%4d\n",
               unTrabajo.id,
               descColor,
               descServicio,
               precio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio );
    }

}

int mostrarTrabajos( eTrabajo trabajos[], int tamT, eMoto lista[], int tam, eColor colores[], int tamCo, eServicio servicios[], int tamS )
{
    int todoOk = 0;
    int flag = 1;
    if ( trabajos != NULL && tamT > 0 && lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && servicios != NULL && tamS > 0 )
    {
        //system("cls");
        printf("                     ***Lista de Trabajos  ***\n");
        printf("----------------------------------------------------------------------\n");
        printf(" ID        Color Moto     Servicio         Precio         Fecha\n");
        printf("----------------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if ( !trabajos[i].isEmpty )
            {
                mostrarTrabajo( trabajos[i], lista, tam, colores, tamCo, servicios, tamS);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay trabajos para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int pedirFecha(eFecha* unaFecha)
{
    int todoOk = 0;
    int retorno;
    eFecha auxFecha;
    if (unaFecha != NULL)
    {
        printf("Ingrese fecha ( dd/mm/aaaa ): ");
        fflush(stdin);
        retorno = scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);

        while (  !( retorno == 3 &&
                    ( auxFecha.dia >= 1 && auxFecha.dia <= 31) &&
                    ( auxFecha.mes >= 1 && auxFecha.mes <= 12) &&
                    ( auxFecha.anio >= 2000 && auxFecha.anio <= 2022) ) )
        {
            printf("Error, Reingrese la fecha en el formato correcto ( dd/mm/aaaa ): ");
            fflush(stdin);
            retorno = scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        }
        *unaFecha = auxFecha;
        todoOk = 1;
    }

    return todoOk;
}
