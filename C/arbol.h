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

// Crea una nueva lista .
Lista* crear_lista(int largo_maximo_inicial);

/* Agrega el nodo en la posicion  lista.largo_actual de lista.arreglo.
Si lista.largo_actual >= lista.largo_maximo , entonces se duplica
el tamano del arreglo y se actualiza lista.largo_maximo */
void insertar_lista(Lista* lista, Nodo* nodo);

//Retorna el hijo del directorio actual de un nombre dado
Nodo* buscar_directorio(Directorio* actual, char* nombre);
Nodo* buscar_archivo(Directorio* actual, char* nombre);

//Crea un nuevo nodo
Nodo* crear_nodo(Nodo* padre, char* tipo, char* nombre);

//crea un directorio actual y lo agrega como hijo del directorio actual
void mkdir(Nodo* actual, char * nombre_directorio);

//Crea un archivo y lo agrega como hijo del directorio actual
void touch(Nodo* actual, char* nombre_archivo);

//Busca un archivo y cambia su contenido
void write(Nodo* actual, char* nombre_archivo , char* contenido);

//Busca un archivo e imprime su contenido
void car(Nodo* actual, char* nombre_archivo);

//imprime todos los hijos del directorio actual o del seleccionado
void ls(Nodo* actual);
void ls_dir(Nodo* actual, char* nombre_directorio);
