#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{
	char nombreEmpresa[100];
	char cuitCliente[20];
	char direccion[100];
	char localidad[200];
	int idCliente;
	int isEmpty;
}Cliente;


int cliente_Inicializar(Cliente clientes[], int cantidad);
int cliente_buscarEmpty(Cliente clientes[], int cantidad);
int cliente_alta(Cliente clientes[], int index,int idCliente);
int cliente_buscarPorId(Cliente clientes[], int idCliente);
int cliente_modificar(Cliente clientes[],int cantidad);
int cliente_listar(Cliente clientes[], int cantidad);
int cliente_baja(Cliente clientes[]);
int cliente_buscarExistente(Cliente clientes[], int cantidad, int* idParaAlta);
void cliente_ordenarPorId(Cliente clientes[],  int cantidad);

#endif /* CLIENTES_H_ */

