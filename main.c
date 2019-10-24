#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"

#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int main(void) {

	Cliente clientes[CANTIDAD_CLIENTES] = {
			{"Telefonica","30-11223344-5","Lima 1234","CABA",1,1},
			{"DATASOFT","30-44556677-6","Corrientes 2547","CABA",2,1},
			{"NESTLE","30-88995521-9","cucha cucha 555","LANUS",3,1},
			{"TERRABUSI","30-56781423-5","rocha 784","QUILMES",4,1},
			{"DIA","31-54581253-3","Mitre 750","AVELLANEDA",5,1},
			{"QUILMES","30-51485759-6","rocha 741","QUILMES",6,1}
	};
	Pedido pedidos[CANTIDAD_PEDIDOS] = {
			{1000,200,145,230,1,1,1,1},
			{800,210,45,30,2,1,1,1},
			{100,0,0,0,3,2,0,1},
			{300,0,0,0,4,2,0,1},
			{1500,500,150,270,5,3,1,1},
			{750,100,50,70,6,4,1,1},
			{200,0,0,0,7,1,0,1},
			{30,10,5,3,8,5,1,1},
			{456,0,0,0,9,6,0,1}
	};

	int idCliente = CANTIDAD_CLIENTES;
	int idPedido = CANTIDAD_PEDIDOS;
	int opcion = 0;
	int indexCliente;
	int indexPedido;
	int auxIdParaAlta;

	do {
                    fflush(stdin);
					//__fpurge(stdin);
					printf(" -- Menu Principal --\n");
					printf("1) Alta cliente\n");
					printf("2) Modificar cliente\n");
					printf("3) Baja cliente\n");
					printf("4) Pedidode recoleccion\n");
					printf("5) Procesar residuos\n");
					printf("6) Imprimir clientes\n");
					printf("7) Imprimie pedidos pendientes\n");
					printf("8) Imprimir pedidos procesados\n");
					printf("9) Informes\n");
					printf("10) Salir\n");
					utn_getInt(&opcion);
					switch (opcion) {
					case 1:
						indexCliente = cliente_buscarEmpty(clientes,CANTIDAD_CLIENTES);
						if(cliente_alta(clientes,indexCliente,idCliente)==0)
						{
						idCliente++;
						}
						break;
					case 2:cliente_modificar(clientes,CANTIDAD_CLIENTES);
						break;
					case 3:
						cliente_listar(clientes,CANTIDAD_CLIENTES);
						cliente_baja(clientes);
						break;
					case 4:
						cliente_ordenarPorId(clientes,CANTIDAD_CLIENTES);
						cliente_listar(clientes,CANTIDAD_CLIENTES);
						if(cliente_buscarExistente(clientes,CANTIDAD_CLIENTES, &auxIdParaAlta)==0)
						{
					    indexPedido = pedido_buscarEmpty(pedidos,CANTIDAD_PEDIDOS);
						if(pedido_alta(pedidos,indexPedido,idPedido,auxIdParaAlta)==0)
					    {
						idPedido++;
					    }
						}else
						{
							printf("No existe el cliente con ese id para recolectar.\n");
						}
						break;
					case 5:
						if(pedido_listarPendientes(pedidos,CANTIDAD_PEDIDOS)==0)
						{
						pedido_procesarResiduos(pedidos);
						}
						break;
					case 6:
					    pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
                        listar_cantidadPedidosPendientes(pedidos,clientes);
						break;
					case 7:
					    pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
						listar_pedidoPendientes(pedidos,clientes);
						break;
					case 8:
					    pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
						listar_pedidosCompletos(pedidos,clientes);
						break;
					case 9:
					    menu_Informes(pedidos, clientes);
						break;
					case 10:
						printf("Gracias por usar el programa.\n");
						break;
					default:
						printf("No ingreso una opcion valida.");
						break;
					}
				} while (opcion != 10);

	return 0;
}
