#include <stdio.h>
/*Considere la siguiente especificación del TAD Tabla no acotada de unsigned int (dominio) en float (codominio):*/
struct RepTabla;
typedef RepTabla * Tabla;
typedef unsigned int nat;

// POS: Devuelve la Tabla vacía, sin correspondencias.
Tabla crear();

// POS: Agrega la correspondencia (d,c) en t, si d no tenía imagen en t. En caso contrario actualiza la imagen de d con c.
void insertar (nat d, float c, Tabla & t);

// POS: Devuelve true si y sólo si d tiene imagen en t. 
bool definida (nat d, Tabla t);

// POS: Devuelve la cantidad de correspondencias en t. En particular, 0 si t es la tabla vacía.
int cantidad (Tabla t);

// PRE: definida(d,t). POS: Retorna la imagen de d en t.
float recuperar (nat d, Tabla t);

// POS: Elimina de t la correspondencia que involucra a d, si d está definida en t. En otro caso la operación no tieneefecto.
void eliminar (nat d, Tabla & t);

/*Implemente el TAD Tabla de tal manera que cantidad tenga O(1) en el peor caso e insertar, recuperar y eliminar
tengan O(log2(n)) en el caso promedio, siendo n la cantidad de correspondencias de la tabla. Desarrolle la
representación del TAD (RepTabla) y el código de las operaciones crear, cantidad e insertar. Omita el código del
resto de las operaciones del TAD, que puede asumir implementadas. No use TADs auxiliares en la
implementación; utilice estructuras de datos.*/

struct Nodo {
    nat d;
    float c;
    Nodo * izq;
    Nodo * der;
};

typedef Nodo * ABB;

struct RepTabla {
    ABB abb;
    int cant;
};

typedef RepTabla * Tabla;

Tabla crear() {
    Tabla t = new RepTabla;
    t->abb = NULL;
    t->cant = 0;

    return t;
};

bool insAbb(ABB &abb, nat d, float c) {
    bool aumentaCant = true;

    if (abb != NULL) {
        if (abb->d == d) {
            abb->c = c;
            aumentaCant = false;
        } else if (abb->d > d) {
            insAbb(abb->izq, d, c);
        } else {
            insAbb(abb->der, d, c);
        }
    } else {
        ABB nuevo = new Nodo;
        nuevo->c = c;
        nuevo->d = d;
        nuevo->izq = NULL;
        nuevo->der = NULL;
    }

    return aumentaCant;
}

void insertar (nat d, float c, Tabla & t) {
    if (insAbb(t->abb, d, c)) {
        t->cant++;
    };
};

int cantidad (Tabla t) {
    return t->cant;
};