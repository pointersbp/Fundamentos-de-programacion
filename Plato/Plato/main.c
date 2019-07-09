#include <stdio.h>
#include <stdlib.h>

#define MACRO 10

typedef struct
{
    float data;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *tope;
    int cantidad;
}Pila;

Pila* IniciarPila();
float Pop(Pila*);
void Push(Pila*,float);


int main()
{

    int indice;
    float numero;
    int* Pila1 = IniciarPila();
    int* Pila2 = IniciarPila();
    int* Pila3 = IniciarPila();

    printf("El contenedor de platos tiene un limite ingrese los datos hasta que se llene: \n");


    for(indice = 0;indice<MACRO;indice++)
    {
        if(indice==9)
            printf("ADVERTENCIA SOLO CABE UN PLATO MAS: \n");
        scanf("%f",&numero);
        Push(Pila1,numero);
    }

    printf("El contenedor esta lleno... ingrese los datos del nuevo contenedor\n");


    for(indice = 0;indice<MACRO;indice++)
    {
        if(indice==9)
            printf("ADVERTENCIA SOLO CABE UN PLATO MAS: \n");
        scanf("%f",&numero);
        Push(Pila2,numero);
    }

    printf("El contenedor esta lleno... ingrese los datos del nuevo contenedor\n");


    for(indice = 0;indice<MACRO;indice++)
    {
        if(indice==9)
            printf("ADVERTENCIA SOLO CABE UN PLATO MAS: \n");
        scanf("%f",&numero);
        Push(Pila3,numero);
    }

    printf("todos los contenedores han sido agotados aqui los datos de todos\n");
    printf("hasta la proxima\n");

    printf("primer contenedor");

    for(indice = 0;indice<MACRO;indice++)
    {
        numero= Pop(Pila1);
        printf("%2.f \t",numero);
    }

    printf("segundo contenedor");
        for(indice = 0;indice<MACRO;indice++)
    {
        numero= Pop(Pila2);
        printf("%2.f \t",numero);
    }

        for(indice = 0;indice<MACRO;indice++)
    {
        numero= Pop(Pila3);
        printf("%2.f \t",numero);
    }



    return 0;
}

Pila* IniciarPila()
{
    Pila *nueva = (Pila*)malloc(sizeof(Pila));
    nueva->cantidad = 0;
    nueva->tope = NULL;

    return nueva;
}
float Pop(Pila *pila)
{
    float resultado = pila->tope->data;

    Nodo *aBorrar = pila->tope;
    pila->tope = pila->tope->siguiente;
    free(aBorrar);

    return resultado;
}
void Push(Pila *pila, float elemento)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->cantidad++;
}
