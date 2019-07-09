#include <stdio.h>
#include <stdlib.h>
#include "Animales.h"

int main()
{
    int temporal;
    int verificacion;
    Cola *Perros = InicializarCola();
    Cola *Gatos = InicializarCola();
    Cola *Ambos = InicializarCola();
    char perro;
    char gato;


        do{
            printf("presione 1 para perros, presione 2 para empezar con gatos");
            scanf("%d",&verificacion);
            if(verificacion == 1)
            {
                do{
                printf("ingrese el nombre de los cachorro");
                scanf("%c",&perro);
                enqueue(Perros,perro);
                enqueue(Ambos,perro);
                printf("desea continuar?(cualquier tecla para que si,0 para salir)");
                scanf("%d",&temporal);

                }while(temporal !=0);
                temporal++;
                if(isEmpty(Gatos))
                    verificacion++;
            }
            if(verificacion == 2)
            {
                do{
                printf("ingrese el nombre de los gato");
                scanf("%c",&gato);
                enqueue(Gatos,gato);
                enqueue(Ambos,gato);
                printf("desea continuar?(cualquier tecla para que si,0 para salir)");
                scanf("%d",&temporal);

                }while(temporal !=0);
                temporal++;
                if(isEmpty(Perros))
                    verificacion--;
             }

            }while(verificacion!=1 || verificacion !=2);

            system("cls");


            do{
                printf("que animal desea adoptar? (1 para perro 2 para gato)");
                printf("1- perro");
                printf("2- gato");
                printf("3- terminar");
                printf("4- Cualquiera");
                scanf("%d",&temporal);
                if (temporal == 1)
                {
                    if(!isEmpty(Perros))
                        printf("%.2f\t",dequeue(Perros));
                }
                if (temporal == 2)
                {
                    if(!isEmpty(Gatos))
                        printf("%.2f\t",dequeue(Gatos));
                }
                if (temporal == 3)
                    break;
                if (temporal == 4)
                {
                    if(!isEmpty(Ambos))
                        printf("%.2f\t",dequeue(Ambos));
                }
        }while(1);

    printf("Gracias por su visita!");


    return 0;
}
