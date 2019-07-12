#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct Nodo *siguiente;
}Nodo;

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void Insertar(int);
void Imprimir();

int main()
{
    int ind;
    int d;

    for(ind=0;ind < 5;ind++)
    {
        printf("Ingrese el valor %d: ",ind+1);
        scanf("%d",&d);
        Insertar(d);
    }

    system("cls");
    Imprimir();



    return 0;
}

void Insertar(int elemento)
{
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = elemento;

    if(primero == NULL)
    {
        primero = aux;
        aux->siguiente = NULL;
        ultimo = aux;
    }


    ultimo->siguiente = aux;
    aux->siguiente = NULL;
    ultimo = aux;
}

void Imprimir()
{
    Nodo *aux = primero;

    while(aux != NULL)
    {
        printf("%d \t",aux ->dato);
        aux = aux->siguiente;
    }
}
