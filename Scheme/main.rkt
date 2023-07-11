#lang scheme

;----------------- ENCODE --------------;

;;Codifica una lista de bits, llama a encode_aux para hacer la codificacion correctamente, si la lista no empieza con 0 , lo agrega y llama a una encode-aux
;;
;;bits: Recibe una lista de bits
(define (encode bits)
  (cond
    ((null? bits) '())
    ((= 0 (car bits))(encode-aux bits))
    (else
     (cons 0 (encode-aux bits)))))

;;función auxiliar para la codificación de bits, llama contar_encode .
;;
;; bits : recibe una lista de bits
(define (encode-aux bits)
  (let ((x (car bits))
        (cont 1))
  (contar-encode (cdr bits) x cont)))

;; Función auxiliar que cuenta la cantidad de bits consecutivos iguales en una lista
;;
;; lista: lista de bits
;; ultima: último bit procesado
;; contador: contador que cuento los bits consecutivos
(define (contar-encode lista ultima contador)
  (cond
    ((null? lista) (list contador))
    ((= ultima (car lista))
     (contar-encode(cdr lista) ultima (+ 1 contador)))
     (else
      (cons contador (contar-encode(cdr lista) (car lista) 1 )))))

;casos de prueba
;(encode '(0 0 0 1 1 0 1 1 1 0 0 0))
;(encode '(1 1 0 1 1 1 0 0 0))
;(encode '( 0 1 0 1 1 1 0 0 0 ))


;----------------- DECODE-SIMPLE --------------;

;;decodifica una lista con cantidades de bits usando recursion simple, llama a una funcion auxiliar para decodificar correctamente
;;
;; lista: lista de enteros codificada
(define (decode_simple lista)
  (if (null? lista) '()
      (let ((contador (car lista)))          
        (decode_simple_aux contador 0 lista))))

;; Función auxiliar para la decodificación simple de una lista.
;;
;; n: Contador de bits consecutivos.
;; simbolo: Símbolo actual.
;; lista: Lista de enteros codificada
(define (decode_simple_aux  n simbolo lista)
  (cond
    ((= n 0)
     (if (null? lista)
         '()
         (if (null? (cdr lista))
             '()
             (decode_simple_aux (car(cdr lista)) (if (= simbolo 0) 1 0) (cdr lista)))))
         
    (else
     (cons simbolo (decode_simple_aux (- n 1) simbolo lista)))))

;casos de prueba
;(decode_simple '( 3 2 1 3 3 ))
;(decode_simple '(0 2 1 3 3))
;(decode_simple '(4))


;----------------- DECODE-COLA --------------;

;; Decodifica una lista codificada con recursión de cola. Llama a una funcion auxiliar para decodificar correctamente
;;
;;lista: Lista de enteros codificada.
(define decode_cola
  (lambda (lista)
    (decode_cola_aux (car lista) 0 lista '())))


;;decode_cola_aux: Función auxiliar para la decodificación con recursion de cola
;;
;; n: Contador de bits consecutivos.
;; simbolo: Símbolo actual.
;; lista: Lista de enteros codificada.
;; acumulador: Lista acumuladora de bits decodificados.
(define decode_cola_aux
  (lambda (n simbolo lista acumulador)
    (cond
      ((null? lista) acumulador)
      ((= n 0)
       (if (null? (cdr lista))
           acumulador
           (decode_cola_aux (car (cdr lista)) (if (= simbolo 0) 1 0) (cdr lista) acumulador)))
      (else
       (decode_cola_aux (- n 1) simbolo lista (cons simbolo acumulador))))))

;casos de prueba
;(decode_cola '( 3 2 1 3 3 ))
;(decode_cola '(0 2 1 3 3))
;(decode_cola '(4))


;----------------- INTEGRAR-SIMPLE --------------;

;; Calcula la integral de una función utilizando el método de recursion simple.
;;
;; a: Límite inferior de integración.
;; b: Límite superior de integración.
;; n: Número de subintervalos.
;; funcion: Función a integrar
(define (integrar_simple a b n funcion)
  (define delta (/ (- b a) n))
  (define f_a (/(funcion a)2))
  (define f_b (/(funcion b)2))

  ;; Calcula la sumatoria de la función en los subintervalos.
  ;;
  ;; a: Límite inferior de integración.
  ;; delta: Ancho de cada subintervalo.
  ;; k: Índice actual de la sumatoria.
  ;; acumulador: Acumulador de la sumatoria.
  ;; funcion: Función a evaluar.
  (letrec ((sumatoria (lambda (k acumulador)
                        (if (= k n)
                            acumulador
                            (sumatoria (+ k 1) (+ acumulador (funcion (+ a (* k delta)))))))))
    (* delta (+ f_a f_b (sumatoria 1 0)))))

;casos de prueba
;(integrar_simple 0 1 4 (lambda (x) (* x x)))
;(integrar_simple 1 10 100 (lambda (x) (/ (log x) (log 2))))


;----------------- INTEGRAR-COLA --------------;

;; Calcula la integral de una función utilizando el método de recursion de cola.
;;
;; a: Límite inferior de integración.
;; b: Límite superior de integración.
;; n: Número de subintervalos.
;; funcion: Función a integrar
(define (integrar_cola a b n funcion)
  (define delta (/ (- b a) n))
  (define f_a (/(funcion a)2))
  (define f_b (/(funcion b)2))

  ;; Calcula la sumatoria de la función en los subintervalos.
  ;;
  ;; k: Índice actual de la sumatoria.
  ;; acumulador: Acumulador de la sumatoria.
  ;; fa: Funcion evaluada en a
  ;; fb: Funcion evaluada en b
  ;; d: delta(ancho de cada subintervalo)
  (letrec ((sumatoria_cola (lambda( k acumulador fa fb d)
                              (if (= k n)
                                  (* (+ acumulador fa fb) d )
                                  (sumatoria_cola (+ k 1) (+ acumulador (funcion (+ a (* k delta)))) fa fb d  )))))
    (sumatoria_cola 1 0 f_a f_b delta) ))

;casos de prueba
;(integrar_cola 0 1 4 (lambda (x) (* x x)))
;(integrar_cola 1 10 100 (lambda (x) (/ (log x) (log 2))))


;----------------- MAP_ARBOL --------------;

;; Aplica una función a los nodos de un árbol binario según un camino dado
;;
;; arbol: Árbol binario de la forma '(valor nodo_izquierdo nodo_derecho)
;; camino: Lista de 0s y 1s que indica el camino a seguir en el árbol
;; funcion: Función lambda que se aplicará a los nodos del camino
(define map_arbol
  (lambda( arbol camino funcion )
    (cond
      ((null? arbol) '())
      ((null? camino) (list (aplicar_funcion (car arbol) funcion) (cadr arbol) (caddr arbol)) )
      (else
       (let ((valor (car arbol))
             (siguiente (if (= (car camino) 0)
                            (cadr arbol)
                            (caddr arbol))))
         (if (= (car camino) 0)
             (list (aplicar_funcion valor funcion) (map_arbol siguiente (cdr camino)  funcion) (caddr arbol))
             (list (aplicar_funcion valor funcion) (cadr arbol) (map_arbol siguiente (cdr camino) funcion) )))))))
                 
;;Aplica una función lambda a un valor de nodo
;;
;; valor_nodo: Valor del nodo al que se aplicará la función
;; funcion: Función lambda a aplicar al valor del nodo     
(define aplicar_funcion
  (lambda (valor_nodo funcion)
    (funcion valor_nodo)))


;casos de prueba
;(map_arbol '(2 (3 () ()) (4 () ())) '(1) (lambda (x) (* x x)))
;(map_arbol '(2 (3 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ()))) '(1 0 0) (lambda (x) (* x x)))
;(map_arbol '(2 (3 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ()))) '(0) (lambda (x) (* x x)))