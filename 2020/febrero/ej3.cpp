#include <stdio.h>
/*(a) Especifique, con pre y postcondiciones, el TAD Tabla (funciones parciales, mappings) no acotada,
de elementos Dominio y Rango de tipos genéricos, con las operaciones básicas: creoTabla, insertar
(que actualiza también), esTablaVacia, estaDefinida, recuperar y borrar. Además, extienda el TAD con
el predicado esInyectiva que retorna true si y sólo si, la tabla es inyectiva: no existen dos elementos
distintos en el dominio de la tabla con igual imagen (rango).*/
struct rep_Tabla;
typedef rep_Tabla * Tabla;

typedef int Dominio; //por ej.
typedef int Rango; //por ej.

//POS: Crea una tabla vacia.
Tabla creoTabla();

//POS: Inserta la correspondencia T(d) = r. Si ya existia, la actualiza.
//void insertar(Tabla &t, Dominio d, Rango r);

//POS: Devuelve true si t es vacia, y false en caso contrario.
bool esTablaVacia(Tabla t);

//POS: Devuelve true si la correspondencia T(d) esta definida en t, y false en caso contrario.
bool estaDefinida(Tabla t, Dominio d);

//PRE: estaDefinida(t, d)
//POS: Devuelve el elemento correspondiente a d en la tabla t.
Rango recuperar(Tabla t, Dominio d);

//POS: Devuelve true si en t no existen dos elementos distintos en el dominio con la misma imagen, 
//y false en caso contrario.
//bool esInyectiva(Tabla t);

/*(b) Implemente el TAD Tabla anterior usando árboles binarios de búsqueda como estructura de datos;
asuma que existe un orden total entre los elementos del dominio. Asuma que los operadores =, < y
>, están definidos para los elementos del tipo Dominio y que el operador = está definido sobre los
elementos del tipo Rango. Desarrolle el código de insertar y esInyectiva. Omita el código del resto de
las operaciones del TAD, que se asumen implementadas.*/

struct nodo_ABB {
    Dominio d;
    Rango r;
    nodo_ABB * izq;
    nodo_ABB * der;
};

typedef nodo_ABB * ABB;

struct rep_Tabla {
    ABB abb;
};

void insABB(ABB &a, Dominio d, Rango r) {

    if (a != NULL) {
        if (a->d == d) {
            a->r = r;
        } else if (a->d > d) {
            insABB(a->izq, d, r);
        } else {
            insABB(a->der, d, r);
        }
    } else {
        nodo_ABB * nuevo = new nodo_ABB;
        nuevo->d = d;
        nuevo->r = r;
        nuevo->der = NULL;
        nuevo->izq = NULL;
    };

}

//POS: Inserta la correspondencia T(d) = r. Si ya existia, la actualiza.
void insertar(Tabla &t, Dominio d, Rango r) {
    insABB(t->abb, d, r);
};

struct nodo_Lista {
    Rango elem;
    nodo_Lista * sig;
};

typedef nodo_Lista * Lista;

void enlistarNodos(ABB a, Lista &l) {
    if (a != NULL) {
        nodo_Lista * nuevo = new nodo_Lista;
        nuevo->elem = a->r;
        nuevo->sig = l;
        l = nuevo;
        enlistarNodos(a->der, l);
        enlistarNodos(a->izq, l);
    };
}

bool hayRepetidos(Lista l) {
    bool hayRepetidos = false;

    while (l != NULL && !hayRepetidos) {
        hayRepetidos = pertenece(l->sig, l->elem);
        l = l->sig;
    }

    return hayRepetidos;
}

bool pertenece(Lista l, Rango r) {
    bool encontrado = false;

    if (l != NULL) {
        encontrado = l->elem == r || pertenece(l->sig, r);
    };

    return encontrado;
}
 
//POS: Devuelve true si en t no existen dos elementos distintos en el dominio con la misma imagen, 
//y false en caso contrario.
bool esInyectiva(Tabla t) {
    bool es = true;

    if (t->abb != NULL) {
       Lista l = new nodo_Lista;
       enlistarNodos(t->abb, l);
       es = !hayRepetidos(l);
    }

    return es;
};

/*(c) Indique para ambas operaciones implementadas en la parte anterior, cuál es el orden del tiempo de
ejecución en el peor caso. Además, para la función insertar indique cuál es el orden del tiempo de
ejecución en el caso promedio. Justifique brevemente*/
/*INSERTAR: 
    Caso promedio: log(n) pues implica buscar un nodo en un ABB, o, si no existia, encontrar la posicion
    correcta para agregarlo. Las operaciones de comparacion o asignacion no aumentan el orden.
    Peor caso: n, pues en el peor caso, el ABB se "deforma" quedando con forma de lista (por ej, todos los
    subarboles existen a la izquierda del nodo en el que se esta parado), y el nuevo elemento debe agregarse
    al final (es decir, cuesta lo mismo que recorrer una lista de n elementos).*/
/*ESINYECTIVA:
    enlistarNodos: n porque recorre todos los n nodos de un arbol,
    pertenece: n porque recorre la lista entera una vez (y luego va recorriendo por sublistas),
    hayRepetidos: n*n porque en el peor caso recorre la lista entera, y en cada nodo llama a pertenece.
    Peor caso: n*n, pues implica recorrer los n nodos de un arbol para insertarlos en una lista, y luego
    recorrer la lista llamando en cada nodo a una funcion que tambien recorre la lista.*/