/*Considere el TAD Cola no acotada de enteros (ColaInt), que contempla la política FIFO, con operaciones 
exclusivamente para: crear una cola vacía; insertar; eliminar y retornar el elemento correspondiente; y chequear 
si una cola está vacía.
a)Especifique el Tad ColaInt, incluyendo sus pre y postcondiciones.*/
struct rep_Cola;
typedef rep_Cola * ColaInt;

//POS: Crea una cola vacia.
ColaInt crearCola();

//POS: Devuelve true si la cola esta vacia, y false en caso contrario.
bool esVacia(ColaInt c);

//POS: Inserta un elemento al final de la cola.
void encolar(int elem, ColaInt cola);

//PRE: !esVacia(cola);
//POS: Elimina el primer elemento de la cola y lo devuelve.
int desencolar(ColaInt cola);
