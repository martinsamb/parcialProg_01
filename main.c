#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "residuos.h"


#define QTY_CLIENTE 100
#define QTY_PEDIDO 1000
#define QTY_RESIDUO 1000

int main()
{
    int opcion;
    int contadorIdCliente=0;                   //cambiar

    Cliente arrayCliente[QTY_CLIENTE];                   //cambiar
    cliente_Inicializar(arrayCliente,QTY_CLIENTE);                   //cambiar

    int contadorIdPedido=0;                   //cambiar

    Pedido arrayPedido[QTY_PEDIDO];                   //cambiar
    pedido_Inicializar(arrayPedido,QTY_PEDIDO);

        int contadorIdResiduo=0;                   //cambiar

    Residuo arrayResiduo[QTY_RESIDUO];                   //cambiar
    residuo_Inicializar(arrayResiduo,QTY_RESIDUO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                cliente_alta(arrayCliente,QTY_CLIENTE,&contadorIdCliente);                   //cambiar
                break;

            case 2: //Modificar
                cliente_modificar(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 3: //Baja
                cliente_baja(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 4://Listar
                pedido_alta(arrayPedido,QTY_PEDIDO);                   //cambiar
                break;

            case 5://Ordenar
                residuo_alta(arrayResiduo,QTY_RESIDUO);                   //cambiar
                break;

            case 6://Imprimir Clientes
                cliente_listar(arrayCliente,QTY_CLIENTE);                   //cambiar
                break;

            case 7://Imprimir pedidos pendientes
                pedido_listarPen(arrayPedido,QTY_PEDIDO);                   //cambiar
                break;

            case 8://Imprimir Pedidos Procesados
                pedido_listarPro(arrayResiduo,QTY_RESIDUO);                   //cambiar
                break;

            case 9://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=9);
    return 0;
}
