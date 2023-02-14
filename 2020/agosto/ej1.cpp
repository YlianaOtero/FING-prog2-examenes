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
    Lista aux = resultado;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dato == l2->dato) {
            Lista nuevoNodo = new nodo;
            nuevoNodo->dato = l1->dato;
            resultado = nuevoNodo;

            if (aux == NULL) {
                resultado->sig = NULL;
            } else {
                aux = resultado;
                resultado->sig = nuevoNodo;
            }
        } else if (l1->dato > l2->dato) {
            l2 = l2->sig;
        } else {
            l1 = l1->sig;
        }
    };

    

    return resultado;
}


/*PRUEBAS*/

void insFinal(Lista &l, int e)
{
    nodo *nuevo = new nodo;
    nuevo->dato = e;
    nuevo->sig = NULL;

    if (l != NULL)
    {
        Lista aux = l;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        };

        aux->sig = nuevo;
    }
    else
    {
        l = nuevo;
    }
};

int main()
{
    Lista nueva = new nodo;
    nueva = NULL;

    for (int i = 0; i < 10; i++)
    {
        insFinal(nueva, i);
    };

    Lista aux = nueva;
    printf("LISTA ORIGINAL: \n");

    while (aux != NULL)
    {
        printf("%d", aux->dato);
        printf("\n");
        aux = aux->sig;
    };

    Lista copiaRapida = copiaEficiente(nueva);

    printf("COPIA EFICIENTE: \n");

    while (copiaRapida != NULL)
    {
        printf("%d", copiaRapida->dato);
        printf("\n");
        copiaRapida = copiaRapida->sig;
    };

}