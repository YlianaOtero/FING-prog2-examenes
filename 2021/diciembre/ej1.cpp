#include <stdio.h>

/*Se debe implementar una función que, dado un árbol general de elementos de un tipo genérico, G, para
cada nodo que tiene hijos rota sus subárboles dejando al final el que era primero, y manteniendo el orden
relativo de los restantes.*/

typedef int G;
struct repT
{
    G dato;
    struct repT *ph;
    struct repT *sh;
};

typedef struct repT *Tree;

/* Rota los subárboles de cada nodo de T y devuelve el resultado de la transformación.*/
// Tree rotar(Tree T);

/* (a) Implemente una función iterativa que aplica la rotación descrita solo al nodo pasado por parámetro (no
a sus subárboles). */

/*Devuelve el árbol resultado de mover el primer subárbol de 'T' dejándolo como su último subárbol.
Pre: T != NULL.*/
Tree moverPrimero(repT *T)
{
    if ((T->ph != NULL) && (T->ph->sh != NULL)) {
        repT * aMover = T->ph;
        T->ph = T->ph->sh;
        aMover->sh = NULL;
        repT * cursor = T->ph;
        while (cursor->sh != NULL) {
            cursor = cursor->sh;
        }
        cursor->sh = aMover;
    }

    return T;
};

Tree rotar(Tree T)
{
    if (T != NULL)
    {
        T = moverPrimero(T);
        T->ph = rotar(T->ph);
        T->sh = rotar(T->sh);
    }

    return T;
}


int main()
{
    Tree t = new repT;
    t->dato = 1;
    t->sh = NULL;

    t->ph = new repT;
    t->ph->dato = 2;
    t->ph->sh = new repT;
    t->ph->sh->dato = 3;
    t->ph->sh->sh = new repT;
    t->ph->sh->sh->dato = 4;
    t->ph->sh->sh->sh = NULL;
    
    Tree aux = t;

    printf("PRIMER NIVEL ARBOL ORIGINAL: \n");
    printf("%d", t->dato);
    printf("\n");

    printf("SEGUNDO NIVEL ARBOL ORIGINAL: \n");
    printf("%d", t->ph->dato);
    printf(" ");

    t = t->ph;

    while (t->sh != NULL)
    {
        t = t->sh;
        printf("%d", t->dato);
        printf(" ");
    }

    printf("\n");

    Tree rotado = moverPrimero(aux);

    printf("PRIMER NIVEL ARBOL ROTADO: \n");
    printf("%d", rotado->dato);
    printf("\n");


    printf("SEGUNDO NIVEL ARBOL ROTADO: \n");
    printf("%d", rotado->ph->dato);
    printf(" ");

    rotado = rotado->ph;

    while (rotado->sh != NULL)
    {
        rotado = rotado->sh;
        printf("%d", rotado->dato);
        printf(" ");
    }

    printf("\n");
}
