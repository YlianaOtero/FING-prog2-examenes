#include <stdio.h>

/*a) Implemente una función iterativa comunes en C/C++ que dadas dos listas de enteros ordenadas de menor
a mayor y sin elementos repetidos, construya y retorne una nueva lista ordenada de mayor a menor y sin
elementos repetidos que contenga todos los elementos que pertenecen a ambas listas. La lista resultante no
debe compartir memoria con las listas parámetro. Notar que si una de las listas es vacía o si no tienen
elementos en común, el resultado debe ser la lista vacía. La función debe tener O(n+m) de tiempo de
ejecución en el peor caso, siendo n y m los largos de las listas parámetro.
Por ejemplo, si las listas son [1,3,4,8] y [1,2,4,6,7,8,9], el resultado debería ser: [8,4,1]*/
typedef nodo *Lista;
struct nodo
{
    int dato;
    Lista sig;
};

Lista copia(Lista l) {
    Lista nueva = NULL;

    if (l != NULL) {
        Lista nuevoNodo = new nodo;
        nuevoNodo->dato = l->dato;
        nueva = nuevoNodo;
        nueva->sig = NULL;
        nueva = nueva->sig;
        l = l->sig;

        while (l != NULL) {
            nuevoNodo = new nodo;
            nuevoNodo->dato = l->dato;
            nueva = nuevoNodo;
            nueva->sig = NULL;
            nueva = nueva->sig;
            l = l->sig;
        }
    }

    return nueva;
}

Lista comunes(Lista l1, Lista l2)
{
    Lista resultado;

    if (l1 == NULL) {

    };

    return resultado;
}