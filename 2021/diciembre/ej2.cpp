#include <stdio.h>

/*Se debe determinar si una lista de enteros tiene elementos repetidos. No se puede acceder a la representación de la lista, sino que se dispone de una versión del TAD Lista que incluye las operaciones longitud y
pertenece además de las operaciones habituales. La siguiente es la especificación del TAD y de la función a implementar:*/

/* Devuelve una lista sin elementos.*/
Lista crear ( ) ;

/* Devuelve ' true' si y solo si 'l' no tiene elementos .*/
bool esVacia ( Lista l ) ;

/*Devuelve la lista resultado de insertar 'a' al inicio de 'l' .*/
Lista insertar ( i n t a , Lista l ) ;

/*Devuelve el primer elemento de 'l'.
Pre: !esVacia (l) .*/
int primero ( Lista l ) ;

/*Devuelve 'l' sin su primer elemento.
Pre : ! esVacia (l) .*/
Lista siguiente ( Lista l ) ;

/* Devuelve 'true' si y solo si 'a' es un elemento de 'l'.*/
bool pertenece ( i n t a , Lista l ) ;


/* Devuelve la cantidad de elementos de 'l'.*/
int longitud ( Lista l ) ;

/* Devuelve 'true ' si y solo s  en 'l' no hay elementos repetidos.*/
// bool sinRepetidos ( Lista l ) ;

/*Se puede asumir que el tiempo de ejecución de crear, esVacia, primero, insertar y siguiente es O(1),
y que el de pertenece y longitud es O(n), donde n es la longitud de la lista parámetro.

(a) Asuma que los enteros pertenecen al dominio {1,…,M} donde M es una constante conocida. Implemente la función sinRepetidos con un tiempo de ejecución O(M) en peor caso*/
CONST M = 10;

bool sinRepetidos (Lista l) {
    bool hayRepetidos = false;

    if (!esVacia(l)) {
        bool * estaEnLista = new bool[M+1];
        for (int i = 0; i < M+1; i++) {
            estaEnLista[i] = false;
        }
        
        Lista aux = l;

        while (!esVacia(aux) && !hayRepetidos) {
            int actual = primero(aux);

            if (estaEnLista[actual]) {
                hayRepetidos = true;
            }

            estaEnLista[actual] = true;

            aux = siguiente(aux);
        }

        delete[] estaEnLista;
    }

    return !hayRepetidos;
};