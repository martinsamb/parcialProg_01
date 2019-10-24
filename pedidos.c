#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedidos.h"


#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

/** \brief inicializa los pedidos con isEmpty en 0
* \param list pedidos[]
* \param int cantidad
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int pedido_Inicializar(Pedido pedidos[], int cantidad)
{
	int i;
	if(pedidos != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			pedidos[i].isEmpty = 0;
		}
	}
	return 0;
}
/** \brief busca la posicion de pedido con isEmpty en 0
* \param list pedidos[]
* \param int cantidad
*
* \return int retorna la posicion del pedido o (-1) if Error [Invalid length or NULL pointer or without free space]
*
*/
int pedido_buscarEmpty(Pedido pedidos[], int cantidad)
{
	int retorno = -1;
	int i;
	if(pedidos != NULL && cantidad > 0)
	{
		if(pedidos != NULL && cantidad > 0)
		{
			for (i = 0; i < cantidad; i++)
			{
				if (pedidos[i].isEmpty == 0)
				{
					return i;
				}
			}
		}
	}
	return retorno;
}

/** \brief lista los pedidos pendientes
* \param list pedidos[]
* \param int cantidad
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int pedido_listarPendientes(Pedido pedidos[], int cantidad)
{
	int retorno = -1;
	int i;
	int flag = 0;
	if(pedidos != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
			{
				printf("-----------------------------\n"
						"ID pedido: %d\n"
						"-----------------------------\n",
						pedidos[i].idPedido);
				retorno = 0;
				flag = 1;
			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}
	return retorno;
}

/** \brief da de alta un pedido
* \param list clientes[]
* \param int index
* \param int idPedido
* \param int idCliente
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int pedido_alta(Pedido pedidos[],int index, int idPedido, int idCliente)
{
	int retorno = -1;
	int auxiliar = 0;
	pedidos[index].kilosRetirados = 0;
	if(pedidos != NULL)
	{
		if (utn_getNumber(&auxiliar,2000,50,2,"Ingrese Cantidad de kilos a retirar, sin coma, entre 50-2000:\n",
													"Fuera de rango valido\n")== 0)
		{
			pedidos[index].kilosRetirados = auxiliar;
		}

		if (pedidos[index].kilosRetirados != 0)
		{
			pedidos[index].isEmpty = 1;
			pedidos[index].idPedido = idPedido;
			pedidos[index].estado = 0;
			pedidos[index].idCliente = idCliente;
			retorno = 0;
		}else
		{
			printf("No se puedo dar de alta el pedido.\n");
		}
	}
	return retorno;
}

/** \brief busca pedido por Id pedido
* \param list clientes[]
* \param int idPedido
* \param int* pUbicacionPedido
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int pedido_buscarPorId(Pedido pedidos[], int idPedido,int *pUbicacionPedido)
{
	int retorno = -1;
	int i;
	if(pedidos != NULL)
	{
		for (i = 0; i != idPedido; i++)
		{
			if (pedidos[i].idPedido == idPedido)
			{
				*pUbicacionPedido = i;
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief procesa los residuos de un pedido pendiente
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int pedido_procesarResiduos(Pedido pedidos[])
{
	int retorno = -1;
	int index = 0;
	int idPedido;
	int auxHPDE;
	int auxLDPE;
	int auxPP;
	int auxKilosRetirados;
	int flag = 0;

	if(pedidos != NULL)
	{
		if(pedido_buscarPendiente(pedidos, CANTIDAD_PEDIDOS,&idPedido)==0)
		{
			pedido_buscarPorId(pedidos,idPedido,&index);
			auxKilosRetirados = pedidos[index].kilosRetirados;
			printf("La cantidad de kilos para procesar en este pedido es: %d\n", pedidos[index].kilosRetirados);
			utn_getNumber(&auxHPDE,auxKilosRetirados,0,2,"Cuantos kilos se procesan como HPDE?\n","Ingreso Invalido.\n");
			if(auxHPDE > auxKilosRetirados)
			{
				printf("No podemos procesar mas que lo que tenemos.\n");
				flag = 1;
			}else if(auxHPDE < 0)
			{
				printf("No puede ser menor a cero.\n");
				flag = 1;
			}else
			{
				pedidos[index].kilosHDPE = auxHPDE;
				auxKilosRetirados = auxKilosRetirados - auxHPDE;
				printf("Quedan %d kilos para seguir procesando.\n", auxKilosRetirados);
			}
			if(auxKilosRetirados != 0)
			{
			utn_getNumber(&auxLDPE,auxKilosRetirados,0,2,"Cuantos kilos se procesan como LDPE?.\n","Ingreso Invalido.\n");
			if(auxLDPE > auxKilosRetirados)
			{
				printf("No podemos procesar mas que lo que tenemos.\n");
				flag = 1;
			}else if(auxLDPE < 0)
			{
				printf("No puede ser menor a cero.\n");
				flag = 1;
			}else
			{
				pedidos[index].kilosLDPE = auxLDPE;
				auxKilosRetirados = auxKilosRetirados - auxLDPE;
				printf("Quedan %d kilos para seguir procesando.\n", auxKilosRetirados);
			}
			}
			if(auxKilosRetirados != 0)
			{
			utn_getNumber(&auxPP,auxKilosRetirados,0,2,"Cuantos kilos se procesan como PP?\n","Ingreso Invalido.\n");
			if(auxPP > auxKilosRetirados)
			{
				printf("No podemos procesar mas que lo que tenemos.\n");
				flag = 1;
			}else if(auxPP < 0)
			{
				printf("No puede ser menor a cero.\n");
				flag = 1;
			}else
			{
				pedidos[index].kilosPP = auxPP;
				auxKilosRetirados = auxKilosRetirados - auxPP;
			}
			}
				printf("Se desecharan %d kilos.\n", auxKilosRetirados);
			if(flag==0)
			{
				pedidos[index].estado = 1;
				retorno = 0;
			}
		}else
		{
			printf("No existe ese numero de pedido.\n");
		}
	}
	return retorno;
}

/** \brief ordena los pedidos por idCliente
* \param list clientes[]
* \param int cantidad
*
* \return void
*
*/
void pedido_ordenarPorId(Pedido pedidos[],  int cantidad)
{
    int i;
    Pedido auxiliarPedido;
    int s = 1;
    if(pedidos != NULL && cantidad > 0)
    {
		while(s)
		{
			s = 0;
			for (i = 1; i < cantidad; i++)
			{
				if (pedidos[i].idCliente < pedidos[i - 1].idCliente)
				{
					auxiliarPedido = pedidos[i];
					pedidos[i] = pedidos[i - 1];
					pedidos[i - 1] = auxiliarPedido;
					s = 1;
				}
			}
		}
    }
}

