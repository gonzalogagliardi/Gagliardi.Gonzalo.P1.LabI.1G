/*
 * DataWarehouse.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "fecha.h"
#include "moto.h"



//char capacidad[10] = { 26, 20, 27.5, 29, 29, 26, 40, 35, 27.5, 20 };

int idColor[10] = { 10000, 10002, 10001, 10002, 10000, 10001, 10003, 10000, 10002, 10003};

int idTipo[10] = { 1000, 1003, 1001, 1000, 1002, 1001, 1002, 1000, 1001, 1001};

char marcas[10][20] = { "Honda", "Suzuki", "Kawasaki", "Yamaha", "Ducati", "Yamaha", "Suzuki" , "Torrot", "Kawasaki" , "Kawasaki"};

int cilindradas[10] = {50, 125, 500, 600, 750, 500, 125, 125, 600, 750};

int puntaje[10] = { 6 , 8 , 9 ,8, 2, 7, 8, 5, 7, 10};

int hardcodearMotos( eMoto lista[], int tam, int cant, int* pId )
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idColor = idColor[i];
            lista[i].idTipo = idTipo[i];
            lista[i].cilindradas = cilindradas[i];
            lista[i].puntaje = puntaje[i];

            strcpy(lista[i].marca, marcas[i]);
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}


int idMoto[10] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

int idServicio[10] = { 20000, 20001, 20002, 20003, 20002, 20001, 20002, 20000, 20003, 20000};

int fechasDia[10] =  {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

int fechasMes[10] = {02, 02, 02, 02, 02, 02, 02, 02, 02, 02};

int fechasAnio[10] = {2020, 2022, 2021, 2019, 2022, 2018, 2017, 2019, 2018, 2021};



int hardcodearTrabajos( eTrabajo trabajos[], int tamT, int cant, int* pId )
{
    int contador = -1;
    if (trabajos != NULL && tamT > 0 && cant >= 0 && cant <= tamT && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	trabajos[i].id = *pId;
            (*pId)++;
            trabajos[i].idMoto = idMoto[i];
            trabajos[i].idServicio = idServicio[i];
            trabajos[i].fecha.dia = fechasDia[i];
            trabajos[i].fecha.mes = fechasMes[i];
            trabajos[i].fecha.anio = fechasAnio[i];
            trabajos[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
