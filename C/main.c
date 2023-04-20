#include "arbol.c"
#include <iostream>
#include <stdlib.h>

int main(){
    Nodo * raiz = crear_nodo(NULL, "Directorio" , "C/");
    ls(raiz);
    return 0;
}