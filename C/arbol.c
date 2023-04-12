#include "arbol.h"

Lista* crear_lista(int largo_maximo_inicial) {
    Lista* lista = malloc(sizeof(Lista)); // Asigna memoria para la estructura lista
    lista->largo_actual = 0; // Inicializa el largo actual en cero
    lista->largo_maximo = largo_maximo_inicial; // Asigna el largo máximo inicial
    lista->arreglo = malloc(sizeof(Nodo) * largo_maximo_inicial); // Asigna memoria para el arreglo de nodos
    return lista;
}

void insertar_lista(Lista* lista, Nodo* nodo) {
    if (lista->largo_actual >= lista->largo_maximo) { // Si el largo actual es mayor o igual al máximo, entonces duplica el tamaño del arreglo
        lista->largo_maximo *= 2;
        lista->arreglo = realloc(lista->arreglo, sizeof(Nodo) * lista->largo_maximo);
    }
    lista->arreglo[lista->largo_actual++] = *nodo; // Agrega el nodo al final del arreglo y aumenta el largo actual
}


