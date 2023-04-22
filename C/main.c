#include "arbol.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Nodo* raiz = crear_raiz("C/");
    mkdir(raiz, "Nueva Carpeta");
    mkdir(raiz, "Otra carpeta");
    touch(raiz, "Nuevo Archivo");
    Nodo* prueba_busqueda_dir = buscar_directorio(((Directorio*)raiz->contenido),"Otra carpeta");

    ls(raiz);

    Nodo* prueba_busqueda_arch = buscar_archivo(((Directorio*)raiz->contenido), "Nuevo Archivo");

    write(raiz, "Nuevo Archivo" , "texto de ejemplo ");
    car(raiz, "Nuevo Archivo");

    raiz = cd(raiz, "Nueva Carpeta");
    mkdir(raiz, "Ejemplo");
    ls(raiz);
    raiz = cd(raiz,"..");
    ls(raiz);

    free(raiz->contenido);
    free(raiz);
    return 0;
}
