#include <stdlib.h>
#ifndef _Colah
#define _Colah

typedef struct
{
    float *elementos;
    int tamano;
    int primerIndice;
    int ultimoIndice;
    int cantidad;
}Cola;

void InicializarCola();
short isEmpty(Cola*);
float getFront(Cola*);
void enqueue(Cola*,float);
float dequeue(Cola*);
void VerificarEspacio(Cola*);
int TamanoCola(Cola*);
#endif // _Colah

