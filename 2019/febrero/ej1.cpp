#include <stdio.h>
/*a) Defina una estructura de tipo LISTA que represente el tipo de datos listas de enteros en memoria
dinámica, simplemente encadenadas.*/
struct nodo_Lista {
    int dato;
    nodo_Lista * sig;
};

typedef nodo_Lista * LISTA;

/*b) Defina una estructura de tipo ABB que represente el tipo de datos árboles binarios de búsqueda de
enteros en memoria dinámica*/
struct nodo_ABB {
    int dato;
    nodo_ABB * izq;
    nodo_ABB * der;
};

typedef nodo_ABB * ABB;

/*c) Implemente una función int maximo(ABB a) que dado un árbol binario de búsqueda a de tipo ABB
no vacío, retorne el valor máximo que contiene. La función debe evitar recorrer nodos de a que no
sean estrictamente necesarios.*/

int maximo(ABB a) {
    int max = a->dato;

    while (a->der != NULL) {
        max = a->der->dato;
        a = a->der;
    };

    return max;
}

/*d) Implemente una función Lista listaOrdenada(ABB a, int k) que dado un árbol binario de búsqueda
a de tipo ABB, retorne una lista de enteros ordenada de menor a mayor que contenga todos los
elementos de a menores a k. Si no hay elementos de a menores a k la función debe retornar la lista
vacía. Puede utilizar operaciones auxiliares, que deberá implementar. La función debe tener tiempo
de ejecución O(n) en el peor caso, siendo n la cantidad de nodos del árbol a, y debe evitar recorrer
nodos de a que no sean estrictamente necesarios.*/

void enlistar(ABB a, int k, LISTA &l) {
    if (a != NULL) {
        if (a->dato < k) {
            enlistar(a->izq, k, l);

            if (l != NULL) {
                l->sig->dato = a->dato;
            } else {
                l = new nodo_Lista;
                l->dato = a->dato;
            }

            
        }
    }
}

LISTA listaOrdenada(ABB a, int k) {
    LISTA resultado = NULL;

    

    return resultado;
}