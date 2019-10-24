#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"


#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int menu_Informes(Pedido pedidos[], Cliente clientes[])
{
	int opcion = 0;
	do {                fflush(stdin);
						//__fpurge(stdin);
						printf("1) Cliente con mas pedidos pendientes\n");
						printf("2) Cliente con mas pedidos procesados\n");
						printf("3) Cliente con mas pedidos\n");
						printf("4) Cliente que mas kilos proceso\n");
						printf("5) Cliente que menos kilos proceso\n");
						printf("6) Cantidad de clientes que reciclaron mas de 1000 kilos\n");
						printf("7) Cantidad de clientes que reciclaron menos de 100 kilos\n");
						printf("8) Pedidos completados con ID - CUIT - Plastico Reciclado\n");
						printf("9) Cantidad de pedidos pendientes por localidad.\n");
						printf("10) Porcentaje de PP procesado por cliente.\n");
						printf("11) Cantidad de plastico procesado ingresando CUIT y tipo de Plastico.\n");
						printf("12)VOLVER AL MENU PRINCIPAL\n");
						utn_getInt(&opcion);
						switch (opcion) {
						case 1:pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
							cliente_conMasPedidosPendientes(pedidos,clientes);
							break;
						case 2:pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
							cliente_conMasPedidosCompletados(pedidos,clientes);
							break;
						case 3:cliente_conMasPedidos(pedidos,clientes);
							break;
						case 4:pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
							   listar_clienteQueMasReciclo(pedidos,clientes);
							break;
						case 5:pedido_ordenarPorId(pedidos,CANTIDAD_PEDIDOS);
						   	   listar_clienteQueMenosReciclo(pedidos,clientes);
							break;
						case 6:clientes_conMasDeMilKilosProcesados(pedidos,clientes);
							break;
						case 7:clientes_conMenosDeCienKilosProcesados(pedidos,clientes);
							break;
						case 8:listar_pedidosCompletosConInformacion(pedidos,clientes);
							break;
						case 9:listar_pedidosPendientesPorLocalidad(pedidos,clientes);
							break;
						case 10:cantidad_deKilosPPProcesadoPorCliente(pedidos,clientes);
							break;
						case 11:cantidad_deKilosProcesadosAEleccion(pedidos,clientes);
							break;
						case 12:
							;
							break;
						default:
							printf("No ingreso una opcion valida.");
							break;
						}
					} while (opcion != 12);
	return 0;
}

