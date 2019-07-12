#include <stdlib.h>
#ifndef _LISTACIRCULARH
#define _LISTACIRCULARH

typedef struct
{
    int Id;
    char *Titulo;
    int anno;
    char *Clasificacion;
    float Calificacion;
    float Duracion;
    int CantidadGeneros;
    char **Generos;
    char *Sinopsis;

}Pelicula;

typedef struct sNodo
{
    Pelicula data;
    struct sNodo *anterior;
    struct sNodo *siguiente;

}NODO;

typedef struct
{
    NODO *Cabeza;
    int Cantidad;
}Lista;


Lista* Inicializar();
void AgregarPelicula(Lista*,Pelicula);
void EliminarPelicula(Lista *,NODO *);
void InsertarPelicula(Lista*,Pelicula, int);
NODO* BuscarporId(Lista*,int);
NODO* BuscarPelicula(Lista*,int);
Lista* OrdenarPelicula(Lista*);
NODO* CopiarNodo(NODO *original);
void Intercambiar(NODO*, NODO*);

#endif // _LISTACIRCULARH
