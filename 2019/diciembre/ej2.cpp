#include <stdio.h>
/*Considere la siguiene función:*/
void funcion(int n, int A[], int B[]) {
    for (int i = 0; i < n; i++) {
        B[i] = A[0];

        for (int j = 1; j <= i; j++) {
            if (A[j] < B[i]) {
                B[i] = A[j];
            }
        }
    }
}

/*(a) ¿Qué obtiene esta función?*/
/*Carga en B[i] el minimo elemento en el intervalo [A[0]...A[i]]*/

/*(b) Calcule la cantidad de asignaciones al arreglo B en el peor caso. ¿Cuál es el orden O del tiempo de
ejecución?*/

/*El peor caso se da cuando A esta ordenado de forma estrictamente decreciente, por lo que siempre se cumple
que A[j] < B[i]. En ese caso, es O(n*n)*/

/*(c) Modifique la función para que el orden O del tiempo de ejecución sea menor. ¿Cuál es el nuevo orden?*/
void funcion2(int n, int A[], int B[]) {
    if (n > 0) {
        B[0] = A[0];
        for (int i = 1; i < n; i++) {
            if (B[i-1] > A[i]) {
                B[i] = B[i-1];  
            } else {
                B[i] = A[i];
            }
        }
    }
}

/*Esta version es O(n).*/