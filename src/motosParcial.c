/*
 ============================================================================
 Name        : motosParcial.c
 Author      : Gonzalo Gagliardi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dataWarehouse.h"
#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

#define TAM 10
#define TAM_CO 5
#define TAM_T 4
#define TAM_S 4
#define TAM_TRA 10

int main(void)
{
	setbuf(stdout, NULL);

    char seguir = 's';
    char salir;
    int nextIdMoto = 100;
    int nexIdTrabajo = 50000;
    eMoto lista[TAM];
    eTrabajo trabajo[TAM_TRA];
    char seguirInforme = 's';
    char salirInforme;

    eColor colores[TAM_CO] =
    {
        { 10000, "Gris" },
        { 10001, "Negro" },
        { 10002, "Blanco" },
        { 10003, "Azul" },
        { 10004, "Rojo" }
    };

     eTipo tipos[TAM_T] =
    {
        { 1000, "Enduro" },
        { 1001, "Chopera" },
        { 1002, "Scooter" },
        { 1003, "Vintage" }
    };

     eServicio servicios[TAM_S] =
    {
        { 20000, "Limpieza", 450},
        { 20001, "Ajuste", 300 },
        { 20002, "Balanceo", 150},
        { 20003, "Cadena", 390 }
    };

    if ( !inicializarMotos(lista, TAM) )
    {
        printf("Error al inicializar motos\n");
    }

     if ( !inicializarTrabajos(trabajo, TAM_TRA) )
    {
        printf("Error al inicializar trabajos\n");
    }

    hardcodearMotos(lista, TAM, 8, &nextIdMoto);

    hardcodearTrabajos(trabajo, TAM_TRA, 4, &nexIdTrabajo);

    do
    {
        switch (menu())
        {
        case 1:
            if(!altaMoto(lista, TAM, colores, TAM_CO, tipos, TAM_T, &nextIdMoto))
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(!modificarMoto(lista, TAM, colores, TAM_CO, tipos, TAM_T))
            {
                printf("No se pudo modificar\n");
            }
            else
            {
                printf("Cambios realizados con exito\n");
            }
            break;
        case 3:
            if(!bajaMoto(lista, TAM, colores, TAM_CO, tipos, TAM_T))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 4:
            system("cls");
            if ( !mostrarMotos(lista, TAM, colores, TAM_CO, tipos, TAM_T) )
            {
                printf("No se pudo mostrar las motos\n");
            }
            else
            {
                printf("Se ordenaron con exito\n");
            }

            break;
        case 5:
            system("cls");
            if ( !mostrarTipo(tipos, TAM_T ) )
            {
                printf("No se pudo mostrar los tipos de motos\n");
            }
            break;
        case 6:
            if ( !mostrarColores(colores, TAM_CO) )
            {
                printf("No se pudo mostrar los colores\n");
            }
            break;
        case 7:
            system("cls");
            if ( !mostrarServicios(servicios, TAM_S) )
            {
                printf("No se pudieron mostrar los servicios\n");
            }
            break;
        case 8:
            if ( !altaTrabajo(trabajo, TAM_TRA, lista, TAM, colores, TAM_CO, tipos, TAM_T, servicios, TAM_S, &nexIdTrabajo ) )
            {
                printf("No se pudo realizar el alta de trabajo\n");
            }
            else
            {
                printf("Alta trabajo exitosa\n");
            }
            break;
        case 9:
                system("cls");
            if( !mostrarTrabajos(trabajo, TAM_TRA, lista, TAM, colores, TAM_CO, servicios, TAM_S))
            {
                printf("No se pudo mostrar los trabajos\n");
            }
            else
            {
                printf("Mostrar trabajo exitosa\n");
            }

            break;
        case 10:

                    do
                    {
                        switch(menuInformes())
                        {
                        case 1:
                            system("cls");
                            if ( !informarMotosColor(lista, TAM, colores, TAM_CO, tipos, TAM_T) )
                            {
                                printf("No se pudo mostrar motos por colores.\n");
                            }
                            break;
                        case 2:
                            system("cls");
                            if ( !informarMotosPromedioPuntaje( lista, TAM,  colores,  TAM_CO,tipos,  TAM_T) )
                            {
                                printf("No se pudo mostrar el porcentaje de los puntajes .\n");
                            }
                            break;
                        case 3:
                              system("cls");
                             if ( !mostrarMotoMayorCilindrada( lista, TAM,  colores,  TAM_CO,tipos,  TAM_T) )
                              	  {
                            	 	 printf("No se pudo mostrar motos por menor cilindradas .\n");
                              	  }
                          break;
                        case 4:
                                 system("cls");
                                   if ( !informarMotosPorTipo(lista, TAM, colores, TAM_CO, tipos, TAM_T) )
                                    {
                                      printf("No se pudo mostrar motos separadas por tipo\n");
                                    }
                                 break;
                        case 5:
                            system("cls");
                             	 if ( !cantMotosColorTipo(lista, TAM, colores, TAM_CO, tipos, TAM_T) )
                             	 {
                             		 printf("No se pudo mostrar cantidad de motos por tipo y color\n");
                                 }
                               break;
                        case 6:
                              	  system("cls");
                                if ( !colorMasElegido(lista, TAM,colores,TAM_CO, tipos, TAM_T) )
                                {
                                   printf("No se pudo mostrar el color mas elegido\n");
                                 }
                               break;
                        case 7:
                        		system("cls");
                             if ( !mostrarTrabajosMoto(trabajo, TAM_T,servicios,TAM_S, colores, TAM_CO, tipos, TAM_T, lista, TAM) )
                                {
                                   printf("No se pudo mostrar trabajos de motos\n");
                                 }
                                break;
                        case 8:
                               system("cls");
                        		if ( !montoTrabajosMoto(trabajo, TAM_T,servicios,TAM_S, colores, TAM_CO, tipos, TAM_T, lista, TAM) )
                        		{
                        			printf("No se pudo mostrar el informe de la suma de los servicios\n");
                        		}
                        	break;
                        case 9:
                               system("cls");
								if ( !mostrarServicioMotos(trabajo, TAM_T,servicios,TAM_S, colores, TAM_CO, tipos, TAM_T, lista, TAM) )
								{
									printf("No se pudo mostrar motos separadas por tipo\n");
								}
								break;
                        case 10:
                                system("cls");
                       			if ( !mostrarServiciosFecha(trabajo, TAM_T,servicios,TAM_S, colores, TAM_CO, tipos, TAM_T, lista, TAM) )
                       			{
                       				printf("No se pudo mostrar los servicios de la fecha\n");
                       			}
                       			break;
                        case 20:

                            printf("Esta seguro que quiere salir? (S/N)\n");
                            fflush(stdin);
                            scanf("%c", &salirInforme);
                            salirInforme = toupper(salirInforme);
                            if (salirInforme == 'S')
                            {
                                seguirInforme = 'n';
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
                    while(seguirInforme == 's');
                    break;
        case 21:
            printf("\nEsta seguro que quiere salir? (S/N)\n");
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


    return EXIT_SUCCESS;
}
