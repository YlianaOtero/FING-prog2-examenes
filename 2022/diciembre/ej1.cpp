/* Se quiere representar una estructura de directorios (carpetas) de un sistema operativo, donde cada directorio tiene
un nombre único que lo identifica. Cada directorio puede contener un número finito de subdirectorios y una lista
de archivos, donde cada archivo tiene un nombre y un contenido. 
Considere el tipo Directorios, definido como árboles generales de Archivos e implementado como árboles
binarios con la semántica primer hijo (pH) – siguiente hermano (sH): */

struct nodoArchivo { 
    char * nombreArchivo;
    char * contenidoArchivo; 
    nodoArchivo * sig; 
};

typedef nodoArchivo * Archivos; 

struct nodoDirectorio { 
    char * nombreDirectorio; 
    Archivos listaArchivos;
    nodoDirectorio * pH, * sH; 
};

typedef nodoDirectorio * Directorios;

/* Defina un procedimiento void borrar (Directorios & D, char * nom_dir)  que, dados un directorio D sin elementos repetidos 
y el nombre nom_dir de un directorio, elimine a nom_dir de D si nom_dir está en D. En caso contrario, el procedimiento no 
tendrá efecto. Al eliminar un directorio deberá liberarse toda la memoria asociada a éste, incluyendo la correspondiente
a los archivos que contenga y a sus subdirectorios. Utilice la función strEq (que se asume implementada) para comparar 
strings; strEq retorna true si y sólo si dos strings son iguales. Si usa funciones o procedimientos auxiliares, deberá  
implementarlos. */

void borrar (Directorios & D, char * nom_dir) {
    if (D != NULL) {
        if (strEq(D->nombreDirectorio, nom_dir)) {
            Directorios aBorrar = D;
            D = D->sH;

            delete [] aBorrar->nombreDirectorio;
            eliminarArchivos(aBorrar->listaArchivos);
            delete aBorrar;
        } else {
            borrar(D->pH, nom_dir);
            borrar(D->sH, nom_dir);
        }
    }
}


void eliminarArchivos(Archivos lista) {
    if (lista != NULL) {
        delete [] lista->nombreArchivo;
        delete [] lista->contenidoArchivo;
        
        eliminarArchivos(lista->sig);

        delete lista;
    }
}

void eliminarSubdirectorios(Directorios & D) {
    if (D != NULL) {
        eliminarSubdirectorios(D->pH);
        eliminarSubdirectorios(D->sH);

        delete [] D->nombreDirectorio;
        eliminarArchivos(D->listaArchivos);
        
        delete D;
    }
}