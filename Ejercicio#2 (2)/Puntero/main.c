#include <stdio.h>
#include <stdlib.h>

void capturar(int*,int*);
void imprimir(int*,int*);
void ordenarinsercion(int*,int*);
void burbuja(int*,int*);

int main()
{
    int longitud;
    printf("Ingrese la longitud del arreglo: ");
    scanf("%d",&longitud);
    int* pointer;
    pointer =(int*) calloc(longitud,sizeof(int));
    capturar(pointer,&longitud);
    ordenarinsercion(&longitud,pointer);
    //burbuja(pointer,&longitud);
    imprimir(pointer,&longitud);


    return 0;
}


void capturar(int* n,int* tamano)
{
    int i;
    for (i = 0; i < *tamano ; i++)
        {
            printf("ingrese el valor %d: ",i+1);
            scanf("%d",(n + i));
        }

}

void imprimir(int* p,int* lenght)
{
        int j;
        for (j = 0; j < *lenght ; j++)
        {
            printf("%d \t",*(p + j));
        }

}
void ordenarinsercion(int *tam,int *arreglo)
{
    int i, j, valorActual;

    for(i=1; j<*tam; i++)
    {
        valorActual = *(arreglo + i);
        j=i-1;
        while(j>=0 && *(arreglo+j) > valorActual)
        {
            *(arreglo+j+1) = *(arreglo+j);
            j--;
        }
        *(arreglo+j+1) = valorActual;
    }
}
void burbuja(int* n,int* tamano)
{
    int temporal,i,j;
    for (i=0;i<*tamano;i++)
    {
        for (j=0;j<*tamano;j++)
        {
            if (*(n)>=*(n+1))
            {
                temporal=*(n);
                *(n)=*(n+1);
                *(n)=temporal;
            }

        }

    }
}
