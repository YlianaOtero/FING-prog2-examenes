#include <stdio.h>
#include <string.h>

/*Un sistema de administración de información maneja datos de dos categorías. La información en cada caso
consiste de un elemento de un tipo string (char *), un identificador entero en el rango [0..K] (siendo K una
constante) y el tipo de categoría (0 ó 1). Cuando llega información al sistema de administración, se almacena
esperando su turno. No son admisibles incorporaciones con identificadores repetidos (en espera de ser
atendidas). El procesamiento de la información en el sistema de administración respeta la siguiente política:
primero se procesa la información de categoría 1 y, si no hay información de categoría 1, recién luego se atiende
información de categoría 0. Dentro de cada categoría (0 ó 1) se sigue la política FIFO.*/

/*Se pide:
a) Especifique un TAD ADM que permita resolver adecuadamente el sistema de administración de información
previamente descrito. Considere las siguientes operaciones:
 CrearADM, que retorna un sistema de administración de información vacío.
 Insertar(e,cat,id,adm), que agrega un elemento e (un string) con categoría cat, si es que no existe el id
en un sistema adm dado, de lo contrario no tiene efecto. Considere definido el tipo enumerado enum
Categoria {0,1}.
 EsVacio, que retorna true si y solo si un sistema dado no tiene elementos.
 Recuperar, que retorna el elemento, de tipo string, que corresponda (según la política definida para el
sistema de administración de información) de un sistema no vacío.
 Eliminar, que borra el elemento que corresponda (según la política definida para el sistema de
administración de información) si el sistema no es vacío, de lo contrario no tiene efecto.
 Destruir, que destruye un sistema de administración de información, liberando toda la memoria asociada
a éste. 
 Clon, que retorne una copia de un sistema de administración de información, que no comparte memoria.
*/
int K = 100; //por ej.

struct rep_ADM;
typedef rep_ADM * ADM;

typedef int Categoria;
typedef char * String;

//POS: Devuelve un ADM vacio.
ADM crearADM();

//POS: Agrega el elemento e con categoria cat al sistema adm, si es que no existe el id en ese sistema.
//De lo contrario, la operacion no tiene efecto.
void insertar(String e, Categoria cat, int id, ADM &adm);

//POS: Retorna true si y solo si adm no tiene elementos.
bool esVacio(ADM adm);

//PRE: !esVacio(adm)
//POS: Retorna el elemento en adm, de tipo string, que corresponda según la política definida para el
//sistema de administración de información.
String recuperar(ADM adm);

//POS: Borra el elemento que corresponda (según la política definida para el sistema de
//administración de información) si el sistema no es vacío, de lo contrario no tiene efecto.
void eliminar(ADM &adm);

//POS: estruye un sistema de administración de información, liberando toda la memoria asociada a éste. 
void destruir(ADM &adm);

//Retorna una copia de un sistema de administración de información, que no comparte memoria.
ADM clon(ADM adm);

/*b) Desarrolle una implementación del TAD ADM, sin usar TADs auxiliares, en la cual las operaciones Insertar,
Eliminar y Recuperar sean O(1) peor caso. Para esto, defina primero y explique (puede ser gráficamente) la
representación elegida para el TAD y luego implemente las operaciones para la representación propuesta.
Asuma que las operaciones Destruir y Clon están implementadas. Puede utilizar operaciones sobre strings
(char *), tales como strcpy y strcmp.*/
struct rep_ADM {
    bool * id;
    queue_head * cat1;
    queue_head * cat0;
};

struct queue_node {
    queue_node * sig;
    String dato;
    int id;
};

struct queue_head {
    queue_node * primero;
    queue_node * ultimo;
};

ADM crearADM() {
    ADM nuevo = new rep_ADM;
    nuevo->cat1 = new queue_head;
    nuevo->cat0 = new queue_head;
    nuevo->cat0->primero = NULL;
    nuevo->cat0->ultimo = NULL;
    nuevo->cat1->primero = NULL;
    nuevo->cat1->ultimo = NULL;
    
    bool * arr = new bool[K+1];
    for (int i = 0; i <= K; i++) {
        arr[i] = false;
    }

    nuevo->id = arr;

    return nuevo;
};

void insertar(String e, Categoria cat, int id, ADM &adm) {
    if (!adm->id[id]) {
        queue_node * nuevo = new queue_node;
        nuevo->dato = e;
        nuevo->id = id;
        nuevo->sig = NULL;

        if (cat == 0) {
            if (adm->cat0->primero != NULL) {
                adm->cat0->ultimo->sig = nuevo;
            } else {
                adm->cat0->primero = nuevo;
            }
            
            adm->cat0->ultimo = nuevo;

        } else {
            if (adm->cat1->primero != NULL) {
                adm->cat1->ultimo->sig = nuevo;
            } else {
                adm->cat1->primero = nuevo;
            }
            
            adm->cat1->ultimo = nuevo;
        };

        adm->id[id] = true;
    };
};

bool esVacio(ADM adm) {
    return ((adm->cat0->primero == NULL) && (adm->cat1->primero == NULL));
};

String recuperar(ADM adm) {
    String valor;

    if (adm->cat1->primero != NULL) {
        valor = adm->cat1->primero->dato;
    } else {
        valor = adm->cat0->primero->dato;
    };

    return valor;
};

void eliminar(ADM &adm) {
    if (!esVacio(adm)) {
        queue_node * aBorrar = NULL;

        if (adm->cat1->primero != NULL) {
            aBorrar = adm->cat1->primero;
            adm->cat1->primero = aBorrar->sig;
        } else {
            aBorrar = adm->cat0->primero;
            adm->cat0->primero = aBorrar->sig;
        }
        
        int id = aBorrar->id;
        adm->id[id] = false;

        delete aBorrar->dato;
        delete aBorrar;
    }
};

/*c) Defina una función indistinguibles que, dados adm1 y adm2 del tipo abstracto ADM, retorne true si y sólo si
los elementos, de tipo string, que se obtienen de adm1 y adm2 son iguales, y en el mismo orden. La función
no debe modificar adm1 ni adm2. Tampoco es posible acceder a la representación del TAD ADM. Puede
utilizar la operación strcmp para comparar strings. */

bool indistinguibles(ADM adm1, ADM adm2) {
    bool resultado = true;

    ADM adm1Aux = clon(adm1);
    ADM adm2Aux = clon(adm2);

    while (resultado && !esVacio(adm1Aux) && !esVacio(adm2Aux)) {
        resultado = strcmp(recuperar(adm1Aux), recuperar(adm2Aux)) == 0;
        eliminar(adm1Aux);
        eliminar(adm2Aux);
    };

    if (!esVacio(adm1Aux) || !esVacio(adm2Aux)) {
        resultado = false;
    }

    destruir(adm1Aux);
    destruir(adm2Aux);

    return resultado;
}