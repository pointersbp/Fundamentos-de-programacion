#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conio.h"
#include <conio.h>
#include "ListaDobleCircular.h"

typedef enum
{
    Salir = 0,
    Agregar = 1,
    Modificar,
    Eliminar,
    Insertar,
    Explorar,
    Ordenar,
    Buscar,

}eSeleccionmenu;

eSeleccionmenu Mostrarmenu();
void MostrarMarco3Col();
void CapturarPelicula(Lista*,NODO*);
void ExplorarPeliculas(Lista*);
void MostrarMarco3Col();
void mostrarsinopsis(int col,int fil,int lim,char*texto);
void ModificarPelicula(Lista *listadoPeliculas);
void BorrarPelicula(Lista *listadoPeliculas);
void OrdenarPeliculasPorAnyo(Lista*);
const int COL2 = 26, COL3 = 52, LIMCOLUMNA = 24;

int main()
{
    Lista* listadoPeliculas = Inicializar();
    eSeleccionmenu opcionActual;

    do
    {
        opcionActual = Mostrarmenu();
        switch(opcionActual)
        {
        case Agregar:
            CapturarPelicula(listadoPeliculas,NULL);
            break;
        case Modificar:
            ModificarPelicula(listadoPeliculas);
            break;
        case Eliminar:
            BorrarPelicula(listadoPeliculas);
            break;
        case Insertar:
            break;
        case Explorar:
            MostrarMarco3Col();
            ExplorarPeliculas(listadoPeliculas);
            break;
        case Buscar:
            break;
        }
    }while(opcionActual != Salir);
    Mostrarmenu();
    gotoxy(5,20);
    return 0;
}

void mostrarmarco()
{
    system("cls");
    printf("%c",201);

    for(int i = 0; i < 47; i++)
        printf("%c",205);
    printf("%c\n",187);
    for(int i = 0; i < 15; i++)
        printf("%c\t\t\t\t\t\t%c\n",186,186);

        printf("%c",200);
   for(int i = 0; i < 47; i++)
        printf("%c",205);
    printf("%c",188);
}
eSeleccionmenu Mostrarmenu()
{
    int seleccion;
    do
    {
        mostrarmarco();
        gotoxy(10,3);
        printf("GESTION DE PELICULAS");
        gotoxy(5,5);
        printf("1: Agregar una pelicula ");
        gotoxy(5,7);
        printf("2: Modificar una pelicula por su ID");
        gotoxy(5,9);
        printf("3: Eliminar una pelicula por su ID");
        gotoxy(5,11);
        printf("4: Agregar una pelicula por su a%co",164);
        gotoxy(5,13);
        printf("5: Explorar pelicula");
        gotoxy(5,15);
        printf("0: Salir");

        fflush(stdin);
        _setcursortype(0);
        seleccion = getch() - 48;

    }while(seleccion < 0 || seleccion > 6);

    _setcursortype(1);
    return seleccion;

}

