#include <stdio.h>
/*Considere la siguiente especificación del TAD Multiset no acotado de números enteros en el rango 1..K,
para una constante K dada:*/

struct RepMultiset;
typedef RepMultiset * Multiset;

// POS: Devuelve el multiset vacío.
Multiset crear();

// POS: Agrega n ocurrencias del elemento x al multiset m. PRE: n>0, 1<=x<=K.
void insertar (Multiset & m, int x, int n);

// POS: Devuelve la suma total de ocurrencias de todos los elementos del multiset m (0 si m está vacío).
int cantidad (Multiset m);

// POS: Devuelve la cantidad de ocurrencias del elemento x del multiset m (0 si x no está en m).
int ocurrencias (Multiset m, int x);

/* POS: Elimina a lo sumo n ocurrencia del elemento x del multiset m. Si ocurrencias(m, x)<=n entonces
en m no quedarán ocurrencias del elemento x. */
void eliminar (Multiset & m, int x, int n);

// POS: Devuelve el mínimo elemento del multiset m (independientemente del número de ocurrencias).
// PRE: m no vacío.
int min (Multiset m);

/*Se quiere implementar el TAD Multiset anterior de tal manera que las operaciones insertar, ocurrencias y
eliminar tengan O(log(n)) de tiempo de ejecución en el caso promedio, siendo n la cantidad de elementos
diferentes del multiset, y las operaciones crear, cantidad y min tengan O(1) peor caso. Además, eliminar
deberá liberar la memoria correspondiente. La implementación debe hacerse en espacio O(n).
Se pide:
a) Defina en C++ la representación del TAD y escriba los códigos de las operaciones crear, insertar y
min. Omita el código del resto de las operaciones, que puede asumir están implementadas.*/
const int K = 10; //por ejemplo

struct nodo {
    int dato;
    nodo * izq;
    nodo * der;
    int cant;
};

typedef nodo * ABB;

struct RepMultiset {
    ABB abb;
    int min;
    int cant;
};

Multiset crear(){
    Multiset nuevo = new RepMultiset;
    ABB arbol = NULL;

    nuevo->cant = 0;
    nuevo->abb = arbol;

    return nuevo;
};

void insAbb(ABB &t, int x, int n) {
    if (t == NULL) {
        ABB nodoNuevo = new nodo;
        nodoNuevo->dato = x;
        nodoNuevo->izq = NULL;
        nodoNuevo->der = NULL;
        nodoNuevo->cant = n;
    } else {
        if (t->dato < x) {
            insAbb(t->der, x, n);
        } else if (t->dato > x) {
            insAbb(t->izq, x, n);
        } else {
            t->cant += n;
        }
    }
}

void insertar (Multiset & m, int x, int n) {
    if (m->abb == NULL || m->min > x) {
        m->min = x;
    } 

    insAbb(m->abb, x, n);
    m->cant += n;
};


int min (Multiset m) {
    return m->min;
};

/*b) Implemente el procedimiento vaciar que dado un multiset m, según la especificación dada
previamente, elimine todos sus elementos, dejando a éste vacío. El procedimiento vaciar no debería
acceder a la representación del TAD ni dejar memoria colgada (sin liberar).*/

void vaciar (Multiset & m) {
    int cantTotal = cantidad(m);
    int minimo = min(m);

    if (cantTotal > 0) {
        eliminar(m, minimo, cantTotal);
        vaciar(m);
    } else {
        delete m;
    }
};