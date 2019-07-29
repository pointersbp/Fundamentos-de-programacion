#include <stdio.h>
#include <stdlib.h>

#define MACRO 10

   void llenaprimos(int[],int,int,int);
   int esprimo(int);
   int main()
   {
   int array[MACRO],n,ini,inc;
    printf(" Cuantos valores quiere imprimir: ");
    scanf("%d",&n);
    printf("\n En que numero desea comenzar: ");
    scanf("%d",&ini);
    printf("\n Cuantos espacios desea saltar: ");
    scanf("%d",&inc);

    llenaprimos(array,n,ini,inc);

    return 0;
   }
  /*
  Funcion: esprimo
  argumento: num:verifica si el rango es primo
  objetivo: hallar si es primo
  retorno: 1 si es primo(osea verdadero)
  */
 int esprimo(int num)
{
   int maxdiv = (int)sqrt(num), div = 2;
   if ( num == 1 ) return 0;

   for ( div = 2; div <= maxdiv ; div ++ )
      if ( num % div == 0 )
         return 0;

   return 1;
}


/*
  Funcion: llenaprimos
  argumento: primos:almacena el arreglo de primos
             n:cantidad de numeros que desea ingresar
             ini:el numero de arreglo que quiere ir
             inc:los numeros que va a incrementar
  objetivo: imprimir los arreglos con numeros primos
  retorno: numeros primos
  */
void llenaprimos(int primos[ ], int n, int ini, int inc)
{
    int ind=0,num,cont;
    for(num = 2;ind-ini < n;num++)
    {

        if (esprimo(num))
        {
            if(ind-ini >=0)
            {
                primos[ind-ini]=num;
                printf("%d\n",primos[ind-ini]);
            }
            ind ++;
        }

    }
}




