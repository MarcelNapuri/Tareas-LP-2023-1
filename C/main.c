#include "arbol.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Nodo* raiz = crear_raiz("C/");
    mkdir(raiz, "Nueva Carpeta");
    mkdir(raiz, "Otra carpeta");
    touch(raiz, "Nuevo Archivo");

    free(raiz->contenido);
    free(raiz);
    return 0;
}