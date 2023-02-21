#include <stdio.h>
/*Se desea implementar un algoritmo para crear un árbol binario de enteros a partir de un conjunto de árboles
pasado como parámetro.
El algoritmo funciona de la siguiente manera: dado un conjunto de árboles, en cada paso se toman los
dos árboles con menor valor en su raíz y se crea un nuevo árbol que contiene a estos dos como subárbol
izquierdo y derecho (el que posee la raíz de menor valor se coloca del lado derecho). Además, la raíz del
nuevo árbol contiene la suma de los valores de los dos subárboles. Luego, el árbol resultante es insertado
en el conjunto, de forma de ser considerado por el algoritmo en los próximos pasos. Si el conjunto tiene un
sólo árbol, el mismo es retornado como resultado. */

/*Considere la siguiente definición de árbol binario.*/

struct nodoAB
{
    int valor;
    nodoAB * izq, *der;
};

typedef nodoAB * AB;

/*Se pide:
(a) Especifique el TAD Cola de Prioridad de elementos de tipo AB.*/

struct rep_Cola;
typedef rep_Cola * CP;

//POS: Crea una cola de prioridad vacia.
CP crearCP();

//POS: Agrega un arbol con prioridad p a la cola.
CP encolar(CP &cola, AB arbol, int p);

//POS: Elimina el elemento con mayor prioridad en la cola. Si la cola es vacia, no tiene efecto.
void desencolar(CP &cola);

//POS: Devuelve true si la cola es vacia, y false en caso contrario
bool esVacia(CP cola);

//PRE: !esVacia(cola);
//POS: Devuelve el arbol con mayor prioridad de la cola.
AB prioritario(CP cola);

//POS: Elimina la cola de prioridad y libera la memoria asociada.
void destruirCola(CP &cola);

/*(b) Asumiendo ya implementadas las operaciones del TAD Cola de Prioridad de elementos de tipo AB.
Implemente la operación crearArbol que recibe en la cola de prioridad CP el conjunto de árboles inicial.*/

/* Función que crea un arbol binario a partir de un conjunto de arboles dados en una cola de prioridad .*/
AB crearArbol(CP cola) {
    AB resultado = NULL;

    if (!esVacia(cola)) {
        AB menorValor = prioritario(cola);
        desencolar(cola);

        while (!esVacia(cola)) {
            AB nuevo = new nodoAB;
            AB segMenorValor = prioritario(cola);

            nuevo->izq = segMenorValor;
            nuevo->der = menorValor;
            nuevo->valor = menorValor->valor + segMenorValor->valor;

            encolar(cola, nuevo, nuevo->valor);    
            menorValor = prioritario(cola);
            resultado = menorValor;

            desencolar(cola);
        }
        resultado = menorValor;
    }

    return resultado;  
};

/*(c) Implemente la operación imprimirSuma, que dado un árbol binario, para cada camino de la raíz a una
hoja imprime la suma de los valores de sus nodos.*/

// Dado un arbol binario, para cada camino de la raíz a una hoja imprime la suma de los valores de sus nodos.
void sumaCamino(AB a, int suma) {
    if (a != NULL) {
        suma += a->valor;

        if (a->der == NULL && a->izq == NULL) {
            printf("%d", suma);
        } else if (a->der != NULL) {
            sumaCamino(a->der, suma);
        } else {
            sumaCamino(a->izq, suma);
        } 
    } 
}

void imprimirSumaAB(AB a) {
    if (a != NULL) {
        int valor = 0;
        sumaCamino(a, valor);
    }
};

