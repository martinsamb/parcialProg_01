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
    int opcion1;
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
        utn_getUnsignedInt("\n\n1) Alta Cliente \n2) Modificar Cliente \n3) Baja Cliente \n4) Pedido recoleccion \n5) Procesar Residuos \n6) Imprimir Clientes\n7)Imprimir Pedidos Pendientes \n8)Imprimir Pedidos procesados \n9) Informes \n10) Salir\n",                   //cambiar
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

            case 9:
                do
                {
                    utn_getUnsignedInt("\n\n1) Cliente Pedidos Pendintes \n2) Clientes Pedidos Completados \n3) Clientes con mas Pedidos \n4) Clientes mas Kilos \n5) Clientes menos kilos \n6)Clientes masMilKg\n7)Cliente masCienKg \n8)Imprimir Pedidos Completados \n9) Pedidos por localidad \n10) Cantidad Kg PP\n11) Cuit Cliente kilosTotales\n11)Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion1);
                    switch(opcionI)
                    {
                        case 1://
                                cliente_masPedidosPendientes(arrayCliente,QTY_CLIENTE,arrayPedido,QTY_PEDIDO);
                            break;
                        case 2://
                                cliente_masPedidosCompletados(arrayMusico, arrayOrquesta, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_ORQUESTA,CANTIDAD_INSTRUMENTO );
                            break;
                        case 3://
                                cliente_masPedidos(arrayOrquesta, arrayMusico,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO);
                            break;
                        case 4://
                                cliente_mas_kilos(arrayMusico, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 5://
                                cliente_menos_kilos(arrayOrquesta, arrayMusico, arrayInstrumento,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 6://
                                cliente_cantidad_masMil(arrayOrquesta, arrayMusico,CANTIDAD_ORQUESTA,CANTIDAD_MUSICO);
                            break;
                        case 7://
                                cliente_cantidad_masCien(arrayOrquesta, arrayInstrumento,CANTIDAD_ORQUESTA,CANTIDAD_INSTRUMENTO);
                            break;
                        case 8://
                                pedido_printCompletados(arrayMusico, arrayInstrumento,CANTIDAD_MUSICO,CANTIDAD_INSTRUMENTO);
                            break;
                        case 9://
                                pedido_IdLocalidad_pendiente(Pedido arrayPedido, QTY_PEDIDO);
                                break;
                        case 10:
                                cliente_cantidadPP_promedio(Cliente arrayCliente, QTY_CLIENTE);
                                break;
                        case 11:
                                cliente_Cuit_Tipo_kilos(arrayCliente, QTY_CLIENTE);
                                break;
                        case 12:
                                break;
                            default:
                                printf("\nOpcion no valida");
                    }
                }while(opcionI != 12);
                break;
                    printf("\nOpcion no valida");

            case 10://Salir
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
    arrayCliente[i].cuit= 30-11223344-5;
    strcpy(arrayCliente[i].nombreEmpresa,"Telefonica");
    strcpy(arrayCliente[i].direccion,"Lima 1234");
    strcpy(arrayCliente[i].localidad,"CABA");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    arrayCliente[i].cuit=30-44556677-6;
    strcpy(arrayCliente[i].nombreEmpresa,"DATASOFT");
    strcpy(arrayCliente[i].direccion,"Corrientes 2547");
    strcpy(arrayCliente[i].localidad,"CABA");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    arrayCliente[i].cuit=30-88995521-9;
    strcpy(arrayCliente[i].nombreEmpresa,"NESTLE");
    strcpy(arrayCliente[i].direccion,"cucha cucha 555");
    strcpy(arrayCliente[i].localidad,"LANUS");
    (*contadorIdCliente)++;
    i++;

     //Clientes
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    arrayCliente[i].cuit=30-56781423-5;
    strcpy(arrayCliente[i].nombreEmpresa,"TERRABUSI");
    strcpy(arrayCliente[i].direccion,"rocha 784");
    strcpy(arrayCliente[i].localidad," QUILMES");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    arrayCliente[i].cuit=31-54581253-3;
    strcpy(arrayCliente[i].nombreEmpresa,"DIA");
    strcpy(arrayCliente[i].direccion,"Mitre 750");
    strcpy(arrayCliente[i].localidad,"AVELLANEDA");
    (*contadorIdCliente)++;
    i++;

    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idUnico=*contadorIdCliente;
    arrayCliente[i].cuit=30-51485759-6;
    strcpy(arrayCliente[i].nombreEmpresa,"QUILMES");
    strcpy(arrayCliente[i].direccion,"rocha 741");
    strcpy(arrayCliente[i].localidad,"QUILMES");
    (*contadorIdCliente)++;
    i++;

    //int i=0;
    //Pedido
    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=1;
    arrayPedido[i].estado=2;
    arrayPedido[i].hdpe=200;
    arrayPedido[i].ldpe=300;
    arrayPedido[i].pp=230;
    arrayPedido[i].kilos= 1000;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=1;
    arrayPedido[i].estado=2;
    arrayPedido[i].hdpe=210;
    arrayPedido[i].ldpe=45;
    arrayPedido[i].pp=30;
    arrayPedido[i].kilos= 800;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=2;
    arrayPedido[i].estado=1;
    arrayPedido[i].hdpe=0.0;
    arrayPedido[i].ldpe=0.0;
    arrayPedido[i].pp=0.0;
    arrayPedido[i].kilos= 100;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=2;
    arrayPedido[i].estado=1;
    arrayPedido[i].hdpe=0.0;
    arrayPedido[i].ldpe=0.0;
    arrayPedido[i].pp=0.0;
    arrayPedido[i].kilos= 300;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=3;
    arrayPedido[i].estado=2;
    arrayPedido[i].hdpe=500;
    arrayPedido[i].ldpe=150;
    arrayPedido[i].pp=270;
    arrayPedido[i].kilos= 1500;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=4;
    arrayPedido[i].estado=2;
    arrayPedido[i].hdpe=100;
    arrayPedido[i].ldpe=50;
    arrayPedido[i].pp=70;
    arrayPedido[i].kilos= 750;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].hdpe=0.0;
    arrayPedido[i].ldpe=0.0;
    arrayPedido[i].pp=0.0;
    arrayPedido[i].kilos= 200;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=5;
    arrayPedido[i].estado=2;
    arrayPedido[i].hdpe=10;
    arrayPedido[i].ldpe=5;
    arrayPedido[i].pp=3;
    arrayPedido[i].kilos= 30;
    (*contadorIdPedido)++;
    i++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idUnico=*contadorIdPedido;
    arrayPedido[i].idCliente=6;
    arrayPedido[i].estado=1;
    arrayPedido[i].hdpe=0.0;
    arrayPedido[i].ldpe=0.0;
    arrayPedido[i].pp=0.0;
    arrayPedido[i].kilos= 456;
    (*contadorIdPedido)++;
    i++;

    return 0;
}
