#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedidos.h"
#include "clientes.h"
#include "residuos.h"


#define QTY_CLIENTE 100
#define QTY_PEDIDO 1000

int cargarDatos(Cliente arrayCliente[], Pedido arrayPedido[], int *contadorIdCliente, int *contadorIdPedido);

int main()
{
    int opcion;
    int index;
    int flag1=0;
    int flag2=0;
    int clienteID=1;
    int pedidoID=1;

    int contadorIdCliente=0;                   //cambiar

    Cliente arrayCliente[QTY_CLIENTE];                   //cambiar
    cliente_Inicializar(arrayCliente,QTY_CLIENTE);                   //cambiar

    int contadorIdPedido=0;                   //cambiar

    Pedido arrayPedido[QTY_PEDIDO];                   //cambiar
    pedido_Inicializar(arrayPedido,QTY_PEDIDO);

    cargarDatos(arrayCliente,arrayPedido,&contadorIdCliente,&contadorIdPedido);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Cliente \n2) Modificar Cliente \n3) Baja Cliente \n4) Pedido recoleccion \n5) Procesar Residuos \n6) Imprimir Clientes\n7)Imprimir Pedidos Pendientes \n8)Imprimir Pedidos procesados \n9) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                if(cliente_alta(arrayCliente,QTY_CLIENTE,&contadorIdCliente)==-1)
                {
                    printf("\nError en el alta del cliente\n");
                }
                else
                {
                    index=cliente_buscarById(arrayCliente,clienteID,QTY_CLIENTE);
                    printf("\n Alta exitosa\n");
                    cliente_print(arrayCliente,index,QTY_CLIENTE);
                    clienteID++;
                    flag1=1;
                }
                break;

            case 2: //Modificar
                if(flag1==1)
                {
                    if(cliente_modificar(arrayCliente,QTY_CLIENTE)==-1)
                        printf("\n Error en la modificacion\n");
                    else
                    {
                        printf("\nNo hay datos cargados en el alta\n");
                    }
                }
                break;

            case 3: //Baja
                if(flag1==1)
                {
                    if(cliente_baja(arrayCliente,QTY_CLIENTE)==-1)
                    {
                        printf("\Error en la baja\n");
                    }
                    else
                    {
                        printf("\nNo hay datos cargados en el alta\n");
                    }
                }
                break;

            case 4://Listar
                if(flag1==0)
                {
                    printf("\nNo se guardo ningun cliente\n");
                    break;
                }
                if(pedido_alta(arrayPedido,QTY_PEDIDO,pedidoID,arrayCliente,QTY_CLIENTE)==-1)
                {
                    printf("\nError en el alta del cliente\n");
                }
                else
                {
                    printf("\nAlta exitosa\n");
                    pedidoID++;
                    flag2=1;
                }
                break;

            case 5://Ordenar
                if(flag2==1)
                {
                    if(residuo_procesar(arrayPedido,QTY_PEDIDO,arrayCliente,QTY_CLIENTE)==-1)
                    {
                        printf("\nError en la modificacion\n");
                    }
                    else
                    {
                        printf("\nProceso realizado exitosamente\n");
                    }
                }
                else
                {
                    printf("\nNo hay datos cargados en el alta\n");
                }
                break;

            case 6://
                if(flag1==1)
                {
                    pedido_listarCliente(arrayPedido,QTY_PEDIDO,arrayCliente,QTY_CLIENTE);
                }
                else
                {
                    printf("\nNo hay datos cargados en el alta\n");
                }
                break;

            case 7:
                if(flag2==1)
                {
                    pedido_listarPendiente(arrayPedido,QTY_PEDIDO,arrayCliente,QTY_CLIENTE);
                }
                else
                {
                    printf("\nNo hay datos cargados en el alta\n");
                }
                break;

            case 8:
                if(flag2==1)
                {
                    pedido_listaProcesado(arrayPedido,QTY_PEDIDO,arrayCliente,QTY_CLIENTE);
                }
                else
                {
                    printf("\nNo hay datos cargados en el alta\n");
                }
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

int cargarDatos(Cliente arrayCliente[], Pedido arrayPedido[], int *contadorIdCliente, int *contadorIdPedido)
{
    int i=0;
    //Clientes
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    //arrayCliente[i].cuit=202086534-5000;
    strcpy(arrayCliente[i].nombreEmpresa,"Ford");
    strcpy(arrayCliente[i].direccion,"Soler 456");
    strcpy(arrayCliente[i].localidad,"Martinez");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    //arrayCliente[i].cuit=20-2123452300;
    strcpy(arrayCliente[i].nombreEmpresa,"Pepsi");
    strcpy(arrayCliente[i].direccion,"Salta 456");
    strcpy(arrayCliente[i].localidad,"Avellaneda");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    //arrayCliente[i].cuit=20-22234523-0;
    strcpy(arrayCliente[i].nombreEmpresa,"Arcor");
    strcpy(arrayCliente[i].direccion,"Solis 456");
    strcpy(arrayCliente[i].localidad,"Martinez");
    (*contadorIdCliente)++;
    i++;

    //int i=0;
    //Pedido
    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=0;
    arrayPedido[i].estado=0;
    arrayPedido[i].hdpe=15.5;
    arrayPedido[i].ldpe=20,5;
    arrayPedido[i].pp=25,5;
    arrayPedido[i].kilos= 100;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].hdpe=18.5;
    arrayPedido[i].ldpe=23,5;
    arrayPedido[i].pp=28,5;
    arrayPedido[i].kilos= 130;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=0;
    arrayPedido[i].estado=0;
    arrayPedido[i].hdpe=21.5;
    arrayPedido[i].ldpe=26,5;
    arrayPedido[i].pp=31,5;
    arrayPedido[i].kilos= 160;
    (*contadorIdPedido)++;
    i++;

    return 0;
}