/** \brief cuenta la cantidad de pedidos en estado pendiente
* \param list pedidos[]
* \param int idCliente
* \param int* cantidadPendientes
*
* \return void
*
*/
void pedido_contadorPendientes(Pedido pedidos[], int idCliente, int* cantidadPendientes)
{
	int i;
	int contadorPendientes = 0;
	if(pedidos != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (idCliente == pedidos[i].idCliente && pedidos[i].estado == 0)
			{
				contadorPendientes++;
			}
		}
		*cantidadPendientes = contadorPendientes;
	}

}

/** \brief cuenta la cantidad de pedidos en estado procesado
* \param list pedidos[]
* \param int idCliente
* \param int* cantidadProcesado
*
* \return void
*
*/
void pedido_contadorProcesado(Pedido pedidos[], int idCliente, int* cantidadProcesado)
{
	int i;
	int contadorProcesado = 0;
	if(pedidos != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (idCliente == pedidos[i].idCliente && pedidos[i].estado == 1)
			{
				contadorProcesado++;
			}
		}
		*cantidadProcesado = contadorProcesado;
	}

}

/** \brief cuenta la cantidad de pedidos
* \param list pedidos[]
* \param int idCliente
* \param int* cantidadProcesado
*
* \return void
*
*/
void pedido_contador(Pedido pedidos[], int idCliente, int* cantidadProcesado)
{
	int i;
	int contadorProcesado = 0;
	if(pedidos != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (idCliente == pedidos[i].idCliente)
			{
				contadorProcesado++;
			}
		}
		*cantidadProcesado = contadorProcesado;
	}

}
/** \brief busca si el id de pedido existe
* \param list pedidos[]
* \param int cantidad
* \param int* idParaProcesar
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoutfree space] - (0) if Ok
*
*/
int pedido_buscarPendiente(Pedido pedidos[], int cantidad, int* idParaProcesar)
{
	int retorno = -1;
	int i;
	int auxiliarIdPedido;
	if(pedidos != NULL && cantidad > 0)
	{
		if (utn_getNumber(&auxiliarIdPedido,2000,100,2,"Ingrese id del pedido:\n","Id no fue ingresado correctamente\n")== 0)
			{
				for (i = 0; i < cantidad; i++)
				{
					if (pedidos[i].idPedido == auxiliarIdPedido)
					{
						*idParaProcesar = auxiliarIdPedido;
						retorno = 0;
					}
				}
			}
	}
	return retorno;
}

void pedido_contadorKilosProcesados(Pedido pedidos[], int idCliente, int* kilosProcesado)
{
	int i;
	int contadorKilosProcesado = 0;
	if(pedidos != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (idCliente == pedidos[i].idCliente)
			{
				contadorKilosProcesado += (pedidos[i].kilosHDPE + pedidos[i].kilosLDPE + pedidos[i].kilosPP);
			}
		}
		*kilosProcesado = contadorKilosProcesado;
	}

}
