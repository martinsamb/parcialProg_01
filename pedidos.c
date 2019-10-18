#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedidos.h" //cambiar por nombre entidad
#include "clientes.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array pedido Array of pedido
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int pedido_Inicializar(Pedido array[], int size)                                    //cambiar pedido
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pedido_buscarEmpty(Pedido array[], int size)                    //cambiar pedido
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
            {
                retorno = posicion;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pedido_buscarById(Pedido array[], int id, int size)
{
    int i;
    int retorno=-1;
    for(i=0; i<size; i++)
    {
        if(array[i].isEmpty==0 && array[i].idUnico==id)
        {
            retorno=i;
            break;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro el ID\n");
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pedido_alta(Pedido arrayP[], int sizeP,int id, Cliente arrayC[],int sizeC)
{
    int retorno = -1;
    int posicion;
    int idCliente;
    Pedido auxPedido;
    posicion = pedido_buscarEmpty(arrayP, sizeP);
    if(arrayP!= NULL && posicion>=0 && posicion<sizeP);
    {
        cliente_listar(arrayC,sizeC);
        utn_getUnsignedInt("\nIngrese ID de cliente: ","\nError",1,sizeof(int),1,3,2,&idCliente);
        if(cliente_buscarById(arrayC,idCliente,TEXT_CLIENT)==-1 &&
           utn_getUnsignedInt("\nIngrese Cantidad de residuos en kilos: ","\nError",3,0,5000,1,3,&auxPedido[posicion].kilos)==0)
        {
            arrayP[posicion]=auxPedido;
            arrayP[posicion].idUnico = id;
            arrayP[posicion].idCliente = idCliente;
            arrayP[posicion].estado = PENDIENTE;
            arrayP[posicion].isEmpty = 0;
            retorno = 0;
        }
        else
        {
            printf("\nNo hay mas espacio para guardar clientes");
        }
        return retorno;
    }

}
//*****************************************

//Listar
/** \brief Lista los elementos de un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/

int pedido_printPendiente(Pedido arrayP[], int posicion, int sizeP,Cliente arrayC[],int sizeC)
{
    int retorno =-1;
    int indexCliente;
    indexCliente = cliente_buscarById(arrayC,arrayP[posicion].idCliente,sizeC);
    if(arrayP!=NULL && posicion<sizeP)
    {
        printf("%d\t%d\t%s\t\%d\n",arrayP[posicion].idUnico,arrayC[indexCliente].cuit,arrayC[indexCliente].direccion,arrayP[posicion].kilos);
        retorno = 0;
    }
    else
    {
        printf("Error al imprimir los datos del pedido\n");
    }
    return retorno;
}

void pedido_listarPendiente(Pedido arrayP[],int sizeP, Cliente arrayC[], int sizeC)
{
    int i;
    printf("\n\nID\tCuit\tDireccion\tKilos\n");
    for(i=0; i<sizeP; i++)
    {
        if(arrayP[i].isEmpty ==0 && arrayP[i].estado==PENDIENTE)
        {
            pedido_printPendiente(arrayP,i,sizeP,arrayC,sizeC);
        }
    }
}

int residuo_procesar(Pedido arrayP[], int sizeP, Cliente arrayC[],int sizeC)
{
    int retorno =-1;
    int idPedido;
    int indexPedido;
    float hdpeKilos;
    float ldpeKilos;
    float ppKilos;
    float kilosMaximo;

    pedido_listarPendiente(arrayP,sizeP,arrayC,sizeC);
    if(utn_getUnsignedInt("\nIngrese ID de Pedido: ","\nError",3,0,2000,3,1,&idPedido)==0)
    {
        indexPedido = pedido_buscarById(arrayP,idPedido,sizeP);
        if(indexPedido != -1)
        {
            kilosMaximo = arrayP[indexPedido].kilos;
            if(utn_getFloat("\nIngrese la cantidad de HDPE en Kilos: ", "\nError", 3,kilosMaximo,1,5,1,&hdpeKilos)==0)
            {
                kilosMaximo = kilosMaximo-hdpeKilos;
            }
            if(utn_getFloat("\nIngrese la cantidad de LDPE en Kilos: ", "\nError", 3,kilosMaximo,1,5,1,&ldpeKilos)==0)
            {
                kilosMaximo = kilosMaximo-ldpeKilos;
            }
            if(utn_getFloat("\nIngrese la cantidad de PP en Kilos: ", "\nError", 3,kilosMaximo,1,5,1,&ppKilos)==0)
            {
                kilosMaximo=kilosMaximo-ppKilos;
            }
            if(kilosMaximo<0)
            {
                printf("\nNo puede haber basura en negativo");
            }
            else
            {
                arrayP[indexPedido].hdpe = hdpeKilos;
                arrayP[indexPedido].ldpe = ldpeKilos;
                arrayP[indexPedido].pp = ppKilos;
                arrayP[indexPedido].estado = COMPLETADO;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int pedido_printProcesado(Pedido arrayP[],int sizeP, int posicion,Cliente arrayC[], int sizeC)
{
    int retorno=-1;
    int indexCliente;

    indexCliente = cliente_buscarById(arrayC,arrayP[posicion].idCliente,sizeC);
    if(arrayP!=NULL && posicion<sizeP)
    {
        printf("%d   %s%18s     %.2f\t  %7.2f%10.2f\n",arrayP[posicion].idUnico,arrayC[indexCliente].cuit,arrayC[indexCliente].direccion,arrayP[posicion].hdpe,arrayP[posicion].ldpe,arrayP[posicion].pp);
        retorno = 0;
    }
    else
    {
        printf("Error al imprimir los datos del pedido\n");
    }
    return retorno;
}

void pedido_listaProcesado(Pedido arrayP[],int sizeP, Cliente arrayC[],int sizeC)
{
    int i;
    printf("\n\nId\tCuit\t\tDireccion\tHDPE\t   LDPE\t      PP\n");
    printf("--\t----\t\t---------\t----\t   ----\t      --\n");
    for(i=0;i<sizeP;i++)
    {
        if(arrayP[i].isEmpty==0 && arrayP[i].estado==COMPLETADO)
        {
            pedido_printProcesado(arrayP,i,sizeP,arrayC,sizeC);
        }
    }
}

int pedido_cantidadPorCliente(Pedido arrayP[], int sizeP, Cliente* arrayC[], int indexCliente)
{
    int retorno = -1;
    int i;
    int cantidadPedidos = 0;

    for(i=0; i<sizeP; i++)
    {
        if(arrayP[i].idCliente==arrayC[indexCliente].id && arrayP[i].estado==PENDIENTE && arrayP[i].isEmpty == 0)
        {
            cantidadPedidos++;
        }
    }

    retorno = cantidadPedidos;

    return retorno;
}

int pedido_printCliente(Pedido arrayP[], int sizeP, Cliente arrayC[], int indexCliente, int sizeC)
{
    int retorno=-1;
    int cantidadDePedidos;

    cantidadDePedidos = pedido_cantidadPorCliente(arrayP,sizeP, arrayC, indexCliente);
    if(arrayC!=NULL && indexCliente<sizeC)
    {
        printf("%d      %-14s%10s  \t%s  \t%10s   \t%d\n", arrayC[indexCliente].idUnico, arrayC[indexCliente].nombreEmpresa, arrayC[indexCliente].cuit, arrayC[indexCliente].direccion, arrayC[indexCliente].localidad, cantidadDePedidos);
        retorno=0;
    }
    else
    {
        printf("Error al imprimir los datos del Cliente \n");
    }
    return retorno;
}

void pedido_listarCliente(Pedido* arrayP[], int sizeP, Cliente* arrayC[], int sizeC)
{
    int i;

    printf("\n\nId\tNombre\t\tCuit\t\tDireccion\tLocalidad\tPedidos\n");
    printf("--\t------\t\t----\t\t---------\t---------\t-------\n");
    for(i=0;i<sizeC;i++)
    {
        if(arrayC[i].isEmpty==0)
        {
            pedido_printCliente(arrayP,sizeP,arrayC,i,sizeC);
        }
    }
}

void pedido_listaPendientes(Pedido arrayP[],int sizeP, Cliente arrayC[],int sizeC)
{
    int i;

    for(i=0;i<sizeP;i++)
    {
        if(arrayP[i].isEmpty==0 && arrayP[i].estado==PENDIENTE)
        {
            pedido_printPendiente(arrayP,i,sizeP,arrayC,sizeC);
        }
    }
}

int pedido_printPendiente(Pedido arrayP[],int sizeP, int posicion,Cliente arrayC[], int sizeC)
{
    int retorno=-1;
    int indexPendiete;

    indexPendiente = pedido_buscarById(arrayP,arrayP[posicion].estado,sizeP);
    if(arrayP!=NULL && posicion<sizeP)
    {
        printf("%d   %d\n",arrayP[posicion].idUnico,arrayP[posicion].estado);
        retorno = 0;
    }
    else
    {
        printf("Error al imprimir los datos del pedido\n");
    }
    return retorno;
}






