/*a) Especifique el TAD Tabla (mapping, función parcial) no acotada con dominio y rango de tipo int. Considere
operaciones para: 1) crear una tabla vacía, 2) agregar una correspondencia, 3) consultar la cantidad de
correspondencias, 4) saber si un valor del dominio tiene imagen, 5) obtener la imagen de un valor del
dominio, 6) eliminar una correspondencia, y 7) destruir una tabla. */
struct TablaNodo;
typedef struct TablaNodo *Tabla;
typedef int Dominio;
typedef int Rango;

//1) Pos: devuelve la Tabla vacía
Tabla crearTabla();

//2) Pos: agrega la correspondencia T(d) = r. Si ya existía T(d), sobreescribe el valor
void agregarCorrespondencia(Tabla T, Dominio d, Rango r);

//3) Pos: devuelve la cantidad de correspondencias que hay en la tabla
int cantidadCorrespondencias(Tabla T);

//4) Pos: devuelve true si T(d) existe y no es vacío, y false en caso contrario
bool tieneImagen(Tabla T, Dominio d);

//5) Pre: tieneImagen(tabla, d)
// Pos: devuelve T(d)
Rango obtenerImagen(Tabla T, Dominio d);

//6) Pos: si tieneImagen(T, d), la elimina, y de lo contrario no hace nada
void eliminarCorrespondencia(Tabla T, Dominio d);

//7) Pos: elimina una tabla y libera la memoria asociada a ella y a sus elementos
void eliminarTabla(Tabla T);

/*b) Implemente la función Tabla composicionRestringida (Tabla t1, Tabla t2, int min, int max)  que, dadas dos tablas 
t1 y t2 (de tipo Tabla) y dados dos enteros min y max (con min < max), retorne una tabla t3 que represente la composición 
de las funciones parciales representadas por t1 y t2, con valores en el dominio de t1 exclusivamente en el rango [min, max]. 
Esto es, para cada valor entero d en t1, tal que min <= d <= max, t3(d) debería ser t2(t1(d)). En caso que t2 no esté definida
para t1(d), d no debería aparecer en el dominio de t3. Implemente la función composicionRestringida considerado la especificación 
(y no una implementación) del TAD Tabla.*/

Tabla composicionRestringida (Tabla t1, Tabla t2, int min, int max) {
    Tabla t3 = crearTabla();

    for (int d = min; d <= max; d++) {
        Rango imagenT1 = obtenerImagen(t1, d);

        if (tieneImagen(t2, imagenT1)) {
            Rango imagenT2 = obtenerImagen(t2, imagenT1);
            agregarCorrespondencia(t3, d, imagenT2);
        }
    }

    return t3;
};

struct TablaNodo {
    Rango * img;
    TablaNodo * sig;
};

Tabla crearTabla() {
    Tabla t = new TablaNodo;
    return t;
};