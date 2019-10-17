#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array cliente Array of cliente
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cliente_Inicializar(Cliente array[], int size)                                    //cambiar cliente
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
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int cliente_buscarEmpty(Cliente array[], int size, int* posicion)                    //cambiar cliente
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarById(Cliente array[], int id, int size)                    //cambiar cliente
{
    int retorno=-1;
    int i;
    for(i=0; i<size;i++)
    {
        if(array[i].isEmpty==0 && array[i].idUnico==id)
        {
            retorno=i;
            break;
        }
    }
    if(retorno==-1)
    {
        printf(" no se encontro el Id\n");
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int cliente_alta(Cliente array[], int size, int* contadorID)                          //cambiar cliente
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getName("\nNombre: ","\nError",1,20,1,array[posicion].nombreEmpresa) == 0 &&
                utn_getCUIT("\nCuit: ","\nError", 1, array[posicion].cuit)== 0 &&
               utn_getAlfanumerico("\nDireccion: ","\nError", 1, TEXT_NAME, 1, array[posicion].direccion)== 0 &&
               utn_getAlfanumerico("\nLocalidad: ","\nError", 1, TEXT_NAME, 1, array[posicion].localidad)== 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\n ID: %d\n Nombre Empresa: %s\n Cuit: %d\n Direccion: %s\n Localidad: %s",
                       array[posicion].idUnico,
                       array[posicion].nombreEmpresa,
                       array[posicion].cuit,
                       array[posicion].direccion,
                       array[posicion].localidad);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}
//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_baja(Cliente array[], int sizeArray)
{
int retorno=-1;
int posicion;
int id;
int opcion;
int size;

    cliente_listar(array,size);
    if(utn_getUnsignedInt("\nIngrese baja cliente: ","\nError",1,sizeof(int),4,3,1,&id)==0)
    {
        posicion=cliente_buscarById(array,id,size);
        if(posicion!=-1)
        {
            printf("\n\nID\tNombre\t\tCuit\t\tDireccion\tLocalidad\n");
            printf("--\t-----\t\t--------\t-----------\n");
            cliente_print(array,posicion,size);

            printf("\nConfirmar borrado: \n\n");
            printf("1- SI\n");
            printf("2- NO\n");
            if(utn_getUnsignedInt("\nElija una opcion: ","\nError",1,sizeof(int),4,3,1,&opcion)==0 && opcion==1)
            {
                array[posicion].isEmpty=1;
                printf("\n Baja Exitosa\n\n");
            }
        }
    }
    return retorno;
}
//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int cliente_modificar(Cliente array[], int sizeArray)                                //cambiar cliente
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        cliente_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),4,3,1,&id);         //cambiar si no se busca por ID
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                printf("\n ID: %d\n Nombre: %s\n Cuit: %d\n Direccion: %s\n Localidad: %s",
                       array[posicion].idUnico,
                       array[posicion].nombreEmpresa,
                       array[posicion].cuit,
                       array[posicion].direccion,
                       array[posicion].localidad);
                utn_getLetra("\nModificar: A: Direccion B: Localidad: S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getDomicilio("\nDireccion : ","\nError",1,TEXT_SIZE,1, array[posicion].direccion);
                        break;
                    case 'B':
                        utn_getTexto("\nLocalidad: ","\nError",1,TEXT_SIZE,1,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
//*****************************************


//Listar
/** \brief Lista los elementos de un array
* \param array cliente Array de cliente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listar(Cliente array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\nID: %d\nNombre Empresa: %s\nCuit: %d\nDireccion: %s\nLocalidad: %s",
                       array[i].idUnico,
                       array[i].nombreEmpresa,
                       array[i].cuit,
                       array[i].direccion,
                       array[i].localidad);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
int cliente_print(Cliente array[], int posicion,int size)
{
    int retorno =-1;
    if(array!=NULL && posicion<size)
    {
        printf("%d\t%s\t%d\t%s\t%s\n",array[posicion].idUnico,array[posicion].nombreEmpresa,array[posicion].cuit,array[posicion].direccion,array[posicion].localidad);
        retorno = 0;
    }
    else
    {
        printf("Error al imprimir losd datos del cliente\n");
    }
    return retorno;
}


