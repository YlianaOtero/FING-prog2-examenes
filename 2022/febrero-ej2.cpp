#include <stdio.h>

/*Implemente un procedimiento que recibe como parámetro de entrada un árbol binario de enteros a e imprime la
suma de los valores de cada nivel de a. El tiempo de ejecución en el peor caso del procedimiento debe ser O(n),
siendo n la cantidad de elementos a. Brinde la especificación de el/los TADs auxiliares que necesite para resolver
el problema (no es necesario implementarlos).*/

struct nodoABEnt
{
    int dato;
    nodoABEnt *izq, *der;
};
typedef nodoABEnt *ABEnt;

// TAD Pila
typedef int * Pila;
struct Pila;

// POS: Crea una pila vacía.
Pila crearPila();

// POS: Destruye una pila y elimina la memoria asociada a ella.
void destruirPila(Pila p);

// POS: Devuelve true si elem pertenece a p, y false en caso contrario.
bool pertenece(Pila p, int elem);

// POS: Devuelve true si p es vacía, y false en caso contrario.
bool esVacia(Pila p);

// POS: "Apila" un elemento a la pila, es decir, lo agrega al principio de esta.
void apilar(Pila p, int elem);

// PRE: pertenece(p, elem);
// POS: "Desapila" el elemento de arriba del todo de la pila, es decir, lo elimina de esta. Además, lo devuelve.
int desapilar(Pila p);

// POS: Devuelve una copia de la pila p. Esta copia no comparte memoria con la pila original.
Pila copia(Pila p);

int sumasNivelesAux(Pila &p, ABEnt a, int suma) {
    if (a != NULL) {
        int sumaAux = suma + a->dato;
        apilar(p, sumaAux);

        return suma;
    } else {
        return 0;
    }
};

void sumasNiveles(ABEnt a) {
    if (a != NULL) {
        Pila p = crearPila();

        while (!esVacia(p)) {
            int elem = desapilar(p);
            printf(elem, " ");
        }


    } else {
        printf(0);
    }
};