/** \brief lista los pedidos pendientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_pedidoPendientes(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int j;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
			{
				auxiliar = pedidos[i].idCliente;
				for(j = 0; j < CANTIDAD_CLIENTES; j++)
				{
					if(clientes[j].idCliente==auxiliar)
					{
						indexCliente = j;
					}
				}
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
				"CUIT: %s\nLa direccion es: %s %d\n"
				"Los kilos a recolectar son: %d\n"
				"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				clientes[indexCliente].cuitCliente,
				clientes[indexCliente].direccion,
				pedidos[i].kilosRetirados);
				flag = 1;
				retorno = 0;
			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}
	return retorno;
}

/** \brief lista los pedidos completos
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_pedidosCompletos(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int j;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				auxiliar = pedidos[i].idCliente;
				for(j = 0; j < CANTIDAD_CLIENTES; j++)
				{
					if(clientes[j].idCliente==auxiliar)
					{
						indexCliente = j;
					}
				}
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
				"CUIT: %s\nLa direccion es: %s %d\n"
				"La cantidad de HDPE procesado es: %d\n""La cantidad de LDPE procesado es: %d\n"
				"La cantidad de PP procesado es: %d\n"
				"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				clientes[indexCliente].cuitCliente,
				clientes[indexCliente].direccion,
				pedidos[i].kilosHDPE,
				pedidos[i].kilosLDPE,
				pedidos[i].kilosPP);
				flag = 1;
				retorno = 0;
			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}

	return retorno;
}

/** \brief lista los clientes con la cantidad de pedidos pendientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_cantidadPedidosPendientes(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int cantidadPendientes;
	int auxiliar;
	int indexCliente;
	int control;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			control = auxiliar;
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
			{
				auxiliar = pedidos[i].idCliente;
				pedido_contadorPendientes(pedidos,auxiliar,&cantidadPendientes);
				indexCliente = cliente_buscarPorId(clientes,auxiliar);
				if(control != auxiliar)
				{
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
			    "El nombre es: %s\n""El CUIT es: %s\n"
			    "La direccion es: %s %d\nLa localidad es %s.\nEl id es: %d.\n"
			    "La cantidad de pedidos pendientes es: %d\n"
			    "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
		        clientes[indexCliente].nombreEmpresa,
		        clientes[indexCliente].cuitCliente,
			    clientes[indexCliente].direccion,
			    clientes[indexCliente].localidad,
			    clientes[indexCliente].idCliente,
			    cantidadPendientes);
			    cantidadPendientes = 0;
			    flag = 1;
			    retorno = 0;
				}

			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}
	return retorno;
}

/** \brief lista el cliente con mas pedidos pendientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int cliente_conMasPedidosPendientes(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int cantidadPendientes;
	int auxiliar;
	int auxiliarPendientes = 1;
	int auxiliarIndexParaMaximo;
	int indexCliente;
	int control;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			control = auxiliar;
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
			{
				auxiliar = pedidos[i].idCliente;
				pedido_contadorPendientes(pedidos,auxiliar,&cantidadPendientes);
				indexCliente = cliente_buscarPorId(clientes,auxiliar);
			    if(cantidadPendientes > auxiliarPendientes)
			    {
			    	auxiliarPendientes = cantidadPendientes;
			    	auxiliarIndexParaMaximo = indexCliente;
			    }
				cantidadPendientes = 0;

			    retorno = 0;
			}
		}
				printf("El nombre de la empresa con mas pendientes es: %s\n", clientes[auxiliarIndexParaMaximo].nombreEmpresa);
	}
	return retorno;
}

/** \brief lista el cliente con mas pedidos completados
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int cliente_conMasPedidosCompletados(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int cantidadProcesados;
	int auxiliar;
	int auxiliarCompletados = 1;
	int auxiliarIndexParaMaximo;
	int indexCliente;
	int control;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			control = auxiliar;
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				auxiliar = pedidos[i].idCliente;
				pedido_contadorProcesado(pedidos,auxiliar,&cantidadProcesados);
				indexCliente = cliente_buscarPorId(clientes,auxiliar);
			    if(cantidadProcesados > auxiliarCompletados)
			    {
			    	auxiliarCompletados = cantidadProcesados;
			    	auxiliarIndexParaMaximo = indexCliente;
			    }
			    cantidadProcesados = 0;

			    retorno = 0;
			}
		}
				printf("El nombre de la empresa con mas procesados es: %s\n", clientes[auxiliarIndexParaMaximo].nombreEmpresa);
	}
	return retorno;
}

/** \brief muestra el cliente con mas pedidos
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int cliente_conMasPedidos(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int cantidadPedidos;
	int auxiliar;
	int auxiliarPendientes = 1;
	int auxiliarIndexParaMaximo;
	int indexCliente;
	int control;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			control = auxiliar;
			if (pedidos[i].isEmpty == 1)
			{
				auxiliar = pedidos[i].idCliente;
				pedido_contador(pedidos,auxiliar,&cantidadPedidos);
				indexCliente = cliente_buscarPorId(clientes,auxiliar);
			    if(cantidadPedidos > auxiliarPendientes)
			    {
			    	auxiliarPendientes = cantidadPedidos;
			    	auxiliarIndexParaMaximo = indexCliente;
			    }
			    cantidadPedidos = 0;

			    retorno = 0;
			}
		}
				printf("El nombre de la empresa con mas pedidos es: %s\n", clientes[auxiliarIndexParaMaximo].nombreEmpresa);
	}
	return retorno;
}

/** \brief muestra el cliente que mas reciclo
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_clienteQueMasReciclo(Pedido pedidos[], Cliente clientes[])
{
		int retorno = -1;
		int i;
		int auxiliar;
		int auxiliarKilos;
		int auxtotalKilosCliente;
		int indexCliente;
		int indexMaximo;
		if(pedidos != NULL && clientes != NULL)
		{
			for (i = 0; i < CANTIDAD_PEDIDOS; i++)
			{
				auxtotalKilosCliente = auxiliarKilos;
				if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
				{
					auxiliar = pedidos[i].idCliente;
					pedido_contadorKilosProcesados(pedidos,auxiliar,&auxiliarKilos);
					indexCliente = cliente_buscarPorId(clientes,auxiliar);

					if(auxtotalKilosCliente < auxiliarKilos)
					{
						indexMaximo = indexCliente;
					}
				}
			}
				printf("El nombre de la empresa con mas kilos reciclados es: %s\n", clientes[indexMaximo].nombreEmpresa);
	}
	return retorno;
}

/** \brief muestra el cliente que menos reciclo
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_clienteQueMenosReciclo(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int auxiliar;
	int auxiliarKilos;
	int auxtotalKilosCliente;
	int indexCliente;
	int indexMinimo;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			auxtotalKilosCliente = auxiliarKilos;
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				auxiliar = pedidos[i].idCliente;
				pedido_contadorKilosProcesados(pedidos,auxiliar,&auxiliarKilos);
				indexCliente = cliente_buscarPorId(clientes,auxiliar);

				if(auxtotalKilosCliente > auxiliarKilos)
				{
					indexMinimo = indexCliente;
				}
			}
		}
					printf("El nombre de la empresa con menos kilos reciclados es: %s\n", clientes[indexMinimo].nombreEmpresa);
		}
		return retorno;
	}

/** \brief muestra el porcentaje de plastico reciclado mas el CUIT del cliente
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_pedidosCompletosConInformacion(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int j;
	int auxiliar;
	float porcentajeReciclado;
	float totalReciclado;
	float totalRetirado;
	int indexCliente;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				auxiliar = pedidos[i].idCliente;
				for(j = 0; j < CANTIDAD_CLIENTES; j++)
				{
					if(clientes[j].idCliente==auxiliar)
					{
						indexCliente = j;
					}
				}
				totalReciclado = (pedidos[i].kilosHDPE + pedidos[i].kilosLDPE + pedidos[i].kilosPP);
				totalRetirado = pedidos[i].kilosRetirados;
				porcentajeReciclado = (totalReciclado / totalRetirado) * 100;
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
				"El id del pedidos es %d\nCUIT: %s\n"
				"El porcentaje de plastico procesado es: %.2f\n"
				"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				pedidos[i].idPedido,clientes[indexCliente].cuitCliente, porcentajeReciclado);
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief muestra el cliente con mas de mil kilos reciclados
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int clientes_conMasDeMilKilosProcesados(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int contadorClinetesMasDeMilKilos = 0;
	int totalReciclado;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				totalReciclado = (pedidos[i].kilosHDPE + pedidos[i].kilosLDPE +pedidos[i].kilosPP);
				if(totalReciclado > 1000)
				{
					contadorClinetesMasDeMilKilos++;
				}
				retorno = 0;
			}
		}
				printf("La cantidad de clientes que reciclo mas de mil kilos es:  %d\n",contadorClinetesMasDeMilKilos);
	}

	return retorno;
}

/** \brief muestra el cliente con menos de cien kilos procesados
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int clientes_conMenosDeCienKilosProcesados(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int contadorClinetesMenosDeCienKilos = 0;
	int totalReciclado;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				totalReciclado = (pedidos[i].kilosHDPE + pedidos[i].kilosLDPE +pedidos[i].kilosPP);
				if(totalReciclado < 100)
				{
					contadorClinetesMenosDeCienKilos++;
				}
				retorno = 0;
			}
		}
				printf("La cantidad de clientes que reciclo menos de 100 kilos es:  %d\n",contadorClinetesMenosDeCienKilos);
	}

	return retorno;
}

/** \brief lista los pedidos pendientes de acuerdo a la localidad ingresada por el usuario
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listar_pedidosPendientesPorLocalidad(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	char buffer[1024];
	int cantidadPendientes = 0;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		if(utn_getString("Ingrese la localidad: \n", "Localidad no valida.\n", buffer)==0)
		{
			for (int indice = 0; buffer[indice] != '\0'; indice++)
			{
				buffer[indice] = toupper(buffer[indice]);
			}

			for (i = 0; i < CANTIDAD_CLIENTES; i++)
			{
				if (clientes[i].localidad == buffer)
				{
					flag = 1;
				}
			}

			if(flag==1)
			{
				for (i = 0; i < CANTIDAD_PEDIDOS; i++)
				{
					if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
					{
						auxiliar = pedidos[i].idCliente;
						indexCliente = cliente_buscarPorId(clientes,auxiliar);
						if(strcmp(clientes[indexCliente].localidad,buffer)==0)
						{
							cantidadPendientes++;
						}
					}
				}
				printf("La cantidad de Pedidos Pendientes para %s es: %d\n",buffer,cantidadPendientes);
				retorno = 0;
			}else
			{
				printf("Esa Localidad no esta ingresada en el sistema\n");
			}
		}
	}

	return retorno;
}

/** \brief muestra el porcentaje de PP procesado por los clientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int cantidad_deKilosPPProcesadoPorCliente(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int auxiliar;
	int totalRecicladoPP = 0;
	int cantidadClientes = 0;
	float porcentajePpCliente;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
			{
				auxiliar = pedidos[i].idCliente;
				totalRecicladoPP += pedidos[i].kilosPP;

			}
			if (auxiliar == pedidos[i].idCliente && auxiliar != pedidos[i+1].idCliente )
			{
				cantidadClientes++;
			}
		}
		porcentajePpCliente = (float)totalRecicladoPP / cantidadClientes;
		printf("El porcentaje de plastico procesado es: %.2f\n",porcentajePpCliente);
		retorno = 0;
	}

	return retorno;
}

/** \brief muestra la cantidad de kilos procesados a eleccion del usuario
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int cantidad_deKilosProcesadosAEleccion(Pedido pedidos[], Cliente clientes[])
{
	int retorno = -1;
	int i;
	int j;
	int opcionPlastico;
	char tipoPlastico[10];
	char buffer[48];
	int idCliente;
	int totalReciclado = 0;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		if(utn_getCuil("Ingrese el del cliente a buscar CUIT xx-xxxxxxxx-x: \n", "Dato no valido.\n",buffer) == 0)
		{
			for (i = 0; i < CANTIDAD_CLIENTES; i++)
			{
				if (clientes[i].cuitCliente == buffer)
				{
					flag = 1;
				}
			}
		}

		if(flag == 0)
		{
			printf("Ingreso un CUIT que no existe en el sistema.\n");
		}

		if(flag == 1 && utn_getNumber(&opcionPlastico,3,1,2,"Ingrese 1 para HDPE, 2 para LDPE o 3 para PP\n","Altura no valida")== 0)
		{
			for (i = 0; i < CANTIDAD_PEDIDOS; i++)
			{
					for(j = 0; j < CANTIDAD_CLIENTES; j++)
					{
						if(strcmp(clientes[j].cuitCliente,buffer)==0)
						{
							idCliente = clientes[j].idCliente;
						}
					}
					if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1 && pedidos[i].idCliente == idCliente)
					{
						if(opcionPlastico == 1)
						{
							totalReciclado += pedidos[i].kilosHDPE;
							strcpy(tipoPlastico, "HDPE");
						}
						if(opcionPlastico == 2)
						{
							totalReciclado += pedidos[i].kilosLDPE;
							strcpy(tipoPlastico, "LDPE");
						}
						if(opcionPlastico == 3)
						{
							totalReciclado += pedidos[i].kilosPP;
							strcpy(tipoPlastico, "PP");
						}
					}
			}
		printf("La cantidad de %s procesado es: %d\n",tipoPlastico,totalReciclado);
		retorno = 0;
		}
	}

	return retorno;
}
