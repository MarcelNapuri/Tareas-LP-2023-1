#include "arbol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Lista* crear_lista(int largo_maximo_inicial) {
    Lista* lista = (Lista*)malloc(sizeof(Lista)); // Asigna memoria para la estructura lista
    lista->largo_actual = 0; // Inicializa el largo actual en cero
    lista->largo_maximo = largo_maximo_inicial; // Asigna el largo máximo inicial
    lista->arreglo = (Nodo*)malloc(sizeof(Nodo) * lista->largo_maximo); // Asigna memoria para el arreglo de nodos
    return lista;
}

void insertar_lista(Lista* lista, Nodo* nodo) {
    //printf("Antes de realloc: largo_maximo=%d, largo_actual=%d\n", lista->largo_maximo, lista->largo_actual);
    if (lista->largo_actual >= lista->largo_maximo) { // Si el largo actual es mayor o igual al máximo, entonces duplica el tamaño del arreglo
        lista->largo_maximo *= 2;
        lista->arreglo = (Nodo*)realloc(lista->arreglo,sizeof(Nodo) * lista->largo_maximo);
    }

    //printf("Después de realloc: largo_maximo=%d, largo_actual=%d\n", lista->largo_maximo, lista->largo_actual);
    if (lista->largo_actual < lista->largo_maximo){
        lista->arreglo[lista->largo_actual] = *nodo; // Agrega el nodo al final del arreglo y aumenta el largo actual
        lista->largo_actual++;
    }
}

Nodo* buscar_directorio(Directorio* actual, char* nombre){
    if (actual->hijos == NULL){
        printf("No se encontro\n");
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo * hijo = &actual->hijos->arreglo[i];
        //printf("%s\n" , ((Nodo*)hijo->contenido)->tipo);
        if(strcmp(((Directorio*)hijo->contenido)->nombre,nombre) == 0){
            //printf("Directorio %s hallado correctamente\n", ((Directorio*)hijo->contenido)->nombre);
            return hijo;
        }
    }
    printf("No se encontro aqui\n");
    return NULL;
}

Nodo* buscar_archivo(Directorio* actual, char* nombre){
    if(actual->hijos == NULL){
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo* hijo = &actual->hijos->arreglo[i];
        if(strcmp(((Archivo*)hijo->contenido)->nombre,nombre) == 0)  {
            //printf("Archivo %s hallado correctamente\n", ((Directorio*)hijo->contenido)->nombre);
            return hijo;
        }
    }
    printf("No se encontro aqui\n");
    return NULL;

}

Nodo* crear_nodo(Nodo* padre, char* tipo, char* nombre) {    //son nodos vacios
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->padre = padre;
    strcpy(nodo->tipo,tipo);
    nodo->contenido = NULL;
    //printf("Nodo creado correctamente\n");
    //printf("%s\n" , nodo->tipo);
    return nodo;     
}

void mkdir(Nodo* actual, char * nombre_directorio){
    Nodo* nodo_directorio = crear_nodo(actual, "Directorio" , nombre_directorio);
    //printf("%s\n" , nodo_directorio->tipo);
    nodo_directorio->contenido = (Directorio*)malloc(sizeof(Directorio));
    insertar_lista(((Directorio*)actual->contenido)->hijos, nodo_directorio);
    strcpy(((Directorio*)nodo_directorio->contenido)->nombre, nombre_directorio);
    ((Directorio*)nodo_directorio->contenido)->hijos = crear_lista(5);
    //printf("%s creado con exito\n", nombre_directorio);
}

void touch(Nodo* actual, char* nombre_archivo){
    Nodo* nodo_archivo = crear_nodo(actual, "Archivo", nombre_archivo);
    //printf("%s\n" , nodo_archivo->tipo);
    nodo_archivo->contenido = (Archivo*)malloc(sizeof(Archivo));
    insertar_lista(((Directorio*)actual->contenido)->hijos, nodo_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->nombre, nombre_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->contenido, "");
    //printf("%s creado con exito\n", nombre_archivo);
}

void write(Nodo* actual, char* nombre_archivo , char* contenido){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido),nombre_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->contenido,contenido);
}

void car(Nodo* actual, char* nombre_archivo){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido),nombre_archivo);
    char* texto = ((Archivo*)nodo_archivo->contenido)->contenido;
    printf("%s\n" , texto);
}

void ls(Nodo* actual){
    for(int i = 0; i < ((Directorio*)actual->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = &((Directorio*)actual->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}


void ls_dir(Nodo* actual, char* nombre_directorio){
    Nodo* nuevo_directorio = buscar_directorio(((Directorio*)actual->contenido),nombre_directorio);
    for(int i = 0; i < ((Directorio*)nuevo_directorio->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = &((Directorio*)nuevo_directorio->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}


Nodo* crear_raiz(char* nombre){
    Nodo* raiz = (Nodo*)malloc(sizeof(Nodo));
    raiz->padre = NULL; 
    strcpy(raiz->tipo,"Directorio");
    raiz->contenido = (Directorio*)malloc(sizeof(Directorio));
    strcpy(((Directorio*)raiz->contenido)->nombre, nombre);
    ((Directorio*)raiz->contenido)->hijos = crear_lista(5);
    //printf("%s\n" , raiz->tipo);
    return raiz;
}

Nodo* cd(Nodo* actual , char* nombre_directorio){
    if (strcmp(nombre_directorio,"..") == 0)
    {
        actual = actual->padre;
        return actual;
    }
    else
    {
        Nodo* busqueda = buscar_directorio(((Directorio*)actual->contenido), nombre_directorio);
        actual = busqueda;
        return actual;
    }
    printf("No se encontro el directorio\n");
    return NULL;

}


void liberar_memoria(Nodo* actual){
    if(actual == NULL){
        return;
    }
    if(strcmp(actual->tipo,"archivo") == 0){
        A
    }
}

/*
void liberar_directorio(Directorio* dir) {
    for(int i = 0; i < dir->hijos->largo_actual; i++) {
        Nodo* hijo = &dir->hijos->arreglo[i];
        if(strcmp(hijo->tipo, "Directorio") == 0) {
            liberar_directorio(hijo->contenido);
        } else {
            free(hijo->contenido);
        }
        free(hijo);
    }
    free(dir->hijos->arreglo);
    free(dir->hijos);
    free(dir);
}
*/