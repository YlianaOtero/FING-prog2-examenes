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
};

typedef nodo * ABB;

struct RepMultiset {
    int K;
    ABB abb;
};

Multiset crear(){
    Multiset nuevo = new RepMultiset;
    ABB arbol = new nodo;
    arbol = NULL;

    nuevo->K = K;
    nuevo->abb = arbol;

    return nuevo;
};

void insertar (Multiset & m, int x, int n) {

};

