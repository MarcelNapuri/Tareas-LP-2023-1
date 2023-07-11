Marcel Silva Napuri
202173597-6

Instrucciones:
    - El directorio cuenta con un unico archivo main.rkt, el cual se debe ejecutar desde el editor DrRacket.
    - Las funciones principales estan separadas por guiones (---)
    - Al final de cada funcion, existen casos de pruebas para las funciones, se debe suprimir el signo ; en los casos de prueba
      por ejemplo: ;(encode '(0 0 0 1 1 0 1 1 1 0 0 0))

Consideraciones:
    - en la funcion decode_cola , la lista generada esta invertida debido a la recursion de cola propiamente tal,
      por ejemplo con el caso de prueba: (decode_cola '( 3 2 1 3 3 )) , en lugar de salir ( 0 0 0 1 1 0 1 1 1 0 0 0) aparece 
      (0 0 0 1 1 1 0 1 1 0 0 0 )
    -Racket : Welcome to Racket v8.6 [cs].