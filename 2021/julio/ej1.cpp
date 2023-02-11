#include <stdio.h>

/*Considere un árbol general de enteros representado mediante un árbol binario de enteros con la semántica:
puntero al primer hijo (pH), puntero al siguiente hermano (sH)*/
typedef struct nodoAG *AG;
struct nodoAG
{
    int dato;
    AG pH, sH;
};

/*Implemente la función AG padre(AG a, int x) que retorne un puntero al nodo padre en a del nodo que tenga a x
como dato. Asumimos que a no tiene elementos repetidos. Si x no está en a o si x es la raíz de a, la función
padre deberá retornar el puntero NULL. No se pueden definir operaciones auxiliares para implementar padre.*/
AG padre(AG a, int x)
{
    AG nodoPadre = NULL;
    bool encontrado = false;

    if (a != NULL && a->dato != x)
    {
        AG ph = a->pH;
        
        if (ph != NULL && ph->dato == x)
        {
            nodoPadre = a;
        }

        encontrado = ph->dato == x;

        while (!encontrado && ph->sH != NULL)
        {
            ph = ph->sH;
            encontrado = ph->dato == x;
        }

        if (encontrado)
        {
            nodoPadre = a;
        }
        else
        {
            nodoPadre = padre(a->pH, x);
            if (nodoPadre == NULL)
            {
                nodoPadre = padre(a->sH, x);
            }
        }
    };

    return nodoPadre;
}