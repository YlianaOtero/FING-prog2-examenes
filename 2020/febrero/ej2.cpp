#include <stdio.h>
/*Considere un árbol general de enteros representado mediante un árbol binario de enteros con la semántica:
puntero al primer hijo (pH), puntero al siguiente hermano (sH).*/

struct nodoAG
{
    int dato;
    nodoAG *pH, *sH;
};

typedef nodoAG *AG;

/*Implemente un procedimiento recursivo impDesdeNivel(AG a, int k) que imprima los elementos del árbol a
que se encuentran en un nivel mayor o igual a k, en cualquier orden. Considere que la raíz del árbol se
encuentra en el nivel 1. No se pueden definir operaciones auxiliares para implementar impDesdeNivel.*/

void impDesdeNivel(AG a, int k) {
    if (a != NULL) {
        if (k > 1) {
            impDesdeNivel(a->pH, k-1);
            impDesdeNivel(a->sH, k);
        } else {
            printf("%d", a->dato);
            impDesdeNivel(a->sH, k);
            impDesdeNivel(a->pH, k-1);
        }
    }
}