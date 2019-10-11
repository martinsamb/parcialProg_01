#ifndef RESIDUOS_H_INCLUDED
#define RESIDUOS_H_INCLUDED



typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int tipo;
    int idPedido;
    int cHpped;
    int cLdpe;
    int cPp;
    int cTotal;


}Residuo;




int residuo_Inicializar(Residuo array[], int size);                                    //cambiar residuo
int residuo_buscarEmpty(Residuo array[], int size, int* posicion);                    //cambiar residuo
int residuo_buscarID(Residuo array[], int size, int valorBuscado, int* posicion);                    //cambiar residuo
int residuo_buscarInt(Residuo array[], int size, int valorBuscado, int* posicion);                    //cambiar residuo
int residuo_buscarString(Residuo array[], int size, char* valorBuscado, int* indice);                    //cambiar residuo
int residuo_alta(Residuo array[], int size, int* contadorID);                          //cambiar residuo
int residuo_baja(Residuo array[], int sizeArray);                                      //cambiar residuo
int residuo_bajaValorRepetidoInt(Residuo array[], int sizeArray, int valorBuscado);
int residuo_modificar(Residuo array[], int sizeArray);                                //cambiar residuo
int residuo_ordenarPorString(Residuo array[],int size);                              //cambiar residuo
int residuo_listar(Residuo array[], int size);                      //cambiar residuo



#endif // RESIDUOS_H_INCLUDED
