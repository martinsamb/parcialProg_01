#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
/*
int cliente_listarPorCriterio(Pedido arrayP[], Cliente arrayC[], int sizeP, int sizeC, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayC!=NULL && sizeC>=0 && arrayP!=NULL && sizeP>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeP;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayP[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(arrayP[i].estado,criterio)==0)
            {
                pedido_buscarById()_buscarID(arrayP,sizeJ,arrayP[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayP[i].idUnico,arrayC[j].idUnico);
            }

        }
        retorno=0;
    }
    return retorno;
}
*/
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int cliente_masPedidosPendientes(Pedido arrayP[], Cliente arrayC[], int sizeC, int sizeJ)         // PedidosPendientes
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayP!=NULL && sizeP>=0 && arrayC!=NULL && sizeC>=0)
    {
        for(i=0;i<sizeP;i++)
        {
            pedido_listaPendientes(arrayP,sizeP,arrayC,sizeC);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayP[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nEstado: %s",arrayP[i].estado);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeP;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayC[k].isEmpty!=1 && strcmp(arrayC[k].idUnico,arrayP[i].estado)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        pedido_buscarById(arrayC,sizeC,arrayP[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayP[k].estado*arrayC[j].idUnico);

                        printf("\nID Pedido: %d\nID Cliente: %d",
                                arrayP[k].idUnico,arrayP[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int cliente_masPedidosCompletados(Pedido arrayP[], Cliente arrayC[], int sizeC, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayP!=NULL && sizeP>=0 && arrayC!=NULL && sizeC>=0)
    {
        for(i=0;i<sizeP;i++)
        {
            pedido_listaCompletado(arrayP,sizeP,arrayC,sizeC);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayP[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nEstado: %s",arrayP[i].estado);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeP;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayC[k].isEmpty!=1 && strcmp(arrayC[k].idUnico,arrayP[i].estado)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        pedido_buscarById(arrayC,sizeC,arrayP[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayP[k].estado*arrayC[j].idUnico);

                        printf("\nID Pedido: %d\nID Cliente: %d",
                                arrayP[k].idUnico,arrayP[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int cliente_masPedidos(Pedido arrayP[], Cliente arrayC[], int sizeP, int sizeC)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeP];
    int iMaxContador [sizeP];

    if(arrayP!=NULL && sizeP>=0 && arrayC!=NULL && sizeC>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            pedido_cantidadPorCliente();                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nEstado: %d",arrayP[i].estado);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayP[k].isEmpty!=1 && strcmp(arrayP[k].varString,arrayC[i].idUnico)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        pedido_buscarById(arrayC,sizeC,arrayP[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayP[k].estado*arrayC[j].idUnico);

                        printf("\nID Pedido: %d\nID Cliente: %d",                                         //imprimo datos que haya que mostrar
                                arrayP[k].idUnico,arrayC[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayP[iMaxAcumulado[i]].estado);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].varString);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int cliente_mas_kilos(Pedido arrayP[], Cliente arrayC[], int sizeP, int sizeC)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeP];
    int iMaxContador [sizeP];

    if(arrayP!=NULL && sizeP>=0 && arrayC!=NULL && sizeC>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            pedido_cantidadPorCliente();                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nEstado: %d",arrayP[i].estado);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayP[k].isEmpty!=1 && strcmp(arrayP[k].varString,arrayC[i].idUnico)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        pedido_buscarById(arrayC,sizeC,arrayP[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayP[k].estado*arrayC[j].idUnico);

                        printf("\nID Pedido: %d\nID Cliente: %d",                                         //imprimo datos que haya que mostrar
                                arrayP[k].idUnico,arrayC[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayP[iMaxAcumulado[i]].estado);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].varString);
            }
        }

        retorno=0;
    }
    return retorno;
}


/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Fantasma arrayAux[sizeI];                                                           //cambiar Fantasma y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].varString,arrayA[i].varString);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                    }
                }
                arrayAux[i].varInt=contador;                                    //completo el resto de los campos
                arrayAux[i].varInt=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/*---------------------------------------------------------------------------------*/


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
    int indexPendiente;

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

void pedido_listaCompletados(Pedido arrayP[],int sizeP, Cliente arrayC[],int sizeC)
{
    int i;

    for(i=0;i<sizeP;i++)
    {
        if(arrayP[i].isEmpty==0 && arrayP[i].estado==COMPLETADO)
        {
            pedido_printCompletado(arrayP,i,sizeP,arrayC,sizeC);
        }
    }
}

int pedido_printCompletado+(Pedido arrayP[],int sizeP, int posicion,Cliente arrayC[], int sizeC)
{
    int retorno=-1;
    int indexPendiente;

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