void CapturarPelicula(Lista *listado, NODO *aModificar)
{
    short generosSeleccionados[] = {0,0,0,0,0,0,0,0,0};
    Pelicula nueva;
    int seleccion,i,j = 0;

    system("cls");
    mostrarmarco();
    gotoxy(10,3);
    if(aModificar == NULL)
     printf("Agregando nueva pelicula");
    else
     printf("Modificando Pelicula Existente");

    gotoxy(5,5);
    printf("Id: ");
    if(aModificar != NULL)
    {
        printf("%d",aModificar->data.Id);
        nueva.Id = aModificar->data.Id;
    }
    else
        scanf("%d",&nueva.Id);

    gotoxy(5,6);
    printf("Titulo: ");
    nueva.Titulo = (char*)malloc((100));
    fflush(stdin);
    gets(nueva.Titulo);
    gotoxy(5,7);
    printf("A%co: ",164);
    scanf("%d",&nueva.anno);


    do
    {
        gotoxy(50,2);
        printf("Seleccione una clasificacion: \n\t\t");
        gotoxy(50,3);
        printf("1: G (Proposito general)\n");
        gotoxy(50,4);
        printf("2: PG (Supervicion parental)\n");
        gotoxy(50,5);
        printf("3: PG-13 (No apta para menores de 13 a%cos)\n",164);
        gotoxy(50,6);
        printf("4: R (Restringido para mayores de edad)\n");
        gotoxy(50,7);
        printf("5: NC-17 (Solo adultos)\n");
        gotoxy(50,8);
        printf("Seleccion: ");
        seleccion = getch() - 48;
    }while(seleccion <= 0 || seleccion >= 6 );
    nueva.Clasificacion = (char*)calloc(6,sizeof(char));
    switch(seleccion)
    {
        case 1:
            strcpy(nueva.Clasificacion,"G");
            break;
        case 2:
            strcpy(nueva.Clasificacion,"PG");
            break;
        case 3:
            strcpy(nueva.Clasificacion,"PG-13");
            break;
        case 4:
            strcpy(nueva.Clasificacion,"R");
            break;
        case 5:
            strcpy(nueva.Clasificacion,"NC-17");
            break;
    }
    gotoxy(5,8);
    printf("Calificacion: ");
    scanf("%f",&nueva.Calificacion);
    gotoxy(5,9);
    printf("Duracion(minutos): ");
    scanf("%f",&nueva.Duracion);
    //Mostramos los generos

   do
   {
        do
        {
            gotoxy(50,7);
            printf("Seleccione los generos de la pelicula: \n");
            gotoxy(50,8);
            printf("1: Accion\t");
            printf("2: Aventura\t");
            printf("3: Comedia");
            gotoxy(50,9);
            printf("4: Drama\t");
            printf("5: Terror\t");
            printf("6: Musical");
            gotoxy(50,10);
            printf("7: Ciencia Ficcion\t");
            printf("8: Suspenso");
            printf("9: Infantil");
            printf("0: Salir");
            gotoxy(50,11);
            printf("Seleccion: ");
            seleccion = getch()-48;
       }while(seleccion < 0 || seleccion > 9);


       if(seleccion != 0 && generosSeleccionados[seleccion - 1] <= 0)
       {
           generosSeleccionados[seleccion - 1] - 1;
           j++;
       }

       else  if(seleccion != 0 && generosSeleccionados[seleccion - 1] > 0)
                {
                    generosSeleccionados[seleccion - 1] -1;
                    j--;

                }


   }while(seleccion != 0);

    nueva.CantidadGeneros = j;
    nueva.Generos = (char**)malloc(sizeof(char*)*j);

    for(i = 0; i < 9; i++)
    {
        if(generosSeleccionados[i])
        {
            j++;
            nueva.Generos = (char**)malloc(sizeof(char*));
            *(nueva.Generos+j) = (char*)calloc(20,sizeof(char));
            switch(i)
            {
                case 0:
                    strcpy(*(nueva.Generos+j),"Accion");
                    break;
                case 1:
                    strcpy(*(nueva.Generos+j),"Aventura");
                    break;
                case 2:
                    strcpy(*(nueva.Generos+j),"Comedia");
                    break;
                case 3:
                    strcpy(*(nueva.Generos+j),"Drama");
                    break;
                case 4:
                    strcpy(*(nueva.Generos+j),"Terror");
                    break;
                case 5:
                    strcpy(*(nueva.Generos+j),"Musical");
                    break;
                case 6:
                    strcpy(*(nueva.Generos+j),"Ciencia Ficcion");
                    break;
                case 7:
                    strcpy(*(nueva.Generos+j),"Suspenso");
                    break;
                case 8:
                    strcpy(*(nueva.Generos+j),"Infantil");
                    break;
            }
        }
    }
    gotoxy(5,10);
    printf("Sinopsis(200 Caracteres): ");
    nueva.Sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nueva.Sinopsis);

    if(aModificar == NULL)
    {
        AgregarPelicula(listado,nueva);
    }
    else
    {
        aModificar->data = nueva;
    }

    AgregarPelicula(listado,nueva);
}
void ExplorarPeliculas(Lista*listado)
{
    char seleccion;
    NODO*nodoactual = listado->Cabeza->siguiente;

    do
    {
        if(nodoactual->data.Id == -1)
          {
            MostrarMarco3Col();
            printf("No hay peliculas registradas");
            break;
          }
        MostrarPeliculaColumnoa(nodoactual->data, 2);
        if(nodoactual->anterior->data.Id == -1)
            MostrarPeliculaColumnoa(nodoactual->anterior->anterior->data,1);
        else
            MostrarPeliculaColumnoa(nodoactual->anterior->data,1);
        if(nodoactual->siguiente->data.Id == -1)
            MostrarPeliculaColumnoa(nodoactual->siguiente->siguiente->data,3);
        else
            MostrarPeliculaColumnoa(nodoactual->siguiente->data,3);

    fflush(stdin);
    printf("X para salir");
    seleccion = getch();
    if(tolower(seleccion) == 'a')
    {
        nodoactual = nodoactual->anterior;
        if(nodoactual->data.Id == -1)
            nodoactual = nodoactual->anterior;
    }
    else if(tolower(seleccion) == 'd')
    {
        nodoactual = nodoactual->siguiente;
        if(nodoactual->data.Id == -1)
            nodoactual = nodoactual->siguiente;
    }
    }while(tolower(seleccion) != 'x');
}
void MostrarMarco3Col()
{
  int i;
    system("cls");
    printf("%c",201);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",187);

    for(i = 2; i < 24; i++)
    {
        gotoxy(0,i);
        printf("%c",186);
        gotoxy(COL2,i);
        printf("%c",186);
        gotoxy(COL3,i);
        printf("%c",186);
        gotoxy(78,i);
        printf("%c\n",186);
    }
     printf("%c",200);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",188);

}

