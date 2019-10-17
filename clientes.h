#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#define TEXT_CLIENT 100
#define TEXT_NAME 70
#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombreEmpresa[TEXT_CLIENT];
    int cuit[TEXT_SIZE];
    char direccion[TEXT_NAME];
    char localidad[TEXT_NAME];

}Cliente;




int cliente_Inicializar(Cliente array[], int size);                                    //cambiar cliente
int cliente_buscarEmpty(Cliente array[], int size, int* posicion);                    //cambiar cliente
int cliente_buscarById(Cliente array[], int id, int size);                    //cambiar cliente
//int cliente_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion);                    //cambiar cliente
//int cliente_buscarString(Cliente array[], int size, char* valorBuscado, int* indice);                    //cambiar cliente
int cliente_alta(Cliente array[], int size, int* contadorID);                          //cambiar cliente
int cliente_baja(Cliente array[], int sizeArray);                                      //cambiar cliente
//int cliente_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado);
int cliente_modificar(Cliente array[], int sizeArray);                                //cambiar cliente
//int cliente_ordenarPorString(Cliente array[],int size);                              //cambiar cliente
int cliente_listar(Cliente array[], int size);                      //cambiar cliente
int cliente_print(Cliente array[], int posicion,int size);




#endif // CLIENTES_H_INCLUDED
