/*
 * moto.c
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"
#include "input.h"
#include "tipo.h"


int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** MOTOS ***\n");
    printf("  1- Alta Moto\n");
    printf("  2- Modificar Moto\n");
    printf("  3- Baja Moto\n");
    printf("  4- Listar Motos\n");
    printf("  5- Listar Tipos\n");
    printf("  6- Listar Colores\n");
    printf("  7- Listar Servicios\n");
    printf("  8- Alta Trabajo\n");
    printf("  9- Listar Trabajos\n");
    printf("  21- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int inicializarMotos(eMoto lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibre(eMoto lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}



int altaMoto(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[],int tamTipo, int* pId)
{
    int todoOk = 0;
    int indice;
    eMoto auxMoto;
    if (lista != NULL && tam > 0 && pId != NULL)
    {
        system("cls");
        printf("  ***Alta Moto*** \n\n");
        indice = buscarLibre(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
        	auxMoto.id = *pId;
            (*pId)++;



            mostrarColores(colores, tamCo);
            printf("\nIngrese id de Colores: ");
            scanf("%d", &auxMoto.idColor);

            mostrarTipo(tipos, tamTipo);
            printf("\nIngrese id de tipo de Moto: ");
            scanf("%d", &auxMoto.idTipo);

            pedirCadena(auxMoto.marca,"Ingrese Marca: ",  20);

            //Usar funcion para cilindradas input

            printf("\n Cilindradas: 50 - 125 - 500 - 600 - 750 ");
            printf("\nIngrese cilindradas: ");
            scanf("%d", &auxMoto.cilindradas);

            validarEntero(&auxMoto.puntaje, "\nIngrese puntaje del 1 al 10: ","\nError. Ingrese puntaje del 1 al 10: ", 1, 10, 10);


            while ( !validarIdColor(auxMoto.idColor, colores, tamCo) )
            {
                printf("Error, ingrese id de Color valido: ");
                scanf("%d", &auxMoto.idColor);
            }

            while ( !validarIdTipo(auxMoto.idTipo, tipos, tamTipo) )
            {
                printf("Error, ingrese id de tipo de avion valido: ");
                scanf("%d", &auxMoto.idColor);
            }
            auxMoto.isEmpty = 0;

            lista[indice] = auxMoto;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarMoto(eMoto lista, eColor colores[], int tamCo, eTipo tipos[], int tamTipo)
{
    char descColor[20];
    char descTipo[20];

    if (( cargarDescripcionColor( colores, tamCo, lista.idColor, descColor) == 1) &&
        (cargarDescripcionTipo(tipos, tamTipo, lista.idTipo, descTipo ) == 1) )
    {
        printf(" %d     %10s    %10s             %10s      %d		%d \n",
               lista.id,
               descColor,
               descTipo,
               lista.marca,
			   lista.cilindradas,
			   lista.puntaje);
    }

}

int mostrarMotos( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    int flag = 1;
    if ( lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 )
    {
        system("cls");
        printf("                     ***Lista de Motos  ***\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf(" ID    Colores             Tipo de Moto      Marca      Cilindradas      Puntaje     \n");
        printf("-----------------------------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                ordenarMotos(lista, tam, tipos, tamTipo);

                mostrarMoto( lista[i], colores, tamCo, tipos, tamTipo );
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay moto para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}


int ordenarMotos(eMoto lista[], int tam, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    eMoto auxMoto;
    char descrTipo1[20];
    char descrTipo2[20];

    if (lista != NULL && tam >0)
    {
        for (int i = 0; i < tam -1; i++)
        {
            for (int j = i+1; j < tam; j++)
            {
                cargarDescripcionTipo(tipos, tamTipo, lista[i].idTipo, descrTipo1);
                cargarDescripcionTipo(tipos, tamTipo, lista[j].idTipo, descrTipo2);

                if( (strcmp(descrTipo1, descrTipo2) > 0) || (strcmp(descrTipo1, descrTipo2) == 0 && lista[i].id > lista[j].id) )
                {
                	auxMoto = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMoto;
                }
            }
        }
    }

  return todoOk;
}

int bajaMoto( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if ( lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 )
    {
        system("cls");
        printf("   *** Baja Moto *** \n\n");
        mostrarMotos(lista, tam, colores, tamCo, tipos, tamTipo);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMotoId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMoto(lista[indice], colores, tamCo, tipos, tamTipo );
            printf("Confirma baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}



int buscarMotoId( eMoto lista[], int tam, int Id )
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == Id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int modificarMoto( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eMoto auxMoto;

    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("   *** Modificar Avion *** \n\n");
        mostrarMotos(lista, tam, colores, tamCo, tipos, tamTipo);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMotoId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(lista, tam, indice, colores, tamCo, tipos, tamTipo) )
                {
                case 1:

                    mostrarColores(colores, tamCo);
                    if ( !validarEntero(&auxMoto.idColor, "Modificar id colores: ", "Error, ingrese un id de colores valido.\n ", colores[0].id, colores[tamCo-1].id, 10)  )
                    {
                        printf("\nError al ingresar id de colores, id ingresado por default: %d\n", colores[0].id);
                        auxMoto.idTipo = colores[0].id;

                    }
                    printf("Confirma cambio de id tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].idColor = auxMoto.idColor;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:




                    if ( !validarEntero(&auxMoto.puntaje, "\nPuntaje del 1 al 10\nIngrese Puntaje de la Moto: ", "Error, ingrese un Puntaje de la Moto valido.\n ",1, 10, 10)  )
                    {
                        printf("\nError al ingresar Puntaje de la Moto, Puntaje por default: %d\n", 8);
                        auxMoto.puntaje = tipos[0].id;
                    }

                    printf("Confirma cambio de puntaje? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].puntaje = auxMoto.puntaje;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 10:
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }
                system("pause");
            }
            while(seguir == 's');

            todoOk = 1;
        }
    }
    return todoOk;
}



int menuModificar( eMoto lista[], int tam, int indice, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int opcion = 0;
    system("cls");
    printf("------------------------------------------------------------\n");
    mostrarMoto(lista[indice], colores, tamCo, tipos, tamTipo );
    printf("------------------------------------------------------------\n");
    printf("1- Editar Color\n");
    printf("2- Editar Puntaje\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
   // system("pause");
    //printf("\n");
    return opcion;
}

int cargarColorMoto( eMoto lista[], int tam, eColor colores[], int tamCo, int idmoto, char color[] )
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && color != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idmoto)
            {
                cargarDescripcionColor(colores, tamCo, lista[i].idColor, descripcion);
                strcpy(color, descripcion);
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

int validarBicicletaId( eMoto lista[], int tam, int id )
{
    int esValido = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty == 0 && id == lista[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


