#ifndef PEDIDOS_H_
#define PEDIDOS_H_

typedef struct{
	int kilosRetirados;
	int kilosHDPE;
	int kilosLDPE;
	int kilosPP;
	int idPedido;
	int idCliente;
	int estado;
	int isEmpty;
}Pedido;


int pedido_Inicializar(Pedido pedidos[], int cantidad);
int pedido_buscarEmpty(Pedido pedidos[], int cantidad);
int pedido_alta(Pedido pedidos[],int index, int idPedido, int idCliente);
int pedido_listarPendientes(Pedido pedidos[], int cantidad);
int pedido_buscarPorId(Pedido pedidos[], int idPedido,int *pUbicacionPedido);
int pedido_procesarResiduos(Pedido pedidos[]);
void pedido_ordenarPorId(Pedido pedidos[], int cantidad);
void pedido_contadorPendientes(Pedido pedidos[], int idCliente, int* cantidadPendientes);
void pedido_contadorProcesado(Pedido pedidos[], int idCliente, int* cantidadProcesado);
void pedido_contador(Pedido pedidos[], int idCliente, int* cantidadProcesado);
void pedido_contadorKilosProcesados(Pedido pedidos[], int idCliente, int* kilosProcesado);
int pedido_buscarExistente(Pedido pedidos[], int cantidad, int* idParaAlta);

#endif /* PEDIDOS_H_ */
