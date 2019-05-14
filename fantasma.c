#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
#include "misValid.h"
#include "fantasma.h" ///cambiar por nombre entidad
#define  CANT_DIG_MIN   1
#define  CANT_DIG_MAX   50
#define SALARIO_MAXIMO 100000
#define SALARIO_MINIMO 100
#define MIN_CARACTER 1

/** \brief  Inicializa todo el array en 1
* \param array fantasma Array of fantasma
* \param limite tamaño del array
* \return int Retorna (-1) si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int fantasma_Inicializar(Fantasma* array, int limite)
{
    int retorno=-1;
    if(array!= NULL && limite>0)
    {
        for(;limite>0;limite--)
        {
            array[limite-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma* array, int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma* array, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma* array, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].auxInt==valorBuscado)   ///cambiar campo auxInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma* array, int limite, char* valorBuscado, int* indice)
{                                   ///Busca por nombre o apellido (por String)
    int retorno=-1;
    int i;
    if(array!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma* array, int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && limite>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            getName("\nIngrese nombre: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,array[posicion].nombre);           //mensaje + cambiar campo varInt
            getApellido("\nIngrese apellido: ","\nApellido invalido",MAX_CARACTER,MIN_CARACTER,2,array[posicion].apellido);             //mensaje + cambiar campo varFloat
            getFloat("\nIngrese salario: ","\nSalario invalido",SALARIO_MAXIMO,SALARIO_MINIMO,2,&array[posicion].auxFloat);                      //mensaje + cambiar campo varString
            getSexo("\nIngrese sexo F o M: ","\nSexo invalido",CANT_DIG_MAX,CANT_DIG_MIN,2,&array[posicion].auxChar); //mensaje + cambiar campo varLongString
            getTelefono("\nIngrese telefono: ","Telefono invalido",MAX_CARACTER,MIN_CARACTER,2,array[posicion].telefono);
            getMail("\nIngrese Mail: ","\nMail invalido",MAX_CARACTER,MIN_CARACTER,2,array[posicion].mail);
            printf("\n Posicion: %d\n ID: %d\n auxInt: %d\n auxFloat: %f\n Nombre: %s\n Apellido: %s\n Telefono: %s\n Mail: %s",
                   posicion, array[posicion].idUnico,array[posicion].auxInt,array[posicion].auxFloat,array[posicion].nombre,
                   array[posicion].apellido,array[posicion].telefono,array[posicion].mail);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma* array, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && limite>0)
    {
        getInt("\nIngrese ID a cancelar: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,2,&id); ///cambiar si no se busca por ID
        if(fantasma_buscarID(array,limite,id,&posicion)==-1)         ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");  ///cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;            ///cambiar campo id
            array[posicion].auxInt=0;             ///cambiar campo auxInt
            array[posicion].auxFloat=0;           ///cambiar campo auxFloar
            strcpy(array[posicion].nombre,"");    ///cambiar campo nombre
            strcpy(array[posicion].apellido,"");  ///cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma* array, int limite, int valorBuscado)
///cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].idUnico==valorBuscado)    ///cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                ///cambiar campo id
                array[i].auxInt=0;                 ///cambiar campo varInt
                array[i].auxFloat=0;               ///cambiar campo varFloat
                strcpy(array[i].nombre,"");     ///cambiar campo nombre
                strcpy(array[i].apellido,""); ///cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma* array, int limite)
{
    int retorno=-1;
    int posicion;
    int id;      ///cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && limite>0)
    {
        getInt("\nIngrese ID a modificar: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,2,&id); ///cambiar si no se busca por ID
        if(fantasma_buscarID(array,limite,id,&posicion)==-1)  ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");///cambiar si no se busca por ID
        }
        else
        {
            do
            {       ///copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n auxInt: %d\n auxFloat: %f\n Nombre: %s\n Apellido: %s\n",
                   posicion, array[posicion].idUnico,array[posicion].auxInt,array[posicion].auxFloat,array[posicion].nombre,array[posicion].apellido);
                getInt("\nModificar:\n 1-Int\n 2-Float\n 3-Nombre\n 4-Apelldio\n 5(salir)\n","\nError",CANT_DIG_MAX,CANT_DIG_MIN,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        getInt("\nIngrese...: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,1,&array[posicion].auxInt);           //mensaje + cambiar campo varInt
                        break;
                    case 2:
                        getFloat("\nINgrese...: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,1,&array[posicion].auxFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 3:
                        getName("\nIngrese....: ","\nError",MAX_CARACTER,MIN_CARACTER,1,array[posicion].nombre);                      //mensaje + cambiar campo varString
                        break;
                    case 4:
                        getApellido("\nIngrese...: ","\nError",MAX_CARACTER,MIN_CARACTER,1,array[posicion].apellido);             //mensaje + cambiar campo varLongString
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=5);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorDobleCriterio(Fantasma* array,int limite, int orderFirst, int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Fantasma buffer;
    int flagSwap;

    if(array!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < limite-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].auxFloat < array[i+1].auxFloat) && orderSecond) ||
                        ((array[i].auxFloat > array[i+1].auxFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma* array, int limite)
{
    int retorno=-1;
    int i;
    if(array!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n auxInt: %d\n auxFloat: %f\n nombre: %s\n apellido: %s",
                       array[i].idUnico,array[i].auxInt,array[i].auxFloat,array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}


