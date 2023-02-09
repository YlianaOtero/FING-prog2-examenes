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

// TAD Cola
typedef ABEnt *Cola;
struct Cola;

// POS: Crea una cola vacía.
Cola crearCola();

// POS: Destruye una cola y elimina la memoria asociada a ella.
void destruirCola(Cola c);

// POS: Devuelve true si elem pertenece a c, y false en caso contrario.
bool pertenece(Cola c, ABEnt elem);

// POS: Devuelve true si c es vacía, y false en caso contrario.
bool esVacia(Cola c);

// POS: "Encola" un elemento a la cola, es decir, lo agrega al final de esta.
void encolar(Cola c, ABEnt elem);

// PRE: pertenece(c, elem);
// POS: "Desencola" el elemento del incio de la cola, es decir, lo elimina de esta. Además, lo devuelve.
ABEnt desencolar(Cola c);

// PRE: !esVacia(c);
// POS: Devuelve el elemento del incio de la cola.
ABEnt frente(Cola c);

// POS: Devuelve una copia de la cola c. Esta copia no comparte memoria con la cola original.
Cola copia(Cola c);

void sumasNiveles(ABEnt a)
{
    if (a != NULL)
    {
        Cola c = crearCola();
        encolar(c, a);
        encolar(c, NULL);
        int suma = 0;

        while (frente(c) != NULL)
        {

            if (frente(c) != NULL)
            {
                ABEnt actual = desencolar(c);
                suma += actual->dato;

                if (actual->der != NULL)
                {
                    encolar(c, actual->der);
                }

                if (actual->izq != NULL)
                {
                    encolar(c, actual->izq);
                }
            }
            else
            {
                printf(%d, suma);
                suma = 0;

                if (!esVacia(c))
                {
                    encolar(c, NULL);
                }
            }
        }
    }
};