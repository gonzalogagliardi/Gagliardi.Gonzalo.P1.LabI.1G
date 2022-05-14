/*
 * DataWarehouse.h
 *
 *  Created on: 13 may. 2022
 *      Author: NBGonza
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_

#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "trabajo.h"


int hardcodearMotos( eMoto lista[], int tam, int cant, int* pId );

int hardcodearTrabajos( eTrabajo trabajo[], int tamT, int cant, int* pId );

#endif /* DATAWAREHOUSE_H_ */
