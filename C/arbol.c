#include "arbol.h"

Lista* crear_lista(int largo_maximo_inicial) {
    Lista* lista = (Lista*)malloc(sizeof(Lista)); // Asigna memoria para la estructura lista
    lista->largo_actual = 0; // Inicializa el largo actual en cero
    lista->largo_maximo = largo_maximo_inicial; // Asigna el largo máximo inicial
    lista->arreglo = (Nodo*)malloc(sizeof(Nodo) * largo_maximo_inicial); // Asigna memoria para el arreglo de nodos
    return lista;
}

void insertar_lista(Lista* lista, Nodo* nodo) {
    if (lista->largo_actual >= lista->largo_maximo) { // Si el largo actual es mayor o igual al máximo, entonces duplica el tamaño del arreglo
        lista->largo_maximo *= 2;
        lista->arreglo = realloc(lista->arreglo, sizeof(Nodo) * lista->largo_maximo);
    }
    lista->arreglo[lista->largo_actual++] = *nodo; // Agrega el nodo al final del arreglo y aumenta el largo actual
}

Nodo* crear_nodo(Nodo* padre, char* tipo, char* nombre) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->padre = padre;
    nodo->tipo = tipo;
    
    if (tipo == "directorio"){
        Directorio* nuevo_directorio = (Archivo*)malloc(sizeof(Directorio));
        nuevo_directorio->nombre = nombre;
        nuevo_directorio->hijos = crear_lista(10);
        nodo->contenido = nuevo_directorio;    
    }

    else if (tipo == "archivo"){
        Archivo* nuevo_archivo = (Archivo*)malloc(sizeof(Archivo));
        nuevo_archivo->nombre = nombre;
        nuevo_archivo->contenido = "";
        nodo->contenido = nuevo_archivo;
    }

    return nodo; 
}


