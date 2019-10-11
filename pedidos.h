#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idCliente;
    int idResiduo;
    int pPendiente;
    int pCompletado;




}Pedido;



int pedido_Inicializar(Pedido array[], int size);                                    //cambiar pedido
int pedido_buscarEmpty(Pedido array[], int size, int* posicion);                    //cambiar pedido
int pedido_buscarID(Pedido array[], int size, int valorBuscado, int* posicion);                    //cambiar pedido
int pedido_buscarInt(Pedido array[], int size, int valorBuscado, int* posicion);                    //cambiar pedido
int pedido_buscarString(Pedido array[], int size, char* valorBuscado, int* indice);                    //cambiar pedido
int pedido_alta(Pedido array[], int size, int* contadorID);                          //cambiar pedido
int pedido_baja(Pedido array[], int sizeArray);                                      //cambiar pedido
int pedido_bajaValorRepetidoInt(Pedido array[], int sizeArray, int valorBuscado);
int pedido_modificar(Pedido array[], int sizeArray);                                //cambiar pedido
int pedido_ordenarPorString(Pedido array[],int size);                              //cambiar pedido
int pedido_listar(Pedido array[], int size);                      //cambiar pedido




#endif // PEDIDOS_H_INCLUDED
