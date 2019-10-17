#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
#include "clientes.h"

#define PENDIENTE 1
#define COMPLETADO 2

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idCliente;
    int kilos;
    float hdpe;
    float ldpe;
    float pp;
    int estado;




}Pedido;



int pedido_Inicializar(Pedido array[], int size);                                    //cambiar pedido
int pedido_buscarEmpty(Pedido array[], int size);                    //cambiar pedido
int pedido_buscarById(Pedido array[], int id, int size);
int pedido_alta(Pedido arrayP[], int sizeP,int id, Cliente arrayC[],int sizeC);
int pedido_printPendiente(Pedido arrayP[], int posicion, int sizeP,Cliente arrayC[],int sizeC);
void pedido_listarPendiente(Pedido arrayP[],int sizeP, Cliente arrayC[], int sizeC);
int residuo_procesar(Pedido arrayP[], int sizeP, Cliente arrayC[],int sizeC);
int pedido_printProcesado(Pedido arrayP[],int sizeP, int posicion,Cliente arrayC[], int sizeC);
void pedido_listaProcesado(Pedido arrayP[],int sizeP, Cliente arrayC[],int sizeC);
int pedido_cantidadPorCliente(Pedido arrayP[], int sizeP, Cliente* arrayC[], int indexCliente);
int pedido_printCliente(Pedido* arrayP[], int sizeP, Cliente* arrayC[], int indexCliente, int sizeC);
void pedido_listarCliente(Pedido* arrayP[], int sizeP, Cliente* arrayC[], int sizeC);



#endif // PEDIDOS_H_INCLUDED
