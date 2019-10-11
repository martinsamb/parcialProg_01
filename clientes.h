#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int cuit;
    char direccion[TEXT_SIZE];
    char localidad[TEXT_SIZE];
    int cantidadKg;

}Cliente;




int fantasma_Inicializar(Fantasma array[], int size);                                    //cambiar fantasma
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion);                    //cambiar fantasma
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int fantasma_alta(Fantasma array[], int size, int* contadorID);                          //cambiar fantasma
int fantasma_baja(Fantasma array[], int sizeArray);                                      //cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int sizeArray);                                //cambiar fantasma
int fantasma_ordenarPorString(Fantasma array[],int size);                              //cambiar fantasma
int fantasma_listar(Fantasma array[], int size);                      //cambiar fantasma




#endif // CLIENTES_H_INCLUDED
