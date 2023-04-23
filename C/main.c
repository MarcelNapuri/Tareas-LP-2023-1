#include "arbol.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    Nodo* raiz = crear_raiz("C/");
    char *input = NULL;
    char delimitador[] = " ";
    bool flag = true;
    size_t len = 0;

    while (flag){
        ssize_t read = getline(&input, &len, stdin);
        input[read-1] = '\0';
        char* comando = strtok(input, delimitador); 
        
        if(strcmp(comando,"mkdir") == 0 ){
            char * nombre = strtok(NULL, "");
            mkdir(raiz, nombre);
            //printf("Directorio %s creado con exito\n", nombre);   
        }
        else if (strcmp(comando,"cd") == 0)
        {
            char* nombre = strtok(NULL , "");
            raiz = cd(raiz, nombre);
        }

        else if (strcmp(comando,"touch") == 0)
        {
            char* nombre = strtok(NULL, "");
            touch(raiz, nombre);
        }
        
        else if (strcmp(comando, "write") == 0)
        {
            char* nombre = strtok(NULL, delimitador);
            char* texto = strtok(NULL, "");
            write(raiz, nombre , texto);
        }
        
        else if (strcmp(comando, "cat") == 0)
        {
            char* nombre = strtok(NULL, "");
            car(raiz,nombre);
        }
        
        else if (strcmp(comando,"ls") == 0)
        {   
            char* nombre_archivo = strtok(NULL, delimitador);

            if(nombre_archivo == NULL ){
                
                ls(raiz); 
            }
            else
            {
               ls_dir(raiz, nombre_archivo);
            }
            
        }
        else if (strcmp(comando,"close") == 0)
        {
            flag = false;
        }
        else
        {
            printf("comando incorrecto\n");
        }
        
    } 

    

    return 0;
}


/*
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
    touch(raiz, "Archivo de prueba para ver ls_dir");
    ls(raiz);
    raiz = cd(raiz,"..");
    ls(raiz);
    ls_dir(raiz,"Nueva Carpeta");
    ls(raiz);

    free(raiz->contenido);
    free(raiz);
    return 0;   
*/