#include <stdio.h>
#include "ej2.cpp"
/*Una empresa almacena los sueldos de sus empleados en tablas (de tipo Tabla, según la especificación dada en el
Problema 2) donde el dominio de tipo unsigned int (nat) corresponde al número de empleado y el codominio de
tipo float corresponde al salario del empleado. 
La empresa quiere consolidar salarios dispersos en varias tablas, para esto se propone implementar una función
consolidar que, dadas dos tablas t1 y t2 (de tipo Tabla) genere una nueva tabla (de tipo Tabla) que contenga los
sueldos de los empleados que están en t1 o en t2. Si un empleado está en las dos tablas, se tomará la suma de los
salarios que tenga en ambas tablas, y si está solamente en una tabla, se tomará su sueldo en dicha tabla. Para la
operación consolidar se considerarán solamente empleados cuyos número de empleado sea mayor o igual que inf y
menor o igual que sup (asumimos inf < sup). Implemente consolidar sin acceder a la representación del TAD
Tabla*/

Tabla consolidar (Tabla t1, Tabla t2, nat inf, nat sup) {

}