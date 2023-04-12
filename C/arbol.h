typedef struct{ 
    Nodo* padre;
    char tipo[64];
    void* contenido;
}Nodo;

typedef struct {
    int largo_actual;
    int largo_maximo;
    Nodo* arreglo;
}Lista;

typedef struct {
    char nombre[128];
    Lista* hijos;
}Directorio;

typedef struct{
    char nombre[128];
    char contenido[256];
} Archivo;