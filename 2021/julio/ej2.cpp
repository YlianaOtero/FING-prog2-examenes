#include <stdio.h>

/*Considere el TAD Cola no acotada de enteros (ColaInt), que contempla la política FIFO, con operaciones 
exclusivamente para: crear una cola vacía; insertar; eliminar y retornar el elemento correspondiente; y chequear 
si una cola está vacía.
a)Especifique el Tad ColaInt, incluyendo sus pre y postcondiciones.*/
struct rep_Cola;
typedef rep_Cola * ColaInt;

//POS: Crea una cola vacia.
ColaInt crearCola();

//POS: Devuelve true si la cola esta vacia, y false en caso contrario.
bool esVacia(ColaInt cola);

//POS: Inserta un elemento al final de la cola.
void encolar(int elem, ColaInt &cola);

//PRE: !esVacia(cola);
//POS: Elimina el primer elemento de la cola.
void desencolar(ColaInt &cola);

//PRE: !esVacia(cola);
//POS: Devuelve el primer elemento de la cola.
int frente(ColaInt cola);


/*b)Implemente la función: ColaInt camino (ABB t, int x), que dado un árbol binario de búsqueda (ABB) de 
enteros ‘t’ y un entero ‘x’, retorne una cola de tipo ColaInt que contenga el camino a ‘x’ desde la raíz de ‘t’. 
En la cola resultado el primero debe corresponder a la raíz de ‘t’ y el último elemento, según la política FIFO, 
debe ser ‘x’. Si ‘x’ no está en ‘t’, el resultado deberá ser la cola vacía. La operación camino no puede acceder 
a la representación del TAD ni modificar sus parámetros. Considere:*/
typedef struct nodoABB * ABB;
struct nodoABB { int dato; ABB izq, der; };

void caminoAux (ABB t, int x, ColaInt &cola) {
    if (t != NULL) {
        encolar(t->dato, cola);

        if (t->dato > x) {
            caminoAux(t->izq, x, cola);
        } else if (t->dato < x) {
            caminoAux(t->der, x, cola);
        }

    } else {
        while (!esVacia(cola)) {
            desencolar(cola);
        }
    }
}

ColaInt camino (ABB t, int x) {
    ColaInt cola = crearCola();

    if (t != NULL) {
        caminoAux(t, x, cola);
    }

    return cola;
}

/*c)Sugiera una implementación eficiente del TAD ColaInt, definiendo la representación del TAD e 
implementando solamente sus operaciones constructoras; asuma que el resto de las operaciones del TAD 
están implementadas eficientemente.*/

/*Usamos una lista simplemente encadenada, con un cabezal con punteros al primero y ultimo nodo.*/
struct nodo {
    int dato;
    nodo * sig;
};

struct rep_Cola {
    nodo * primero;
    nodo * ultimo;
};


ColaInt crearCola() {
    ColaInt nueva = new rep_Cola;
    nueva->primero = NULL;
    nueva->ultimo = NULL;

    return nueva;
};

void encolar(int x, ColaInt &cola) {
    nodo * nuevo = new nodo;
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (esVacia(cola)) {
        cola->primero = nuevo;
        cola->ultimo = nuevo;
    } else {
        cola->ultimo->sig = nuevo;
        cola->ultimo = nuevo;
    }
}