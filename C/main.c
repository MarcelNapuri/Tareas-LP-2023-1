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
            cat(raiz,nombre);
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
        else if (strcmp(comando,"mapdir") == 0)
        {

            char* funcion = strtok(NULL, delimitador);
            if(strcmp(funcion,"ls") == 0){
                mapdir(raiz, &ls_dir,"");
            }
            else if (strcmp(funcion,"mkdir") == 0){
                char* parametro = strtok(NULL, "");
                mapdir(raiz,&mkdir,parametro);
            }
            else if (strcmp(funcion,"touch") == 0){
                char* parametro = strtok(NULL, "");
                mapdir(raiz,&touch,parametro);
            }
            else
            {
                printf("comando incorrecto\n");
            }
            
        }
        
        else if (strcmp(comando,"close") == 0)
        {
            while (raiz->padre != NULL)
            {
                raiz = cd(raiz, "..");
            }
            
            flag = false;
        }
        else
        {
            printf("comando incorrecto\n");
        }
        
    } 
    liberar_memoria(raiz);
    return 0;
}


