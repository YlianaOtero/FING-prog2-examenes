#include <stdio.h>
#include <string.h>
/*Una empresa quiere tener un sistema que permita gestionar el stock de sus productos. Cada producto se 
identifica con una cadena de caracteres y se puede tener una cantidad arbitraria de unidades para cada uno. El 
sistema que pretende la empresa debería contemplar al menos las siguientes funcionalidades básicas:
i. Agregar n unidades de un producto dado al stock. Si el producto no había sido ingresado al sistema 
se ingresa con n unidades.
ii. Dar de baja a lo sumo n unidades de un producto dado al stock. No tiene efecto si el producto no está 
ingresado.
iii. Saber dado un producto la cantidad de unidades disponibles en el stock. En caso de no estar ingresado 
devuelve 0.
Se pide:*/
/*a) Indique un TAD de los vistos en el curso que resulte particularmente adecuado para modelar el stock de 
productos. Especifique el TAD stock con operaciones constructoras, selectoras/destructoras y predicados 
para operar con el stock de productos de la empresa.*/
typedef char * String;

struct rep_Stock;
typedef rep_Stock * Stock;

//POS: Crea un stock vacio de n productos.
Stock crearStock(int n);

//POS: Agrega cant unidades del producto. 
//Si el producto no existia en el stock, agrega la correspondencia f(id) = cant.
//Si el producto ya existia en el stock, suma cant a su cantidad actual de unidades.
void agregarUnidades(String id, int cant, Stock &s);

//POS: Quita cant unidades del producto. 
//Si el producto no existe en el stock, no tiene efecto.
//Si existe, resta cant a su cantidad actual de unidades. 
//Si el resultado de esto es 0, elimina al producto del stock.
void quitarUnidades(String id, int cant, Stock &s);

//POS: Devuelve la cantidad de unidades de un producto en el stock.
//Si el producto no existe en el stock, devuelve 0.
int cantEnStock(String id, Stock s);

//POS: Elimina un stock y la memoria asociada a el y a sus elementos.
void eliminarStock(Stock &s);

/*b) Proponga una implementación que resulte O(1) caso promedio para las tres funcionalidades previamente 
mencionadas (i, ii y iii), asumiendo que se esperan aproximadamente N productos y que se tiene disponible 
la función H: String→[0,N-1]. Justifique, asumiendo las hipótesis que considere necesarias. Defina la 
representación del TAD e implemente únicamente los códigos de las operaciones i) y iii). Omita el código 
del resto de las operaciones del TAD. */
/*Mapping*/
struct nodo;
typedef nodo * Lista;

struct nodo {
    String id;
    int cant;
    nodo * sig;
};

struct rep_Stock {
    Lista * hash;
    int N;
};

int H(String id);

int cantEnStock(String id, Stock s) {
    int res = 0;
    int pos = H(id);

    if (s->hash[pos] != NULL) {
        Lista aux = s->hash[pos];

        while (aux != NULL && strcmp(aux->id, id) != 0) {
            aux = aux->sig;
        }

        if (strcmp(aux->id, id) != 0) {
            res = aux->cant;
        }
    }

    return res;
};

void agregarUnidades(String id, int cant, Stock &s) {
    int pos = H(id);
    Lista aux = s->hash[pos];

    if (cantEnStock(id, s) == 0) {
        nodo * nuevo = new nodo;
        nuevo->id = id;
        nuevo->cant = cant;

        s->hash[pos] = nuevo;

        if (s->hash[pos] == NULL) {
            nuevo->sig = NULL;
        } else {
            nuevo->sig = aux;
        }
    } else {
        while (strcmp(aux->id, id) != 0) {
            aux = aux->sig;
        }
        aux->cant += cant;
    }
};