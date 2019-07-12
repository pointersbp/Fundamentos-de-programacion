#include <stdlib.h>
#include "ListaDobleCircular.h"

Lista* Inicializar()
{
    Lista *Nuevalista = (Lista*)malloc(sizeof(Lista));
    Nuevalista->Cantidad = 0;
    Nuevalista->Cabeza = (NODO*)malloc(sizeof(NODO));
    Nuevalista->Cabeza->data.Id = -1;
    Nuevalista->Cabeza->siguiente = Nuevalista->Cabeza;
    Nuevalista->Cabeza->anterior = Nuevalista->Cabeza;

    return Nuevalista;
}

void AgregarPelicula(Lista*listado,Pelicula elemento)
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->data = elemento;
    nuevo->siguiente = listado->Cabeza;
    nuevo->anterior = listado->Cabeza->anterior;
    listado->Cabeza->anterior->siguiente = nuevo;
    listado->Cabeza->anterior = nuevo;
}


void EliminarPelicula(Lista *listadopeliculas,NODO *aEliminar)
{
    if(aEliminar->data.Id == -1)
        return;

    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;
    free(aEliminar);

}

NODO* BuscarporId(Lista *listadoPeliculas,int id)
{
    NODO *nodoactual = listadoPeliculas->Cabeza->siguiente;

    while(nodoactual->data.Id != -1)
    {
        if(nodoactual->data.Id == id)
            return nodoactual;

        nodoactual = nodoactual->siguiente;

    }

    return NULL;
}

NODO* CopiarNodo(NODO *original)
{
    NODO *copia = (NODO*)malloc(sizeof(NODO));

    copia->data = original->data;
    copia->anterior = original->anterior;
    copia->siguiente = original->siguiente;

    return copia;
}


void Intercambiar(NODO *primero, NODO *segundo)
{
    NODO *auxPrimero = CopiarNodo(primero);

    primero->anterior->siguiente = segundo;
    primero->anterior = segundo->anterior;
    primero->siguiente->anterior = segundo;
    primero->siguiente = segundo->siguiente;
    segundo->siguiente = auxPrimero->siguiente;
    segundo->anterior->siguiente = primero;
    segundo->anterior = auxPrimero->anterior;
    primero->siguiente->anterior = primero;

    free(auxPrimero);
}

Lista* OrdenarPelicula(Lista* listadoPeliculas)
{
    NODO *nodoActual = listadoPeliculas->Cabeza->siguiente;
    NODO *nodoMenor;
    NODO *temporal;

    while(nodoActual->data.Id != -1)
    {
        nodoMenor = nodoActual;
        temporal = nodoActual->siguiente;
        while(temporal->data.Id != -1)
        {
            if(temporal->data.anno < nodoMenor->data.anno)
            {
                nodoMenor = temporal;
            }
            temporal = temporal->siguiente;
        }
        Intercambiar(nodoActual, nodoMenor);
        nodoActual = nodoActual->siguiente;
    }
}