void MostrarPeliculaColumnoa(Pelicula aMostrar,int NumeroCol)
{
    int colActual,i = 0;

    if(NumeroCol == 1)
    {
        colActual = 0;
    }
    if(NumeroCol == 2)
    {
        colActual = COL2;
    }
    if(NumeroCol == 3)
     {
        colActual = COL3;
     }


    gotoxy(colActual++, 3);
    printf("%4.3d - %.*s",aMostrar.Id,LIMCOLUMNA,aMostrar.Titulo);
    gotoxy(colActual+1,5);
    printf("%4d - %.1f/10 - %.1fmins",aMostrar.anno,aMostrar.Calificacion,aMostrar.Duracion);
    gotoxy(colActual+1,7);
    printf("Clasif.: %.20s", aMostrar.Clasificacion);
    gotoxy(colActual+1,9);

    while(i < aMostrar.CantidadGeneros) //O NULL
    {
        printf("%.*s",LIMCOLUMNA,*(aMostrar.Generos+i));
        i++;
        gotoxy(colActual + 1, 9 + i);
    }
    gotoxy(colActual+1,10+i);
    mostrarsinopsis(colActual+1,10+i,LIMCOLUMNA,aMostrar.Sinopsis);
}
void mostrarsinopsis(int col,int fil,int lim,char*texto)
{
    int i = 0,tam = strlen(texto);
    char *nuevoTexto = (char*)malloc(sizeof(char)*tam);
    nuevoTexto = strcpy(nuevoTexto, texto);
    while(tam > 0)
    {
        gotoxy(col,fil+i);
        printf("%.*s",lim,nuevoTexto);
        nuevoTexto = strcpy(nuevoTexto,nuevoTexto+lim);

        i++;
        tam -= lim;
    }
    gotoxy(col,fil+i+1);
}

void ModificarPelicula(Lista *listadoPeliculas)
{
    int idPelicula;
    NODO *nodoactual;
    system("cls");
    mostrarmarco();
    gotoxy(10,3);
    printf("Modificando Pelicula existente.");
    gotoxy(5,7);
    printf("Digite el ID: ");
    scanf("%d",&idPelicula);
    nodoactual = BuscarporId(listadoPeliculas,idPelicula);

    if(nodoactual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pelicula no existe. Presione cualquier letra para continuar.");
        fflush(stdin);
        getch();
        return;
    }

}

void BorrarPelicula(Lista *listadoPeliculas)
{
    int idPelicula;
    NODO *nodoactual;
    system("cls");
    mostrarmarco();
    gotoxy(10,3);
    printf("Eliminar Pelicula existente.");
    gotoxy(5,7);
    printf("Digite el ID: ");
    scanf("%d",&idPelicula);
    nodoactual = BuscarporId(listadoPeliculas,idPelicula);

    if(nodoactual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pelicula no existe. Presione cualquier letra para continuar.");
        fflush(stdin);
        getch();
        return;
    }

    EliminarPelicula(listadoPeliculas,nodoactual);

}

void OrdenarPeliculasPorAnyo(Lista *listadoPeliculas)
{
    NODO* uno = listadoPeliculas->Cabeza->siguiente->siguiente;
    NODO* dos = listadoPeliculas->Cabeza->anterior->siguiente;

     printf("%d - %s // %d - %s", uno->data.Id, uno->data.Titulo, dos->data.Id, dos->data.Titulo);

     Intercambiar(uno, dos);

     uno = listadoPeliculas->Cabeza->siguiente;
     dos = listadoPeliculas->Cabeza->anterior;

     printf("%d - %s // %d - %s", uno->data.Id, uno->data.Titulo, dos->data.Id, dos->data.Titulo);

     fflush(stdin);
     getch();
}
