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
//Tree rotar(Tree T);

/* (a) Implemente una función iterativa que aplica la rotación descrita solo al nodo pasado por parámetro (no
a sus subárboles). */

/*Devuelve el árbol resultado de mover el primer subárbol de 'T' dejándolo como su último subárbol.
Pre: T != NULL.*/
Tree moverPrimero(repT *T) {
    Tree primero = T->ph;
    Tree auxPrimero = primero;
    Tree auxSegundo = T->sh;

    T->ph = T->sh;

    Tree auxHermano = auxPrimero->sh;
    
    while (auxPrimero->sh != NULL) {
        auxHermano = auxPrimero->sh;
        auxPrimero = auxHermano;
        auxHermano = auxHermano->sh;
    }

    Tree auxUltimo = auxPrimero;
    T->ph = auxHermano;
    auxHermano = auxUltimo;


    return T;
};

Tree rotar(Tree T) {
    if (T != NULL) {
        T = moverPrimero(T);
        T->ph = rotar(T->ph);
        T->sh = rotar(T->sh);
    }

    return T;
}

Tree crearArbol(int info)
{
    Tree t = new repT;
    t->dato = info;
    t->sh = NULL;
    t->ph = NULL;

    return t;
};

void agregarNodo(Tree t, int info, bool pH)
{
    Tree nuevoNodo = crearArbol(info);
    Tree aux = t;

    if (pH)
    {
        t->ph = nuevoNodo;
    }
    else
    {

      //  if (t->ph != NULL) aux = t->ph;


        while (aux->sh != NULL)
        {
            aux = aux->sh;
        }

        aux->sh = nuevoNodo;
    }
};

int main()
{
    Tree t = crearArbol(-1);
    Tree aux = t;

    agregarNodo(aux, 19, true);
    

    for (int i = 0; i < 4; i++)
    {
        agregarNodo(t, i, false);
    }

    Tree rotado = moverPrimero(t);

    printf("PRIMER NIVEL ARBOL ORIGINAL: \n");
    printf("%d", t->dato);
    printf("\n");

    printf("PRIMER NIVEL ARBOL ROTADO: \n");
    printf("%d", rotado->dato);
    printf("\n");

    printf("SEGUNDO NIVEL ARBOL ORIGINAL: \n");
    printf("%d", t->ph->dato);
    printf(" ");

    while(t->sh != NULL) {
        t = t->sh;
        printf("%d", t->dato);
        printf(" ");
    }

    printf("\n");

    printf("SEGUNDO NIVEL ARBOL ROTADO: \n");
    printf("%d", rotado->ph->dato);
    printf(" ");

    while(rotado->sh != NULL) {
        rotado = rotado->sh;
        printf("%d", rotado->dato);
        printf(" ");
    }

    printf("\n");



 
}
