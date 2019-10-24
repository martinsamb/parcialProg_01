
#ifndef INFORMES_H_
#define INFORMES_H_

int listar_pedidoPendientes(Pedido pedidos[], Cliente clientes[]);
int listar_cantidadPedidosPendientes(Pedido pedidos[], Cliente clientes[]);
int listar_pedidosCompletos(Pedido pedidos[], Cliente clientes[]);
int cliente_conMasPedidosPendientes(Pedido pedidos[], Cliente clientes[]);
int cliente_conMasPedidosCompletados(Pedido pedidos[], Cliente clientes[]);
int menu_Informes(Pedido pedidos[], Cliente clientes[]);
int cliente_conMasPedidos(Pedido pedidos[], Cliente clientes[]);
int listar_clienteQueMasReciclo(Pedido pedidos[], Cliente clientes[]);
int listar_clienteQueMenosReciclo(Pedido pedidos[], Cliente clientes[]);
int listar_pedidosCompletosConInformacion(Pedido pedidos[], Cliente clientes[]);
int clientes_conMasDeMilKilosProcesados(Pedido pedidos[], Cliente clientes[]);
int clientes_conMenosDeCienKilosProcesados(Pedido pedidos[], Cliente clientes[]);
int listar_pedidosPendientesPorLocalidad(Pedido pedidos[], Cliente clientes[]);
int cantidad_deKilosPPProcesadoPorCliente(Pedido pedidos[], Cliente clientes[]);
int cantidad_deKilosProcesadosAEleccion(Pedido pedidos[], Cliente clientes[]);
int bucar_localidadExistente(Cliente clientes[], int cantidad, char* localidad);

#endif /* INFORMES_H_ */
