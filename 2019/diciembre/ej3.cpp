#include <stdio.h>
/*Implemente una función recursiva que a todos los nodos de un nivel dado de un árbol general le agrega
como primer hijo un elemento pasado como parámetro. La raíz está en el nivel 1.*/
struct Nodo {
    int elem;
    Nodo * pH;
    Nodo * sH;
};

typedef Nodo * Arbol;

/*PRE: nivel > 0.*/
void insertar (int elem, int nivel, Arbol &a) {
    if (a != NULL) {
        if (nivel > 1) {
            insertar(elem, nivel-1, a->pH);
        } else {
            Nodo * nuevo = new Nodo;
            nuevo->elem = elem;
            nuevo->pH = NULL;
            Arbol primerHijo = a->pH;
            nuevo->sH = primerHijo;
            a->pH = nuevo;
        }
        insertar(elem, nivel, a->sH);
    }
}