#include <stdlib.h>
#include "Lista.h"

Lista* InicializarLista()
{
    Lista *nueva = (Lista*)malloc(sizeof(Lista));
    nueva->Cabeza = NULL;
    nueva->tamano = 0;
    return nueva;

}

void AgregarEnCola(Lista *listado, int elemento)
{
    Nodo *temporal;
    Nodo *nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
    nodoNuevo->data = elemento;
    nodoNuevo->siguiente = NULL;

    if(listado->tamano == 0)
    {
        listado->Cabeza = nodoNuevo;
        listado->tamano++;
        return;
    }

    temporal = listado->Cabeza;
    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = nodoNuevo;
    listado->tamano++;
}

void Intercambiar(Nodo *primero, Nodo *segundo)
{
    /*
    Nodo *burbuja = (Nodo*)malloc(sizeof(Nodo));
    burbuja->data = primero->data;
    burbuja->siguiente = primero->siguiente;
    primero->data = segundo->data;
    primero->siguiente = segundo->siguiente;
    segundo->data = burbuja->data;
    segundo->siguiente = burbuja->siguiente; */

    int burbuja;
    burbuja = primero->data;
    primero->data = segundo->data;
    segundo->data = burbuja;
}
