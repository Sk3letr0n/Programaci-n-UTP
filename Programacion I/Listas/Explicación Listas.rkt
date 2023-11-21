; Racket documentation cons
; listas
; Una lista es un par ordenado compuesto por
; (car, cdr)
; donde car es el 1er elemento de la lista
; y cdr es el resto de la lista
; null representa lista vacía

(define milista(list 3 6 5 7 6 8 7 9 8 2 3 4 5))
(define tulista(list 4 6 5 7))
(define estudiantes(list "manuela" "lelion" "juan andres" "juan jose" "samuel"))
(define edades (list 16 19 18 19 21))


; Función que suma los datos de una lista numérica
(define (sumaLista lista)
  (if(null? lista)
     0
     (+ (car lista)
        (sumaLista (cdr lista)))
     ))

; Función que cuenta los elementos de una lista
(define (cuentaLista lista)
  (if(null? lista)
     0
     (+ 1 (cuentaLista (cdr lista)))
     ))

; promedio de una lista
(define (promedioLista lista)
  (/ (sumaLista lista)(cuentaLista lista)))

; mostrar los datos de una lista
(define (muestraLista lista1 lista2)
  (if(null? lista1)
     (display "")
     (begin
       (display (car lista1))
       (display "\t")
       (display (car lista2))
       (newline)
       (muestraLista (cdr lista1) (cdr lista2)))
     ))
     
; Cómo saber la longitud de una cadena
; Racket Documentation string
; Racket Documentation list->vector vector->list


; 1. Construir una función que encuentre el número menor de una lista
; 2. Construir una función que determina si el primer número de una
; lista está repetido dentro de ella
; 3. Construir un función que determine si el promedio de una lista
; numérica de datos enteros se encuentra entre la misma lista
; (4 6 5 6 5 4) --> promedio 5
; 4. Construir una función que determine si una lista numérica
; está ordenada ascendentemente
;(3 5 7 8)-> esta sí, (5 3 7 1)--> esta no