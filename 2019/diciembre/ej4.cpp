#include <stdio.h>
/*La empresa de entrega de mercaderías DeliveryYa necesita gestionar su callcenter, al cual se comunican
sus clientes para hacer los pedidos y que es atendido por una plantilla de operadores de la empresa.
Cada cliente es identificado por su teléfono (int) y no se sabe cuántos clientes pueden estar en espera en
cada momento. La empresa tiene operadores que atienden a los clientes y cada uno puede atender hasta
un cliente por vez. Los operadores son identificados por un número de operador (int) que no se repite. Cada
vez que un cliente quiere hacer un pedido es transferido con el operador que ha estado libre durante más
tiempo o es puesto en espera hasta que un operador quede libre.*/

/*(a) Especifique el TAD Cola que sirve tanto para mantener clientes en espera como operadores con 
disponibilidad para atender clientes.*/
struct rep_Cola;
typedef rep_Cola * Cola;

//POS: Crea una cola vacia.
Cola crearCola();

//POS: Agrega el elemento dato al final de la cola.
void encolar(Cola c, int dato);

//POS: Elimina el elemento al inicio de la cola. Si la cola estaba vacia, no tiene efecto.
void desencolar(Cola c);

//POS: Devuelve true si la c esta vacia, y false en caso contrario.
bool esVacia(Cola c);

//PRE: !esVacia(c)
//POS: Devuelve el elemento al inicio de la cola.
int frente(Cola c);

//POS: Destruye c y libera su memoria asociada.
void destruirCola(Cola c);

/*(b) Defina una representación para Cola que permita que el orden del tiempo de ejecución de las 
operaciones sean O(1) peor caso. Además el espacio ocupado en memoria debe ser proporcional a la cantidad
de elementos almacendos en la cola en todo momento. Dar especificación de tipos y explicación gráfica,
justificando brevemente por qué la representación elegida cumple con las restricciones de tiempo.*/
struct nodo_Cola {
    int dato;
    nodo_Cola * sig;
};

struct rep_Cola {
    nodo_Cola * primero;
    nodo_Cola * ultimo;
    nodo_Cola * cola;
    int cant;
};

/*Es O(1) peor caso porque al ser una lista pero mantener en la representacion un puntero al primer y ultimo
elemento, siempre se puede encolar un elemento facilmente (pues no es necesario recorrer toda la cola). 
En el caso de desencolar un elemento, esto tambien se hace en O(1) pero porque simplemente es acceder al 
primer elemento en la cola. Por otro lado, saber si una cola es vacia o no solo implica consultar por 
el parametro cant en la representacion de la cola. */

/*(c) Implemente todas las operaciones del TAD.*/
Cola crearCola() {
    Cola nueva = new rep_Cola;
    nueva->cola = NULL;
    nueva->ultimo = NULL;
    nueva->primero = NULL;
    nueva->cant = 0;

    return nueva;
};

bool esVacia(Cola c) {
    return (c->cant == 0);
};

int frente(Cola c) {
    return c->primero->dato;
};

void encolar(Cola c, int dato) {
    nodo_Cola * nuevo = new nodo_Cola;
    nuevo->dato = dato;
    nuevo->sig = NULL;
    c->ultimo->sig = nuevo;
    c->ultimo = nuevo;
    c->cant++;
};

void desencolar(Cola c) {
    nodo_Cola * aBorrar = c->cola;
    c->cola = c->cola->sig;
    c->primero = c->cola;
    c->cant--;

    delete aBorrar;
};

void destruirCola(Cola c) {
    while (c->cant > 0) {
        desencolar(c);
    }

    delete c;
};

/*(d) Implemente la siguiente operación:*/

/* Dada una cola de clientes en espera ECli y una cola de operadores libres EOper,
se intenta asignar un operador a un cliente.
Si hay operadores libres y clientes en espera: el operador que ha estado libre más
tiempo debe ser asignado al cliente que ha esperado más tiempo y se devuelve true,
en caso contrario se devuelve false.
Si se puede hacer una asignacion de un operador a un cliente se debe devolver
en cliAtendido el número de telefono del cliente atendido y en operAsignado el número 
de operador asignado. Se deben remover cliAtendido y operAsignado de sus colas correspondientes.*/

bool asignarUnOperador(Cola &ECli, Cola &EOper, int &cliAtendido, int &operAsignado) {
    bool seAsigno = false;

    if (!esVacia(ECli) && !esVacia(EOper)) {
        cliAtendido = frente(ECli);
        operAsignado = frente(EOper);
        desencolar(ECli);
        desencolar(EOper);
        seAsigno = true;
    }

    return seAsigno;
};
