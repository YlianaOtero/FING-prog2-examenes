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

void enlistarMenores(ABB a, int k, LISTA &l) {
    if (a != NULL) {
        if (a->dato < k) {
            enlistarMenores(a->der, k, l);

            insertarAlInicio(a->dato, l);
        } 
        enlistarMenores(a->izq, k, l);
    }
}

void insertarAlInicio(int elem, LISTA &l) {
    LISTA nodo = new nodo_Lista;
    nodo->dato = elem;
    nodo->sig = l;
    l = nodo;
}

LISTA listaOrdenada(ABB a, int k) {
    LISTA resultado = NULL;

    enlistarMenores(a, k, resultado);

    return resultado;
}

/*e) Dos árboles binarios de búsqueda son similares si contienen los mismos elementos. Usando las
operaciones desarrolladas anteriormente (partes c) y d)), implemente una función que retorne true
si y sólo si dos árboles binarios de búsqueda son similares: bool similares(ABB a, ABB b).*/

void borrarLista(LISTA &l) {
    while (l != NULL) {
        LISTA aux = l;
        l = l->sig;
        delete aux;
    }
}

bool similares(ABB a, ABB b) {
    bool mismosElementos = true;
    
    if (a != NULL && b != NULL) {
        int maximoA = maximo(a);
        int maximoB = maximo(b);

        if (maximoA == maximoB) {
            LISTA menoresA = listaOrdenada(a, maximoA);
            LISTA menoresB = listaOrdenada(b, maximoB);

            LISTA auxA = menoresA;
            LISTA auxB = menoresB;

            while (mismosElementos && auxA != NULL && auxB != NULL) {
                mismosElementos = auxA->dato == auxB->dato;
                auxA = auxA->sig;
                auxB = auxB->sig;
            };

            mismosElementos = mismosElementos && (auxA == NULL) && (auxB == NULL);

            borrarLista(menoresA);
            borrarLista(menoresB);
        }

    } else if ((a != NULL && b == NULL) || (a == NULL && b != NULL)) {
        mismosElementos = false;
    }

    return mismosElementos;
}

/*f) Explique brevemente cuál es el orden de tiempo de ejecución en peor caso de la función similares
desarrollada en e)*/
/*Es O(n+m), siendo n la cantidad de nodos de a, y m la cantidad de nodos de b. Esto se debe a que debe
llamarse a la funcion maximo para a y para b, la cual en el peor caso es O(n) y O(m) respectivamente. Luego,
debe llamarse a listaOrdenada para a y para b, la cual en el peor caso tambien es O(n) y O(m) respectivamente.
Luego, se recorren las listas creadas, hasta que se viole la condicion del while. Supongamos que ambas listas
tienen la misma cantidad de elementos (m, por ejemplo), y que la condicion solo se viola en el ultimo elemento,
siendo este distinto en ambas listas: esta recorrida costo O(m).
Por lo tanto, la funcion similares es O(n+m).*/