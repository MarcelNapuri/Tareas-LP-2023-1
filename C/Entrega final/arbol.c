#include "arbol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Crea una lista vacía con un tamaño máximo inicial especificado por el usuario.

Parámetros:
largo_maximo_inicial (int): entero que especifica el tamaño máximo inicial de la lista.

Retorno:
lista (Lista*) : puntero a una estructura Lista, que contiene un arreglo de nodos y otros campos necesarios para administrar una lista.
*/
Lista* crear_lista(int largo_maximo_inicial) {
    Lista* lista = (Lista*)malloc(sizeof(Lista)); 
    lista->largo_actual = 0; 
    lista->largo_maximo = largo_maximo_inicial; 
    lista->arreglo = (Nodo*)malloc(sizeof(Nodo) * lista->largo_maximo); 
    return lista;
}

/*
La función insertar_lista se encarga de agregar un nodo al final de una lista. Si la lista ya está llena, duplica el tamaño del arreglo de nodos.

Parametros:
lista (Lista*): Puntero a la estructura Lista que representa la lista en la que se agregará el nodo.
nodo (Nodo*): Puntero al Nodo que se agregará a la lista
*/
void insertar_lista(Lista* lista, Nodo* nodo) {
    if (lista->largo_actual >= lista->largo_maximo) { // Si el largo actual es mayor o igual al máximo, entonces duplica el tamaño del arreglo
        lista->largo_maximo *= 2;
        lista->arreglo = (Nodo*)realloc(lista->arreglo,sizeof(Nodo) * lista->largo_maximo);
    }

    if (lista->largo_actual < lista->largo_maximo){
        lista->arreglo[lista->largo_actual] = *nodo; // Agrega el nodo al final del arreglo y aumenta el largo actual
        lista->largo_actual++;
    }
}

/*
La función busca en el directorio actual un hijo cuyo nombre coincida con el nombre pasado como parámetro. Si encuentra un hijo con ese nombre, devuelve un puntero al nodo correspondiente. Si no lo encuentra, devuelve NULL.

Parámetros:
actual (Directorio*): Puntero al directorio en el que se desea buscar el hijo.
nombre (char*): Nombre del hijo que se desea buscar.

Retorno:
hijo (Nodo*) : Puntero al nodo correspondiente al hijo con el nombre especificado. Si no se encuentra, devuelve NULL.
*/
Nodo* buscar_directorio(Directorio* actual, char* nombre){
    if (actual->hijos == NULL){
        printf("No se encontro\n");
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo * hijo = &actual->hijos->arreglo[i];
        if(strcmp(((Directorio*)hijo->contenido)->nombre,nombre) == 0){
            return hijo;
        }
    }
    printf("No se encontro aqui\n");
    return NULL;
}

/*
Esta funcion busca un archivo en un directorio dado.

Parametros :
actual ( Directorio* ) : Un puntero al directorio actual en el que se va a buscar el archivo.
nombre ( char* ) : El nombre del archivo que se esta buscando.

Retorno :
hijo ( Nodo* ) : Puntero correspondiente al archivo encontrado. Devuelve NULL si no se encuentra.
*/
Nodo* buscar_archivo(Directorio* actual, char* nombre){
    if(actual->hijos == NULL){
        return NULL;
    }
    for(int i = 0; i < actual->hijos->largo_actual; i++){
        Nodo* hijo = &actual->hijos->arreglo[i];
        if(strcmp(((Archivo*)hijo->contenido)->nombre,nombre) == 0)  {
            return hijo;
        }
    }
    printf("No se encontro aqui\n");
    return NULL;

}
/*
crea y retorna un nuevo nodo vacío, asignándole un padre y un nombre. Este nodo aún no tiene contenido.

Parámetros:

padre (Nodo*): el puntero al nodo padre del nuevo nodo.
tipo (char*): una cadena de caracteres que representa el tipo de nodo (archivo o directorio).
nombre (char*): una cadena de caracteres que representa el nombre del nuevo nodo.

Retorno:

nodo (Nodo*): el puntero al nuevo nodo creado.
*/
Nodo* crear_nodo(Nodo* padre, char* tipo, char* nombre) {    //son nodos vacios
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->padre = padre;
    strcpy(nodo->tipo,tipo);
    nodo->contenido = NULL;
    return nodo;     
}
/*
crea un nuevo directorio dentro del directorio actual y lo agrega a la lista de hijos del directorio actual.

Parámetros:

actual (Nodo*): puntero al nodo del directorio actual donde se creará el nuevo directorio.
nombre_directorio (char*): nombre del nuevo directorio a crear.
*/
void mkdir(Nodo* actual, char * nombre_directorio){
    Nodo* nodo_directorio = crear_nodo(actual, "Directorio" , nombre_directorio);
    nodo_directorio->contenido = (Directorio*)malloc(sizeof(Directorio));
    insertar_lista(((Directorio*)actual->contenido)->hijos, nodo_directorio);
    strcpy(((Directorio*)nodo_directorio->contenido)->nombre, nombre_directorio);
    ((Directorio*)nodo_directorio->contenido)->hijos = crear_lista(1);
}

/*
Crea un nuevo archivo vacío con el nombre dado y lo agrega a la lista de hijos del nodo actual.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
nombre_archivo (char*): el nombre que se le quiere dar al nuevo archivo.
*/
void touch(Nodo* actual, char* nombre_archivo){
    Nodo* nodo_archivo = crear_nodo(actual, "Archivo", nombre_archivo);
    nodo_archivo->contenido = (Archivo*)malloc(sizeof(Archivo));
    insertar_lista(((Directorio*)actual->contenido)->hijos, nodo_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->nombre, nombre_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->contenido, "");
}

