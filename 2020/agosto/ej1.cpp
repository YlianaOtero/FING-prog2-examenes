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

Lista comunes(Lista l1, Lista l2)
{
    Lista resultado = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dato == l2->dato) {
            Lista nuevoNodo = new nodo;
            nuevoNodo->dato = l1->dato;
            nuevoNodo->sig = resultado;
            resultado = nuevoNodo;
            
        } else if (l1->dato > l2->dato) {
            l2 = l2->sig;
        } else {
            l1 = l1->sig;
        }
    };

    return resultado;
}

/*b) Justifique brevemente el cumplimiento del orden del peor caso O(n+m) para la función comunes.*/
/*En el peor de los casos, la función comunes recorre ambas listas una única vez, pues va recorriendo hasta que una de las dos es vacía, 
y una vez se llega a esta condición, no vuelve a recorrer nada.  Recorrer l1 es O(n), mientras que recorrer l2 es O(m).
El resto de las operaciones que hace la función son comparaciones y asignaciones, por lo que no aumentan el orden de ejecución.*/