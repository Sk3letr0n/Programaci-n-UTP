#| Enunciado/Objetivo:
Construir un programa que lea dos números enteros y muestre todos los enteros comprendidos entre entre ellos.

Análisis semántico:
Leer los números entre n y m, ej: 15, 8--> 8 9 10 11 12 13 14 15

Análisis EPS:
Entrada: n m
Proceso: 1. Leer n - 2. Leer m - 3. Buscar los números comprendidos entre n y m
Salida: Mostrar los números
|#
;Código
(define (Suman n)
  (display n)
  (display " ")  
)
(define (sumam m)
  (display m)
  (display " ")
)
  
(define (ciclo1 m n)
  (if  (= m n)
       (sumam m)
       (begin (suman n)  b
           (ciclo1 m (- n 1))        
       )     
  )
)

(define (ciclo2 m n)
  (if  (= n m)
        (suman n)
        (begin (sumam m)  
           (ciclo2 (- m 1) n)        
        )     
  )
)

(define (int n m)
  (display "Ingrese un número ")(newline)
  (set! n  (read))
  (display "Ingrese el segundo número ")(newline)
  (set! m  (read))
  (if (> n m)
      (ciclo1 m n)
      (ciclo2 m n)
  )
)
(int 1 2)
       