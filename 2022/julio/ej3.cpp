#include <stdio.h>

/*Considere la siguiente especificación, con pre y postcondiciones, de un TAD cola de prioridad no acotado de
elementos de un tipo T con prioridades que toman valores enteros: */

// PRE: -
// POS: retorna una nueva cola de prioridad vacía
// ColaPrioridad crearColaPrioridad ();

// PRE: -
// POS: inserta un elemento t de tipo T con prioridad p a la cola de prioridad. Los
// elementos con igual prioridad se consideran en orden FIFO.
// void encolar(ColaPrioridad &cp, T t, int p);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la cola de prioridad
// unsigned int cantidad (ColaPrioridad cp);

// PRE: cantidad(cp)!=0
// POS: retorna y quita el elemento con mayor prioridad (mayor valor entero) de la
// cola de prioridad. Ante elementos de igual prioridad máxima, retorna y elimina el más antiguo (orden FIFO)
// T obtener(ColaPrioridad &cp);

// PRE: -
// POS: retorna una copia de la cola de prioridad parámetro sin compartir memoria
// ColaPrioridad copia (ColaPrioridad cp);

// PRE: -
// POS: destruye la cola de prioridad, liberando su memoria
// void destruir (ColaPrioridad &cp);

/*Se pide:
a) Defina una representación del TAD anterior en la que las operaciones crearColaPrioridad, obtener y
cantidad tengan O(1) de tiempo de ejecución en el peor caso. Escriba el código de las operaciones
crearColaPrioridad y encolar. Asuma que las restantes están implementadas. Considere que los
elementos de tipo T pueden manipularse usando los operadores habituales de asignación y comparación (como si
fuera un tipo numérico básico). */

typedef char T; // por ejemplo
typedef unsigned int nat;

// Definamos una cola de prioridad representada como una lista ordenada desc. por prioridad y numero (antiguedad)
typedef struct nodo *ColaPrioridad;
struct nodo
{
    int prioridad;
    int num;
    unsigned int cant;
    T elem;
    nodo *sig;
};

ColaPrioridad crearColaPrioridad()
{
    ColaPrioridad cp = new nodo;
    cp->sig = NULL;
    cp->cant = 0;
    cp->num = 0;

    return cp;
}

void insertarOrdenado(ColaPrioridad &nuevo, ColaPrioridad &original)
{
    int prioridadNuevo = nuevo->prioridad;
    int numNuevo = nuevo->num;

    ColaPrioridad originalAux = original;

    if (originalAux->prioridad <= prioridadNuevo)
    {
        nuevo->sig = original;
        original = nuevo;
    }
    else
    {
        while (originalAux->sig != NULL && originalAux->sig->prioridad > prioridadNuevo)
        {
            originalAux = originalAux->sig;
        };

        ColaPrioridad sigAux = originalAux->sig;
        nuevo->sig = sigAux;
        originalAux->sig = nuevo;
    };
}

unsigned int cantidad(ColaPrioridad cp)
{
    return cp->cant;
};

void encolar(ColaPrioridad &cp, T t, int p)
{
    ColaPrioridad nuevoNodo = new nodo;
    nuevoNodo->prioridad = p;
    nuevoNodo->elem = t;
    cp->cant++;
    nuevoNodo->cant = cp->cant;
    nuevoNodo->num = nuevoNodo->cant;

    if (nuevoNodo->num == 1)
    {
        cp = nuevoNodo;
        cp->sig = NULL;
    }
    else
    {
        insertarOrdenado(nuevoNodo, cp);
    }
}

/*b) Implemente la función bool indistinguibles (ColaPrioridad cp1, ColaPrioridad cp2) que
dadas dos colas de prioridad retorne true si y solo si son indistinguibles. Esto es, si los elementos de tipo T que se
obtienen de ambas son los mismos y en el mismo orden. La función no deberá acceder a la representación del TAD
(su implementación), ni modificar las colas de prioridad parámetro, ni dejar memoria colgada.*/
ColaPrioridad copia (ColaPrioridad cp) {}; //falta implementar para probar
void destruir (ColaPrioridad &cp) {}; //falta implementar para probar

T obtener(ColaPrioridad &cp) {
    T elem = cp->elem;

    ColaPrioridad aux = cp;
    cp = cp->sig;
    delete aux;

    return elem;  
};

bool indistinguibles(ColaPrioridad cp1, ColaPrioridad cp2) {
    bool loSon = true;

    ColaPrioridad cp1Aux = copia(cp1);
    ColaPrioridad cp2Aux = copia(cp2);

    while (loSon && cp1Aux != NULL && cp2Aux != NULL) {
        T elem1 = obtener(cp1Aux);
        T elem2 = obtener(cp2Aux);

        loSon = elem1 == elem2 && cantidad(cp1Aux) == cantidad(cp2Aux);
    }


    destruir(cp1Aux);
    destruir(cp2Aux);
    
    return loSon;
}

/* #############################################################################################
                                         PRUEBAS
   ############################################################################################# */

void imprimirCola(ColaPrioridad cp)
{
    while (cp != NULL)
    {
        printf("Pri.: ");
        printf("%d", cp->prioridad);
        printf(" | ");
        printf("Num.: ");
        printf("%d", cp->num);
        printf(" | ");
        printf(" ---> ");

        cp = cp->sig;
    }
}

ColaPrioridad colaDeEjemplo1() {
    ColaPrioridad cp = crearColaPrioridad();

    for (int i = 2; i < 15; i++)
    {
        encolar(cp, 2, i);
        encolar(cp, 3, i + 5);
        encolar(cp, 4, i - 1);
    };
};

ColaPrioridad colaDeEjemplo2() {
    ColaPrioridad cp = crearColaPrioridad();

    for (int i = 9; i < 15; i++)
    {
        encolar(cp, 2, i);
        encolar(cp, 3, i + 10);
        encolar(cp, 4, i - 8);
    };
};

void pruebaParteA() {
    ColaPrioridad cp = colaDeEjemplo1();

    printf("Se creo una cola de prioridad con esta cantidad de elementos: ");
    printf("%d", cantidad(cp));
    printf("\n");

    imprimirCola(cp);
}

void pruebaParteB() {
    ColaPrioridad cp1 = colaDeEjemplo1();
    ColaPrioridad cp2 = colaDeEjemplo2();
    ColaPrioridad cp3 = colaDeEjemplo1();
    ColaPrioridad cp4 = colaDeEjemplo2();

    if (indistinguibles(cp1, cp2)) {
        printf("Las colas de prioridad cp1 y cp2 son indistinguibles. \n");
    } else {
        printf("Las colas de prioridad cp1 y cp2 no son indistinguibles. \n");
    } 

    if (indistinguibles(cp1, cp3)) {
        printf("Las colas de prioridad cp1 y cp3 son indistinguibles. \n");
    } else {
        printf("Las colas de prioridad cp1 y cp3 no son indistinguibles. \n");
    }

    if (indistinguibles(cp4, cp2)) {
        printf("Las colas de prioridad cp4 y cp2 son indistinguibles. \n");
    } else {
        printf("Las colas de prioridad cp4 y cp2 no son indistinguibles. \n");
    }

}

int main()
{
    pruebaParteB();
}
