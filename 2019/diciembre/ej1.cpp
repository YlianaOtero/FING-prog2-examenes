#include <stdio.h>
/*Implemente una función iterativa que remueve todas las ocurrencias de un elemento en una lista ordenada.*/

struct Nodo {
    int elem;
    Nodo * sig;
};

typedef Nodo * Lista;

/* Remueve todas las ocurrencias de 'rem ' en ' l ' .
Si 'rem ' no está en ' l ' la operación no tiene efecto.
PRE: ' l ' está ordenada de manera no decreciente .*/
void removerTodos (int rem, Lista &l) {
    Lista aux = new Nodo;
    aux->sig = l;
    Lista iter = aux;

    while (iter->sig != NULL && iter->sig->elem < rem) {
        iter = iter->sig;
    };
    while (iter->sig != NULL && iter->sig->elem == rem) {
        Lista aBorrar = iter->sig;
        iter->sig = iter->sig->sig;
        delete aBorrar;
    };

    l = aux->sig;
 
    delete aux;
};


/*PRUEBAS*/
void insFinal(Lista &l, int e)
{
    Nodo *nuevo = new Nodo;
    nuevo->elem = e;
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
    Lista nueva = new Nodo;
    nueva = NULL;

    for (int i = 0; i < 10; i++)
    {
        insFinal(nueva, i);
        if (i == 0) {
            insFinal(nueva, i);
            insFinal(nueva, i);
            insFinal(nueva, i);
        }
    };

    Lista aux = nueva;
    printf("LISTA ORIGINAL: \n");

    while (aux != NULL)
    {
        printf("%d", aux->elem);
        printf("\n");
        aux = aux->sig;
    };

    printf("AL ELEMINAR TODAS LAS OCURRENCISA DE 0: \n");

    Lista aux2 = nueva;

    removerTodos(0, aux2);

    while (aux2 != NULL)
    {
        printf("%d", aux2->elem);
        printf("\n");
        aux2 = aux2->sig;
    };

    

}