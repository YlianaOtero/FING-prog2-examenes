#include <stdio.h>

/*a) Implemente un procedimiento iterativo insFinal que dados una lista de enteros l y un entero e,
agregue a e al final de l. Si la lista es vacía, lo insertará como único elemento de ésta.*/
struct nodo
{
    int dato;
    nodo *sig;
};

typedef nodo *Lista;

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

/*b) Dada la siguiente función iterativa copia en C++ que, dada una lista de enteros l devuelve una copia
idéntica de l sin compartir memoria con ésta:*/

Lista copia(Lista l)
{
    Lista resultado = NULL;
    while (l != NULL)
    {
        insFinal(resultado, l->dato);
        l = l->sig;
    }
    return resultado;
};

/*Calcule el orden de tiempo de ejecución en el peor caso de la función copia. Justifique brevemente.*/

/*Tomemos n como la cantidad de elementos de la lista parametro.
La funcion insFinal es O(n) en el peor caso porque para insertar un elemento en la lista, necesita
recorrer toda la lista hasta el final.
La funcion copia es O(n'2) en el peor caso porque va recorriendo toda la lista pasada por parametro (esto
es O(n)) y por cada elemento de la lista, llama a insFinal, que es O(n).*/

/*c) Sin usar el procedimiento insFinal ni otras estructuras auxiliares, implemente la función
copiaEficiente para construir la copia de una lista, sin compartir memoria, en un menor orden de
tiempo de ejecución en el peor caso que la función copia. Calcule el orden del peor caso y justifique
brevemente.*/

Lista copiaEficiente(Lista l)
{
    Lista resultado = NULL;

    if (l != NULL)
    {
        nodo *nuevo = new nodo;
        nuevo->dato = l->dato;
        nuevo->sig = NULL;

        resultado = nuevo;

        Lista auxRes = resultado;
        resultado->sig = auxRes;

        while (l->sig != NULL)
        {
            nodo *nuevo = new nodo;
            nuevo->dato = l->sig->dato;
            auxRes->sig = nuevo;
            l = l->sig;
            auxRes = auxRes->sig;
        }
    }

    return resultado;
};

/*PRUEBAS*/
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