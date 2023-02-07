#include <stdio.h>

/*Considere un árbol general de enteros representado mediante un árbol binario de enteros con la semántica: puntero
al primer hijo (pH), puntero al siguiente hermano (sH).
Implemente la función bool existeNodo (AG t, int n) que retorne true si y solo si en el árbol t existe
al menos un nodo que tiene n o más hijos, asumiendo n>0 y t->sH==NULL. Si utiliza operaciones auxiliares,
deberá implementarlas. La función existeNodo debe tener O(m) en el peor caso, siendo m la cantidad de nodos
de t*/

typedef struct nodoAG *AG;
struct nodoAG
{
    int dato;
    nodoAG *pH, *sH;
};

int hijos(AG t)
{
    int cantHijos = 0;
    t = t->pH;
    while (t != NULL)
    {
        cantHijos++;
        t = t->sH;
    }
    return cantHijos;
}

int cantHijos(AG t, int contador)
{
    if (t->pH != NULL && contador == 0)
    {
        contador += 1 + cantHijos(t->pH, contador);
    }
    else if (contador > 0 && t->sH != NULL)
    {
        contador += 1 + cantHijos(t->sH, contador);
    };

    return contador;
};

bool existeNodo(AG t, int n)
{
    bool existe = false;

    if (t != NULL)
    {
        existe = hijos(t) >= n || existeNodo(t->pH, n) || existeNodo(t->sH, n);
    };

    return existe;
};

AG crearArbol(int info)
{
    AG t = new nodoAG;
    t->dato = info;
    t->sH = NULL;
    t->pH = NULL;

    return t;
};

void agregarNodo(AG t, int info)
{
    AG nuevoNodo = crearArbol(info);
    AG aux = t;

    if (t->pH == NULL)
    {
        t->pH = nuevoNodo;
    }
    else
    {

        aux = t->pH;

        while (aux->sH != NULL)
        {
            aux = aux->sH;
        }

        aux->sH = nuevoNodo;
    }
};

int main()
{
    AG t = crearArbol(-1);
    AG aux = t;

    for (int i = 0; i < 2; i++)
    {
        agregarNodo(aux, i);
    }

    bool existeConUno = existeNodo(t, 1);
    bool existeConDos = existeNodo(t, 2);
    bool existeConTres = existeNodo(t, 3);
    bool existeConCuatro = existeNodo(t, 4);
    bool existeConCinco = existeNodo(t, 5); 

    if (existeConUno)
    {
        printf("Existe al menos un nodo con al menos un hijo. ");
    };
    if (existeConDos)
    {
        printf("Existe al menos un nodo con al menos dos hijos. ");
    };
     if (existeConTres)
    {
        printf("Existe al menos un nodo con al menos tres hijos. ");
    };
    if (existeConCuatro)
    {
        printf("Existe al menos un nodo con al menos cuatro hijos. ");
    };
    if (existeConCinco)
    {
        printf("Existe al menos un nodo con al menos cinco hijos. ");
    };  
}
