#include <stdio.h>
/*Considere la siguiente especificación del TAD Tabla acotada de unsigned int (dominio) en char (codominio):*/

struct RepTabla;
typedef RepTabla *Tabla;
typedef unsigned int nat;

// POS: Devuelve la Tabla vacía, sin correspondencias, donde max es la cantidad máxima de elementos que se puede almacenar en la
// Tabla crear(nat max);

// POS: En el caso de que d no tiene imagen en t, agrega la correspondencia (d,c).
// En el caso contrario solo actualiza la imagen de d con c.
// La operación no tiene efecto si t está llena y d no tiene imagen en t.
// void insertar (nat d, char c, Tabla & t);

// POS: Devuelve true si y sólo si d tiene imagen en t.
bool definida(nat d, Tabla t);

// POS: Devuelve la cantidad de correspondencias en t. En particular, 0 si t es la tabla vacía.
// int cantidad (Tabla t);

// PRE: definida(d,t). POS: Retorna la imagen de d en t.
char recuperar(nat d, Tabla t);

// POS: Elimina de t la correspondencia que involucra a d, si d está definida en t. En otro caso la operación no tiene efecto.
void eliminar(nat d, Tabla &t);

/*a) Proponga y justifique una representación para el TAD Tabla de tal manera que cantidad tenga O(1) en el peor
caso e insertar, definida, recuperar y eliminar tengan O(1) en el caso promedio asumiendo que la distribución
de los elementos del dominio es uniforme.*/

/*Podemos representar el TAD Tabla con una tabla de Hashing.*/

/*Cantidad O(1) peor caso: almaceno la cantidad de correspondencias en RepTabla, por lo que para saber cuantas correspondencias
hay en una tabla t, basta con hacer t->cantCorresp.

Insertar O(1) caso promedio: para insertar basta con agregar un elemento en una posicion del arreglo, al cual se accede haciendo
t->hash[pos], siendo pos la posicion que obtenemos mediante la funcion de hashing escogida. En este caso, elegimos utilizar h(x) = x % tope,
siendo tope el tamano de la tabla. Esto permite distribuir los elementos de manera mas uniforme.

Definida, Recuperar y Eliminar O(1) caso promedio: para ver si una correspondencia esta definida, recuperarla o eliminarla, el mayor
trabajo a realizar esta en la busqueda de la correspondencia. Para ello, en general basta con hallar la posicion en la que esta,
mediante la funcion de hashing (esto es O(1)), y acceder a esa posicion en el arreglo con t->has[pos]. Operaciones como eliminar
este elemento, devolverlo, etc. son todas de orden 1. No podemos decir que es O(1) en el peor caso porque en este, tendriamos multiples
elementos en t->has[pos].*/

/*b) Implemente la representación del TAD (RepTabla) y el código de las operaciones crear, cantidad e insertar.
Omita el código del resto de las operaciones del TAD, que puede asumir implementadas. Si utiliza operaciones
auxiliares debe implementarlas.*/
struct nodo;
struct nodo
{
    nat d;
    char c;
    nodo *sig;
};

typedef nodo *lista;

struct RepTabla
{
    lista *hash;
    nat tope;
    int cantCorresp;
};

Tabla crear(nat max)
{
    Tabla t = new RepTabla;
    t->cantCorresp = 0;
    t->tope = max;
    t->hash = new lista[max];
    for ( int i = 0; i < max; i++) {
        t->hash[i] = NULL;
    }
        
    return t;
};

int cantidad(Tabla t)
{
    return t->cantCorresp;
};

void insertar(nat d, char c, Tabla &t)
{
    int pos = d % t->tope;

    bool estaLlena = cantidad(t) == t->tope;
    bool tieneImagen = definida(d, t);

    if (!(estaLlena && !tieneImagen))
    {
        lista aux = t->hash[pos];
        if (aux != NULL && tieneImagen)
        {
            // la buscamos y la modificamos
            if (aux->d != d)
            {
                while (aux->sig != NULL && aux->d != d)
                {
                    aux = aux->sig;
                }
            }
            aux->c = c;
        }
        else
        {
            lista nuevoNodo = new nodo;
            nuevoNodo->c = c;
            nuevoNodo->d = d;
            nuevoNodo->sig = aux;
            aux = nuevoNodo;
            t->cantCorresp++;
        }
    }
};