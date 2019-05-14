#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fantasma.h"  //cambiar por nombre entidad
#include "funcionesUTN.h"
#include "misValid.h"
#define LIMITE_ARRAY 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;                   ///cambiar

    Fantasma arrayFantasma[LIMITE_ARRAY];                   ///cambiar
    fantasma_Inicializar(arrayFantasma,LIMITE_ARRAY);                   ///cambiar

    //*******************************************************************
    arrayFantasma[0].idUnico=0;
    arrayFantasma[0].isEmpty=0;
    arrayFantasma[0].auxInt=0;
    arrayFantasma[0].auxFloat=0;
    strcpy(arrayFantasma[0].apellido,"AAAAA");
    strcpy(arrayFantasma[0].nombre,"AAAA");
    contadorIdfantasma++;

    arrayFantasma[1].idUnico=1;
    arrayFantasma[1].isEmpty=0;
    arrayFantasma[1].auxInt=0;
    arrayFantasma[1].auxFloat=0;
    strcpy(arrayFantasma[1].apellido,"BBBBB");
    strcpy(arrayFantasma[1].nombre,"BB");
    contadorIdfantasma++;

    arrayFantasma[2].idUnico=2;
    arrayFantasma[2].isEmpty=0;
    arrayFantasma[2].auxInt=0;
    arrayFantasma[2].auxFloat=20;
    strcpy(arrayFantasma[2].apellido,"CCCCCC");
    strcpy(arrayFantasma[2].nombre,"CCC");
    contadorIdfantasma++;

    arrayFantasma[3].idUnico=3;
    arrayFantasma[3].isEmpty=0;
    arrayFantasma[3].auxInt=0;
    arrayFantasma[3].auxFloat=10;
    strcpy(arrayFantasma[3].apellido,"DDDDDD");
    strcpy(arrayFantasma[3].nombre,"DDD");
    contadorIdfantasma++;

    fantasma_listar(arrayFantasma,LIMITE_ARRAY);
    //********************************************************************

    do
    {
        getInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",sizeof(int),1,1,&opcion);
         system("clear");
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma,LIMITE_ARRAY,&contadorIdfantasma);                   //cambiar
                break;

            case 2: ///Modificar
                fantasma_modificar(arrayFantasma,LIMITE_ARRAY);                   //cambiar
                break;

            case 3: ///Baja
                fantasma_baja(arrayFantasma,LIMITE_ARRAY);                   //cambiar
                break;

            case 4:///Listar
                fantasma_listar(arrayFantasma,LIMITE_ARRAY);                   //cambiar
                break;

            case 5:///Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,LIMITE_ARRAY,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6:///Salir
                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }
    while(opcion!=6);
    return 0;
}
