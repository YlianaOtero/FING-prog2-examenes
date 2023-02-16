#include <stdio.h>
/*Considere la siguiente declaración, en C++, del tipo Lista, que representa listas dinámicas de enteros*/
struct nodoLista
{
    int info;
    nodoLista *sig;
};
typedef nodoLista *Lista;

/*Dadas dos listas l1 y l2 de números enteros de igual largo ordenadas estrictamente, diremos que l1 es
parecida a l2 si las listas tienen al menos la mitad de sus elementos en común (iguales). Definir una función
iterativa parecidas que determine si l1 es parecida a l2. Asumimos como precondición que ambas listas
tienen igual largo, están ordenadas de menor a mayor y no poseen elementos repetidos. La función parecidas debe 
tener O(n) de tiempo de ejecución en el peor caso (siendo n largo de las listas). Cada lista debe
recorrerse a lo sumo una vez.*/
bool parecidas ( Lista l1 , Lista l2 ) {
    int largo = 0;
    int cant = 0;

    while (l1 != NULL && l2 != NULL) {
        if (l1->info == l2->info) {
            cant++;
            largo++;
            l1 = l1->sig;
            l2 = l2->sig;
        } else if (l1->info > l2->info) {
            l2 = l2->sig;
        } else {
            l1 = l1->sig;
            largo++;
        }
    }

    while (l1 != NULL) {
        largo++;
        l1 = l1->sig;
    }

    bool resultado = cant >= largo/2;

    return resultado;
};