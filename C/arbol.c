#include "arbol.h"
#include <stdlib.h>
#include <iostream>

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
        lista->arreglo = (Nodo*)realloc(lista->arreglo,sizeof(Nodo) * lista->largo_maximo);
    }
    lista->arreglo[lista->largo_actual] = *nodo; // Agrega el nodo al final del arreglo y aumenta el largo actual
    lista->largo_actual++;
}

Nodo* buscar_directorio(Directorio* actual, char* nombre){
    if (actual->hijos == NULL){
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo * hijo = &actual->hijos->arreglo[i];
        if(((Directorio*)hijo->contenido)->nombre == nombre){
            return hijo;
        }
    }
}

Nodo* buscar_archivo(Directorio* actual, char* nombre){
    if(actual->hijos == NULL){
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo* hijo = &actual->hijos->arreglo[i];
        if(((Archivo*)hijo->contenido)->nombre == nombre){
            return hijo;
        }
    }
}

Nodo* crear_nodo(Nodo* padre, char* tipo, char* nombre) {    //son nodos vacios
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->padre = padre;
    nodo->tipo = tipo;
    nodo->contenido = NULL;
    return nodo;     
}

void mkdir(Nodo* actual, char * nombre_directorio){
    Nodo* nuevo_nodo = crear_nodo(actual, "Directorio" , nombre_directorio);
    Directorio* nuevo_directorio = (Directorio*)malloc(sizeof(Directorio));
    nuevo_directorio->nombre = nombre_directorio;
    nuevo_directorio->hijos = crear_lista(10);
    nuevo_nodo->contenido = nuevo_directorio;
    insertar_lista(((Directorio*)actual->contenido)->hijos, nuevo_nodo);
}

void touch(Nodo* actual, char* nombre_archivo){
    Nodo* nuevo_nodo = crear_nodo(actual, "Archivo", nombre_archivo);
    Archivo* nuevo_archivo = (Archivo*)malloc(sizeof(Archivo));
    nuevo_archivo->nombre = nombre_archivo;
    nuevo_archivo->contenido = "";
    nuevo_nodo->contenido = nuevo_archivo;
    insertar_lista(((Directorio*)actual->contenido)->hijos, nuevo_nodo);
}

void write(Nodo* actual, char* nombre_archivo , char* contenido){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido)->hijos,nombre_archivo);
    ((Archivo*)nodo_archivo->contenido)->contenido = contenido;
}

void car(Nodo* actual, char* nombre_archivo){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido)->hijos,nombre_archivo);
    char* texto = ((Archivo*)nodo_archivo->contenido)->contenido;
    printf("%s" , texto);
}

void ls(Nodo* actual){
    for(int i = 0; i < ((Directorio*)actual->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = ((Directorio*)actual->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}

void ls_dir(Nodo* actual, char* nombre_directorio){
    Nodo* nuevo_directorio = buscar_directorio(((Directorio*)actual->contenido)->hijos,nombre_directorio);
    for(int i = 0; i < ((Directorio*)nuevo_directorio->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = ((Directorio*)nuevo_directorio->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}