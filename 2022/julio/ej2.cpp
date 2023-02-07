#include <stdio.h>

/*Considere la siguiente definición del tipo ABB de los árboles binarios de búsqueda de enteros sin elementos repetidos , en memoria dinámica:*/

typedef struct nodoABB *ABB;
struct nodoABB
{
    int dato;
    ABB izq, der;
};

/*Implemente un procedimiento insertarMenores que dados dos ABB t1 y t2, y dado un entero x, inserte en t2 los
elementos de t1 que sean menores estrictos a x. Si no hay elementos menores a x en t1 (en particular si t1 es vacío),
el procedimiento no tendrá efecto. La función deberá evitar recorrer elementos de t1 que no sean estrictamente necesarios.
Si usa operaciones auxiliares, deberá implementarlas*/

ABB insertarNodo(ABB t, int dato) {
    if (t != NULL) {
        if (t->dato < dato) {
            t->der = insertarNodo(t->der, dato);
        } else if (t->dato > dato) {
            t->izq = insertarNodo(t->izq, dato);
        } 
    } else {
        ABB nuevoNodo = new nodoABB;
        nuevoNodo->dato = dato;
        t = nuevoNodo;
        t->izq = NULL;
        t->der = NULL;
    }

    return t;
}

void insertarMenores(ABB t1, ABB &t2, int x) {
    if (t1 != NULL) {
        if (t1->dato >= x) {
            insertarMenores(t1->izq, t2, x);
        } else {
            t2 = insertarNodo(t2, t1->dato);
            insertarMenores(t1->izq, t2, x);
            insertarMenores(t1->der, t2, x);
        } 
    }
}

/* ############################################################################################# 
                                         PRUEBAS
   ############################################################################################# */

void imprimirArbolAux(ABB t, int espacio)
{
    if (t == NULL)
        return;
 
    //Distancia entre los niveles
    espacio += 2;
 
    imprimirArbolAux(t->der, espacio);

    printf("\n");
    for (int i = 2; i < espacio; i++)
        printf(" ");
    printf("%d\n", t->dato);

    imprimirArbolAux(t->izq, espacio);
}
 
void imprimirArbol(ABB t)
{
    imprimirArbolAux(t, 0);
}
 

int main() {
    ABB arbol = new nodoABB;
    arbol->dato = 4;
    arbol->izq = NULL;
    arbol->der = NULL;

    for (int i = 0; i < 10; i++) {  
        arbol = insertarNodo(arbol, i);
        arbol = insertarNodo(arbol, i*3);
        
    }

    for (int i = 2; i > -4; i--) {  
        arbol = insertarNodo(arbol, i);
        arbol = insertarNodo(arbol, i-9);
    }

    printf("PRIMER ARBOL: \n");
    imprimirArbol(arbol);

    ABB arbol2 = new nodoABB;

    insertarMenores(arbol, arbol2, 3);

    printf("\nSEGUNDO ARBOL: \n");
    imprimirArbol(arbol2);
}

