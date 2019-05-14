#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
#define MAX_CARACTER 30

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[MAX_CARACTER];
    char apellido[MAX_CARACTER];
    int auxInt;
    float auxFloat;
    char auxChar;
    char sexo;
    char telefono[MAX_CARACTER];
    char mail[MAX_CARACTER];
    char DNI[MAX_CARACTER];

}Fantasma;


#endif /// FANTASMA_H_INCLUDED

int fantasma_Inicializar(Fantasma* array, int limite);         ///cambiar fantasma
int fantasma_buscarEmpty(Fantasma* array, int limite, int* posicion);      ///cambiar fantasma
int fantasma_buscarID(Fantasma* array, int limite, int valorBuscado, int* posicion);    ///cambiar fantasma
int fantasma_buscarInt(Fantasma* array, int limite, int valorBuscado, int* posicion);    ///cambiar fantasma
int fantasma_buscarString(Fantasma* array, int limite, char* valorBuscado, int* indice);   ///cambiar fantasma
int fantasma_alta(Fantasma* array, int limite, int* contadorID);                     ///cambiar fantasma
int fantasma_baja(Fantasma* array, int limite);                                 ///cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma* array, int limite, int valorBuscado);
int fantasma_modificar(Fantasma* array, int limite);                               ///cambiar fantasma
int fantasma_ordenarPorDobleCriterio(Fantasma* array,int limite, int orderFirst, int orderSecond);                                  //cambiar fantasma
int fantasma_listar(Fantasma array[], int limite);                      ///cambiar fantasma

