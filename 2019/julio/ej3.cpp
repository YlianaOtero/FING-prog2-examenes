#include <stdio.h>
#include <string.h>
typedef char * String;
/*Se pretende modelar de forma simplificada la asignación de funcionarios a circuitos electorales el día de las
elecciones. Cada circuito está identificado por un número en el rango [0, C] y tiene asociado una dirección de
tipo String y 3 funcionarios que están asignados al circuito el día de las elecciones. Cada funcionario tiene
asociado un nombre, un número de cédula de identidad, el circuito en el que vota y el circuito al que está
asignado el día de las elecciones. Se sabe que el número de funcionarios en el sistema será N = 3(C + 1)
cómo máximo.
Algunas de las operaciones del sistema necesarias son: crear la estructura de datos con la información
de circuitos, asignar funcionarios a circuitos, retornar el número de funcionarios asignados a un circuito,
imprimir los funcionarios de un circuito, retornar el número de circuito al que está asignado un funcionario,
imprimir la información de los funcionarios asignados.

Considere la siguiente definición del tipo Asignaciones*/

// Nodos de arbol binario de búsqueda. Cada nodo representa un funcionario. El arbol esta ordenado por nombre del funcionario.
struct nodoABBF
{
    String nom;
    int ci;
    int circFAsig;
    int circFVota;
    nodoABBF *izq;
    nodoABBF *der;
};

typedef nodoABBF *ABBFuncionarios;

// Nodos para representar un circuito, identificados por número del circuito.
// Tiene un puntero a cada funcionario asignado a ese circuito.
struct nodoCirc
{
    String dir;
    nodoABBF *f1, *f2, *f3;
};

// Nodos para lista de punteros a funcionarios (nodos del arbol).
// Se utilizara para implementar hash abierto.
struct nodoLista
{
    nodoABBF *f;
    nodoLista *sig;
};

typedef nodoLista *ListaFuncCI;

// Multiestructura de Asignaciones. Contiene:
// −Arbol Binariode Búsqueda de funcionarios
// −Arreglo de circuitos
// −Hash Abierto de funcionarios (por CI).
struct rep_Asignaciones
{
    ABBFuncionarios funcionarios;
    nodoCirc *circuitos;
    ListaFuncCI *hashFuncCI;
};

typedef struct rep_Asignaciones *Asignaciones;

/*(a) 1. Implemente la siguiente operación del TAD Asignaciones:*/

/*Crea un sistema para asignar hasta N funcionarios a C circuitos electorales con identificador en el rango [0, C].
El array 'circuitos' es de largo C+1 y contiene la direccion de cada circuito. La posicion en el array identifica a cada circuito.
Devuelve un TAD Asignaciones con circuitos sin funcionarios asignados. */
Asignaciones crearAsig(int C, String *circuitos)
{
    Asignaciones sistema = new rep_Asignaciones;

    if (C > 0)
    {
        nodoCirc *circuitosSistema = new nodoCirc[C + 1];

        for (int i = 0; i <= C; i++)
        {
            circuitosSistema[i].dir = circuitos[i];
            circuitosSistema[i].f1 = NULL;
            circuitosSistema[i].f2 = NULL;
            circuitosSistema[i].f3 = NULL;
        }

        int N = 3*(C + 1);

        ListaFuncCI * hashFunc = new ListaFuncCI[N+1];
        
        for (int i = 1; i <= N; i++) {
            hashFunc[i] = NULL;
        }

        sistema->circuitos = circuitosSistema;
        sistema->funcionarios = NULL;
        sistema->hashFuncCI = hashFunc;
    }

    return sistema;
};

/*2. Explique cuál es el orden del tiempo de ejecución para el peor caso.*/
/*Deben recorrerse dos arreglos completamente: uno de tamaño C+1, y otro de tamaño 3(C+1).
Estas operaciones son de O(C) cada una. En cuanto al resto de las operaciones, son todas
asignaciones o comparaciones, por lo que son de orden constante.
Por lo tanto, la funcion crearAsig es O(C).*/

/*(b) Implemente la siguiente operación del TAD Asignaciones, de forma que el orden del tiempo de ejecución
sea O(1) en promedio. Asuma implementada una función ℎ ∶ int → [0‥N − 1].*/
//Devuelve verdadero si el circuito al que esta asignado el funcionario con cédula ci es el mismo en el que vota.
//PRE: existe el funcionario con ci asignado a algún circuito en A.
bool coincide(int ci, Asignaciones A) {
    int pos = h(ci);

    ListaFuncCI bucketFuncionario = A->hashFuncCI[pos];

    while (bucketFuncionario->f->ci != ci) {
        bucketFuncionario = bucketFuncionario->sig;
    }

    int circAsignado = bucketFuncionario->f->circFAsig;
    int circVota = bucketFuncionario->f->circFVota;

    bool resultado = circAsignado == circVota;
    
    return resultado;
};

/*(c) 1. Implemente un procedimiento que imprima, en orden alfabético, los nombres de los funcionarios
que NO están asignados al mismo circuito en el que votan.*/
void noCoincidenAux(ABBFuncionarios arbol) {
    if (arbol != NULL) {
        noCoincidenAux(arbol->izq);

        if (arbol->circFAsig != arbol->circFVota) {
            printf("%s", arbol->nom);
        }

        noCoincidenAux(arbol->der);
    }
}

void noCoinciden(Asignaciones A) {
    ABBFuncionarios funcionarios = A->funcionarios;
    noCoincidenAux(funcionarios);
}

/*2. Explique cuál es el orden del tiempo de ejecución para el peor caso.*/
/*En el peor caso, noCoincidenAux debe recorrer todo el arbol imprimiendo los nombres de todos los funcionarios.
Esto es O(N), pues tenemos N funcionarios (por ende N nodos), y recorrer un arbol es O(N).*/