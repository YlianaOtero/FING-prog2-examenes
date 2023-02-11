#include <stdio.h>

/*Un árbol binario está parcialmente ordenado si para cada nodo del árbol se cumple que el valor de información
del nodo es menor o igual que el de todos los nodos que están en sus subárboles (izquierdo y derecho). El árbol
vacío está parcialmente ordenado.
Considere la siguiente declaración de nodos de árboles binarios de enteros:*/

struct ABNode
{
    int info;
    ABNode *left;
    ABNode *right;
};

/*Implemente la función recursiva ordParcial que dado un árbol binario de enteros retorne true si y solo si el 
árbol está parcialmente ordenado. No se permite definir y usar operaciones auxiliares propias.*/

bool ordParcial (ABNode * t) {
    bool ordenado = true;

    if (t != NULL) {
        ABNode * izq = t->left;
        ABNode * der = t->right;
        bool ordActual = true;

        if (izq != NULL && der != NULL) {
            ordActual = t->info <= izq->info && t->info <= der->info;
            ordenado =  ordActual && ordParcial(izq) && ordParcial(der);
        } else if (izq != NULL) {
            ordActual = t->info <= izq->info;
            ordenado =  ordActual && ordParcial(izq);
        } else if (der != NULL) {
            ordActual = t->info <= der->info;
            ordenado =  ordActual && ordParcial(der);
        }
    }

    return ordenado;
}