/*
Escribe el contenido dado en el archivo con el nombre indicado en el directorio actual.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
nombre_archivo (char*): el nombre del archivo en el que se quiere escribir.
contenido (char*): el contenido que se quiere escribir en el archivo.
*/
void write(Nodo* actual, char* nombre_archivo , char* contenido){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido),nombre_archivo);
    strcpy(((Archivo*)nodo_archivo->contenido)->contenido,contenido);
}

/*
Imprime el contenido del archivo con el nombre dado.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
nombre_archivo (char*): el nombre del archivo del cual se quiere imprimir el contenido.
*/
void cat(Nodo* actual, char* nombre_archivo){
    Nodo* nodo_archivo = buscar_archivo(((Directorio*)actual->contenido),nombre_archivo);
    char* texto = ((Archivo*)nodo_archivo->contenido)->contenido;
    printf("%s\n" , texto);
}

/*
Imprime por pantalla los nombres de los archivos y subdirectorios que se encuentran en el directorio actual.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
*/
void ls(Nodo* actual){
    for(int i = 0; i < ((Directorio*)actual->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = &((Directorio*)actual->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}

/*
Muestra los nombres de los archivos y subdirectorios dentro de un directorio específico del nodo actual,
o del nodo actual mismo si se especifica una cadena vacía como nombre del directorio.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
nombre_directorio (char*): el nombre del directorio cuyos hijos se quieren mostrar. Si se especifica una cadena vacía, se muestran los hijos del nodo actual.
*/
void ls_dir(Nodo* actual, char* nombre_directorio){
    if (strcmp(nombre_directorio,"") == 0)
    {
        ls(actual);
        return;
    }
    
    Nodo* nuevo_directorio = buscar_directorio(((Directorio*)actual->contenido),nombre_directorio);
    for(int i = 0; i < ((Directorio*)nuevo_directorio->contenido)->hijos->largo_actual; i++){
        Nodo* hijo = &((Directorio*)nuevo_directorio->contenido)->hijos->arreglo[i];
        printf("%s\n", ((Directorio*)hijo->contenido)->nombre);
    }
}

/*
Aplica una instrucción a todos los nodos de tipo Directorio presentes en el árbol de directorios a partir del nodo actual. 
La instrucción a aplicar se especifica como un puntero a función.

Parámetros:
actual (Nodo*): el nodo actual en el que se está trabajando.
instruccion (void(instruccion)(Nodo, char*)): el puntero a función que representa la instrucción a aplicar a cada nodo Directorio.
parametro_instruccion (char*): un parámetro adicional que se pasa a la función instrucción.
*/
void mapdir(Nodo* actual , void(*instruccion)(Nodo*, char*) , char* parametro_instruccion){
    if(strcmp(actual->tipo,"Directorio") == 0){
        for (int i = 0; i < ((Directorio*)actual->contenido)->hijos->largo_actual; i++){
            Nodo* hijo = &((Directorio*)actual->contenido)->hijos->arreglo[i];
            if (strcmp(hijo->tipo,"Directorio") == 0){
                instruccion(hijo, parametro_instruccion);
            }
        }
        
    }
    else
    {
        printf("No se puede aplicar el comando a '%s'. Solo se puede aplicar a directorios.\n", ((Archivo*)actual->contenido)->nombre);

    }
    
}

/*
Crea un nodo raíz para el sistema de archivos con el nombre especificado y lo inicializa como un directorio vacío.

Parámetros:
nombre (char*): el nombre que se le quiere dar al nodo raíz.

Retorno:
raiz (Nodo*): el nodo raíz creado.
*/
Nodo* crear_raiz(char* nombre){
    Nodo* raiz = (Nodo*)malloc(sizeof(Nodo));
    raiz->padre = NULL; 
    strcpy(raiz->tipo,"Directorio");
    raiz->contenido = (Directorio*)malloc(sizeof(Directorio));
    strcpy(((Directorio*)raiz->contenido)->nombre, nombre);
    ((Directorio*)raiz->contenido)->hijos = crear_lista(1);
    return raiz;
}

/*
Cambia el directorio actual al directorio especificado por nombre_directorio. 
Si nombre_directorio es "..", se moverá al directorio padre del directorio actual.

Parámetros:
actual (Nodo*): el nodo que representa el directorio actual.
nombre_directorio (char*): el nombre del directorio al que se desea mover.

Retorno:

actual (Nodo*) :Si se encuentra el directorio especificado, se devuelve un puntero al nodo que lo representa. Si no lo encuentra, devuelve NULL
*/
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

/*
Libera toda la memoria utilizada por el árbol de directorios y archivos a partir del nodo actual.

Parámetros:
actual (Nodo*): el nodo actual a partir del cual se desea liberar la memoria.
*/
void liberar_memoria(Nodo* actual){
    if (actual == NULL) { // Si el nodo es nulo, no hay nada que liberar
        return;
    }
    if (strcmp(actual->tipo, "Archivo") == 0) { // Si es un archivo, solo liberamos su memoria
        free(actual->contenido);
        free(actual);
        return;
    }
    // Si es un directorio, recorremos su lista de hijos y llamamos recursivamente a la función para cada uno de ellos
    for (int i = 0; i < ((Directorio*)actual->contenido)->hijos->largo_actual; i++){
        liberar_memoria(&((Directorio*)actual->contenido)->hijos->arreglo[i]);
    }
    free(((Directorio*)actual->contenido)->hijos->arreglo);
    free(((Directorio*)actual->contenido)->hijos);
    free(actual->contenido);
    free(actual);
}
