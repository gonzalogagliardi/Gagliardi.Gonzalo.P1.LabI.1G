/*
 * informes.c
 *
 *  Created on: 17 may. 2022
 *      Author: NBGonza
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "input.h"
#include "moto.h"

int menuInformes()
{
	  int opcion = 0;
	    system("cls");
	    printf("     *** Informes Motos ***\n");
	    printf("  1- Mostrar motos del color seleccionado por el usuario.\n");
	    printf("  2- Informar el promedio de puntaje de un tipo seleccionado por el usuario.\n");
	    printf("  3- Informar la o las motos de mayor cilindradas.\n");
	    printf("  4- Mostrar un listado de las motos separadas por tipo\n");
	    printf("  5- Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo\n");
	    printf("  6- Mostrar el o los colores más elegidos por los clientes.\n");
	    printf("  7- Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.\n");
	    printf("  8- Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la misma\n");
	    printf("  9- Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.\n");
	    printf("  10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
	    printf("  20- Salir\n");
	    printf("Ingrese opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);
	    //printf("\n");
	    return opcion;
}

int informarMotosColor( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
	int todoOk = 0;
	    int idColor;

	    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
	    {
	        system("cls");
	        printf("            ***   Motos por Color  ***\n");
	        printf("------------------------------------------------------------\n");

	        mostrarColores(colores, tamCo);

	        if ( !validarEntero(&idColor, "Ingrese id de Color: ", "Error, ingrese un id de Color valido.\n ", colores[0].id, colores[tamCo-1].id, 10)  )
	        {
	            printf("\nError al ingresar id de Color, id ingresado por default: %d\n", colores[0].id);
	            idColor = colores[0].id;

	        }

	        informarMotosIdColor(idColor, lista, tam, colores, tamCo, tipos, tamTipo);

	        todoOk = 1;
	    }
	    return todoOk;

}



int informarMotosIdColor( int idColor, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    int flag = 1;
    char descColor[20];

    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 )
    {
        printf(" ID    Colores            Servicio      ///Marca	Cilindradas		Puntaje///     \n");
        printf("-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !lista[i].isEmpty && lista[i].idColor == idColor)
            {
                mostrarMoto(lista[i], colores, tamCo, tipos, tamTipo);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionColor(colores, tamCo, idColor, descColor);
            printf("   No hay motos del color %s.\n", descColor);
        }
        todoOk = 1;
    }
    return todoOk;
}


int informarMotosPromedioPuntaje( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int idTipo;
    int contTotal = 0;
    int acumulador = 0;
    float porcentaje = 0;
    int flag = 1;

    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("            ***   Motos por tipo   ***\n");
        printf("------------------------------------------------------------\n");

        mostrarTipo(tipos, tamTipo);

        if ( !validarEntero(&idTipo, "Ingrese id de tipo de moto: ", "Error, ingrese un id de tipo de moto valido.\n ", tipos[0].id, tipos[tamTipo-1].id, 10)  )
        {
            printf("\nError al ingresar id de tipo de moto, id ingresado por default: %d\n", tipos[0].id);
            idTipo = tipos[0].id;
        }


        for (int i = 0; i < tam; i++)
               {
                   if (!lista[i].isEmpty && lista[i].idTipo == idTipo)
                   {
                       contTotal++;
                       if ( lista[i].puntaje )
                       {
                    	   acumulador+=lista[i].puntaje;

                       }
                       flag = 0;
                   }
               }
               if (!flag)
               {
                   printf("\n");

                   porcentaje = (float) acumulador /contTotal  ;
                   printf("El promedio de puntaje es de %.2f \n",  porcentaje);

                   printf("\n");
               }
               else
               {
                   printf("No hay micros VIP en esta empresa.\n");

               }


        todoOk = 1;
    }
    return todoOk;
}

int informarMotosIdTipo( int idTipo, eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;
    int flag = 1;
    char descTipo[20];
    if (lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 )
    {
        printf(" ID    Colores             Tipo de Moto      Marca	Cilindradas		Puntaje   \n");
        printf("-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !lista[i].isEmpty && lista[i].idTipo == idTipo)
            {
                mostrarMoto(lista[i], colores, tamCo, tipos, tamTipo);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionTipo(tipos, tamTipo, idTipo, descTipo);
            printf("   No hay motos del tipo  %s.\n", descTipo);
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMotoMayorCilindrada(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    float maximo;
    int flagMin = 1;
    if(lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        for(int i = 0 ; i < tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(flagMin || lista[i].cilindradas > maximo)
                {
                	maximo = lista[i].cilindradas;
                    flagMin = 0;
                }
            }
        }
        printf(" 					 *** Moto/s con mas cilindradas ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID    Colores             Tipo de Moto      Marca	Cilindradas	 Puntaje   \n\n");
        printf("---------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].cilindradas == maximo)
            {

                mostrarMoto(lista[i],colores,tamCo,tipos,tamTipo);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int informarMotosPorTipo( eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo )
{
    int todoOk = 0;

    if ( lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 )
    {
        system("cls");
        printf("               ***  Motos por Tipo  ***\n");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < tamTipo; i++)
        {
            printf("\n");
            printf("Tipo: %s\n", tipos[i].descripcion);
            informarMotosIdTipo( tipos[i].id, lista, tam, colores, tamCo, tipos, tamTipo );

            printf("\n------------------------------------------------------------\n");
        }

        todoOk = 1;
    }
    return todoOk;
}



int cantMotosColorTipo(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int contador = 0;
    int idColor;
    int idTipo;
    char descTipo[20];
    char descColor[20];

    if(lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
    {

    mostrarTipo(tipos, tamTipo);

    if ( !validarEntero(&idTipo, "Ingrese id de tipo de moto: ", "Error, ingrese un id de tipo de moto valido.\n ", tipos[0].id, tipos[tamTipo-1].id, 10)  )
    {
    	  printf("\nError al ingresar id de tipo de moto, id ingresado por default: %d\n", tipos[0].id);
    	  idTipo = tipos[0].id;
    }




        printf("------------------------------------------------------------\n");



        mostrarColores(colores, tamCo);
        printf("------------------------------------------------------------\n");


       	if ( !validarEntero(&idColor, "Ingrese id de Color: ", "Error, ingrese un id de Color valido.\n ", colores[0].id, colores[tamCo-1].id, 10)  )
       	 {
       	   printf("\nError al ingresar id de Color, id ingresado por default: %d\n", colores[0].id);
       	   idColor = colores[0].id;

       	 }


        cargarDescripcionColor(colores,tamCo,idColor,descColor);
        cargarDescripcionTipo(tipos,tamTipo,idTipo,descTipo);
        system("cls");
        printf("      *** Cantidad de Motos de cada tipo y marca***\n");
        printf(" ID    Colores             Tipo de Moto      Marca	Cilindradas	 Puntaje   \n");
        printf("**********************************************************************************\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idColor == idColor && lista[i].idTipo == idTipo)
            {
                contador++;
                mostrarMoto(lista[i],colores,tamCo,tipos,tamTipo);
            }
        }
        if(contador == 0)
        {
            printf("\nNo hay motos de tipo %s y de color %s para mostrar\n",descTipo, descColor);
        }
        else
        {
            printf("\nHay %d motos de tipo %s y de color %s\n", contador, descTipo, descColor);
        }
        todoOk = 1;
    }
    return todoOk;
}



//----> ACOMODAR: No deja elegir para poner el id de la moto, entonces se carga solo cualquier ID <----- ACOMODAR FUNCION VALIDAR ENTERO POR OTRA
int mostrarTrabajosMoto(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    int idMoto;
    if(trabajos != NULL &&  tamT > 0 && servicios != NULL && tamS
            > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 && lista != NULL && tam > 0)
    {
        mostrarMotos(lista,tam,colores,tamCo,tipos,tamTipo);
        idMoto = pedirEntero("Ingresa el id de la moto : ");

        	while(!validarMotoId(lista,tam,idMoto))
                {
                    printf("Error, ingrese un id valido  \n");
                    idMoto = pedirEntero("Ingresa el id de la moto : ");
                }



        system("cls");
        printf("       *** Listado de Trabajos de una Moto ***      \n");
        printf("*******************************************************************************************************************************************\n");
        printf("ID TRABAJO       COLOR          SERVICIO         PRECIO        FECHA       \n");
        printf("*******************************************************************************************************************************************\n");
        for(int i = 0; i < tamT ; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto)
            {
                mostrarTrabajo(trabajos[i],lista,tam,colores,tamCo,servicios,tamS);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay trabajos para mostrar de esta moto \n");
        }

        todoOk = 1;
    }

    return todoOk;
}


int colorMasElegido(eMoto lista[], int tam, eColor colores[], int tamCo, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int contadores[tamCo];
    int flag = 1;
    int mayorCantidad;
    for (int i = 0; i < tamCo; i++)
    {
        contadores[i] = 0;
    }
    if(lista != NULL && tam > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0)
    {
        system("cls");
        printf("               *** Color mas elegido ***\n");
        for (int i = 0; i < tamCo; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (lista[j].isEmpty  == 0 && colores[i].id == lista[j].idColor)
                {
                    contadores[i]++;
                }
            }
        }

        for (int i = 0; i < tamCo; i++)
        {
            if (flag || contadores[i] > mayorCantidad)
            {
                mayorCantidad = contadores[i];
                flag = 0;
            }
        }
        for (int i = 0; i < tamCo; i++)
        {
            if (contadores[i] == mayorCantidad)
            {
                printf("El color mas elegido es : %s\n", colores[i].descripcion);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


int montoTrabajosMoto(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    int idMoto;
    int acumulador = 0;
    if(trabajos != NULL &&  tamT > 0 && servicios != NULL && tamS
            > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 && lista != NULL && tam > 0)
    {

    	mostrarMotos(lista,tam,colores,tamCo,tipos,tamTipo);
    	idMoto = pedirEntero("Ingresa el id de la moto : ");

    	while(!validarMotoId(lista,tam,idMoto))
    	{
    	   printf("Error, ingrese un id valido  \n");
    	   idMoto = pedirEntero("Ingresa el id de la moto : ");
    	}


        system("cls");
        printf("       *** Listado de Trabajos realizados de una Moto ***      \n");
        printf("******************************************************************************\n");
        printf("ID TRABAJO       COLOR          SERVICIO         PRECIO        FECHA       \n");
        printf("******************************************************************************\n");
        for(int i = 0; i < tamT; i++)
        {
            for(int j = 0; j < tamS ; j++)
            {
                if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto &&  trabajos[i].idServicio == servicios[j].id)
                {
                    acumulador += servicios[j].precio;//
                    mostrarTrabajo(trabajos[i],lista,tam,colores,tamCo,servicios,tamS);

                    flag = 0;
                }
            }
        }
        if(flag)
        {
            printf("No hay trabajos para mostrar de esta moto \n");
        }
        else
        {
            printf("\nLa suma de los importes de los servicios que recibio la moto es: $%d\n", acumulador);
        }

        todoOk = 1;
    }
    return todoOk;
}



int mostrarServicioMotos(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam)
{
    int todoOk = 0;
    int idServicio;
    int flag = 1;

    if(trabajos != NULL &&  tamT > 0 && servicios != NULL && tamS
            > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("        *** Listado de  Motos por servicios ***                      \n");
        printf("--------------------------------------------------------------------------------\n");

        mostrarServicios(servicios, tamS);
        idServicio = pedirEntero("Ingresar id del servicio : ");

        printf("*******************************************************************************************************************************************\n");
        printf("ID TRABAJO       COLOR          SERVICIO         PRECIO        FECHA       \n");
        printf("*******************************************************************************************************************************************\n");
        for(int i = 0; i < tamT; i++)
        {
            if(trabajos[i].idServicio == idServicio && trabajos[i].isEmpty == 0)
            {
            	mostrarTrabajo(trabajos[i],lista,tam,colores,tamCo,servicios,tamS);

                flag = 0;

            }
        }

        if(flag)
        {
            printf("No hay servicios para mostrar.\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


int mostrarServiciosFecha(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,
                          eColor colores[],int tamCo, eTipo tipos[], int tamTipo, eMoto lista[], int tam)
{
    int todoOk = 0;
    char descripcion[25];
    //int precio;
    int indiceMoto;
    int flag = 1;
    eTrabajo auxTrabajo;
    eFecha auxFecha;
    int contador = 0;


    if(trabajos != NULL &&  tamT > 0 && servicios != NULL && tamS
            > 0 && colores != NULL && tamCo > 0 && tipos != NULL && tamTipo > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("               *** Listado Servicios por fecha ***                      \n");
        printf("******************************************************************************\n");

        pedirFecha(&auxFecha);

        auxTrabajo.fecha = auxFecha;



        printf("*****************************\n");
        printf("\nSERVICIO     	  FECHA\n");
        printf("*****************************\n");

        for(int i = 0; i < tamT; i++)
        {
        	indiceMoto = buscarMotoId(lista, tam, trabajos[i].idMoto);
            if(trabajos[i].fecha.dia == auxTrabajo.fecha.dia && trabajos[i].fecha.mes == auxTrabajo.fecha.mes && trabajos[i].fecha.anio == auxTrabajo.fecha.anio && trabajos[i].isEmpty == 0 && !lista[indiceMoto].isEmpty)
            {
            	cargarDescripcionServicio(servicios,  tamS, trabajos[i].idServicio,descripcion );
                contador++;
                printf("%s          %02d/%02d/%04d\n",descripcion, auxTrabajo.fecha.dia, auxTrabajo.fecha.mes, auxTrabajo.fecha.anio);
                flag = 0;
            }
        }

        if(flag)
        {
            printf("No hay servicios para mostrar en la fecha.\n");
        }
        else
        {
            printf("En la fecha se realizaron %d servicio.\n",contador);
        }

        todoOk = 1;
    }
    return todoOk;
}
